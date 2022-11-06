#ifndef MYSMARTPTR_H
#define MYSMARTPTR_H

// auto_ptr的核心在于拷贝和赋值时所有权的转移
// 通过方法release释放所有权，方法swap交换所有权
// 需要在类中重载与指针操作相关的运算符：*, ->, bool
template <typename T>
class MyAutoPtr
{
public:
  // 1. 构造和析构
  explicit MyAutoPtr(T *_ptr = nullptr) : ptr(_ptr) {}

  ~MyAutoPtr() { delete ptr; }

  // 2. 拷贝和赋值
  MyAutoPtr(MyAutoPtr &other) { ptr = other.release(); }

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
void swap(auto_ptr<T> &lhs, auto_ptr<T> &rhs) { lhs.swap(rhs); }

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

  void swap(MyAutoPtr &rhs)
  {
    using std::swap;
    swap(ptr, rhs.ptr);
  }

private:
  T *ptr;
};

template <typename T>
void swap(unique_ptr<T> &lhs, unique_ptr<T> &rhs) { lhs.swap(rhs); }

template <typename T>
class MySharedPtr
{
};

template <typename T>
class MyWeakPtr
{
};

#endif
