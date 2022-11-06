#ifndef MYSMARTPTR_H
#define MYSMARTPTR_H

// auto_ptr的核心在于拷贝和赋值时所有权的转移
// 通过方法release释放所有权，方法swap交换所有权
// 需要在类中重载与指针操作相关的运算符：*, ->, bool
// 当需要做到子类指针向基类指针的隐式指针时，需要在类中添加模板成员
template <typename T>
class MyAutoPtr
{
public:
  // 1. 构造和析构
  explicit MyAutoPtr(T *_ptr = nullptr) : ptr(_ptr) {}

  ~MyAutoPtr() { delete ptr; }

  // 2. 拷贝和赋值
  MyAutoPtr(MyAutoPtr &other) { ptr = other.release(); }

  template <typename U>
  MyAutoPtr(MyAutoPtr<U> &other) { ptr = other.release(); }

  MyAutoPtr &operator=(MyAutoPtr &rhs)
  {
    // 通过copy-swap技术完成了避免自我赋值与保证了强异常安全
    // 通过临时对象在析构函数中释放原来的资源
    MyAutoPtr(rhs.release()).swap(*this);
    return *this;
  }

  // 3. 重载指针相关运算符
  T &operator*() const { return *ptr; }

  T *operator->() const { return ptr; }

  operator bool() const { return ptr; }

  // 4. 相关方法
  T *get() const { return ptr; }

  T *release()
  {
    T *tmp = ptr;
    ptr = nullptr;
    return tmp;
  }

  void swap(MyAutoPtr &rhs)
  {
    using std::swap;
    swap(ptr, rhs.ptr);
  }

private:
  T *ptr;
};

template <typename T>
void swap(MyAutoPtr<T> &lhs, MyAutoPtr<T> &rhs) { lhs.swap(rhs); }

// unique_ptr的核心在于禁止拷贝和赋值，但是支持通过移动语义转移其所有权
// 通过方法release释放所有权，方法swap交换所有权
// 需要在类中重载与指针操作相关的运算符：*, ->, bool
template <typename T>
class MyUniquePtr
{
public:
  // 1. 构造和析构
  explicit MyUniquePtr(T *_ptr) : ptr(_ptr) {}

  ~MyUniquePtr() { delete ptr; }

  // 2. 移动语义
  MyUniquePtr(MyUniquePtr &&other) { ptr = other.release(); }

  MyUniquePtr &operator=(MyUniquePtr &&rhs)
  {
    // 不需要在函数体中构造临时对象
    rhs.swap(*this);
    return *this;
  }

  // 3. 重载和指针操作相关的运算符：*, ->, bool
  T &operator*() const { return *ptr; }

  T *operator->() const { return ptr; }

  operator bool() const { return ptr; }

  // 4. 相关方法
  T *get() const { return ptr; }

  T *release()
  {
    T *tmp = ptr;
    ptr = nullptr;
    return tmp;
  }

  void swap(MyUniquePtr &rhs)
  {
    using std::swap;
    swap(ptr, rhs.ptr);
  }

private:
  T *ptr;
};

template <typename T>
void swap(MyUniquePtr<T> &lhs, MyUniquePtr<T> &rhs) { lhs.swap(rhs); }


// shared_ptr的核心在于使用引用计数的机制来管理对象的释放
// 方法：use_count, get, swap
template <typename T>
class MySharedPtr
{
public:
  // 1. 构造和析构
  explicit MySharedPtr(T *_ptr = nullptr) : ptr(_ptr)
  {
    if (ptr)
      count = new int(1);
    else
      count = new int(0);
  }

  ~MySharedPtr()
  {
    if (ptr)
    {
      --(*count);
      if (count == 0)
      {
        delete count;
        delete ptr;
      }
    }
  }

  // 2. 拷贝和赋值
  MySharedPtr(const MySharedPtr &other)
  {
    ptr = other.ptr;
    count = other.count;
    if (ptr) ++(*count);
  }

  MySharedPtr &operator=(const MySharedPtr &rhs)
  {
    if (this != &rhs)
    {
      if (ptr)
      {
        --(*count);
        if (*count == 0)
        {
          delete ptr;
          delete count;
        }
      }

      ptr = rhs.ptr;
      count = rhs.count;
      if (ptr) ++(*count);
    }

    return *this;
  }

  // 3. 重载和指针操作相关的运算符
  T &operator*() const { return *ptr; }

  T *operator->() const { return ptr; }

  operator bool() const { return ptr; }


  // 4. 相关方法
  T *get() { return ptr; }

  int useCount()
  { 
    if (ptr)
      return *count;
    else 
      return 0; 
  }

  void swap(MySharedPtr &rhs)
  {
    using std::swap;
    swap(ptr, rhs.ptr);
    swap(count, rhs.count);
  }

private:
  int *count;
  T *ptr;
};

template <typename T>
void swap(MySharedPtr<T> &lhs, MySharedPtr<T> &rhs) { lhs.swap(rhs); }

template <typename T>
class MyWeakPtr
{
};

#endif
