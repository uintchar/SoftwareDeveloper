# 数据结构与算法分析：C++语言分析

## 第1章 程序设计：综述

### 1.1 本书讨论的内容

### 1.2 数学知识复习

1. 指数
2. 对数
3. 级数（幂函数）
4. 模运算

### 1.3 递归简介

### 1.4 C++类

1. 基本的`class`语法
   - 访问权限说明符和封装：`private`, `protected`, `public`；

2. 构造函数的附加语法和访问函数：
   - 默认参数；
   - 初始化列表：当类中的数据成员为`const`时，或者为类且该类没有默认构造函数时，必须使用；
   - `explicit`构造函数：为了防止单参数的构造函数造成的隐式类型转换；
   - `const`成员函数：检查但是不改变其对象状态的成员函数，也称为访问函数；否则称为修改函数；

3. 接口与实现的分离
   - 预处理命令：头文件中的`ifndef`命令防止头文件的重复包含；
   - 作用域解析运算符`::`：`cpp`源文件中的成员函数必须与其所在的类关联；
   - 特征必须完全匹配：一个被实现的成员函数的特征(signature)必须完全匹配在类接口中列出的特征（成员函数的`const`在实现中不能省略，默认参数可省略）；
   - 对象的声明等同于基本类型；

4. `vector`和`string`类
   - C++11给列表（花括号）初始化更高的优先权：`vector<int> a = { 12 }`；

    ```cpp {class=line-numbers}
    // IntCell.h文件
    #ifndef IntCell_H
    #define IntCell_H

    class Intcell
    {// 一个模拟整数单元的类
    public:
      explicit IntCell(int initialValue = 0);
      int read() const;
      void write(int x);
    private
      int storedvalue;
    };

    #endif

    // IntCell.cpp文件
    #include "IntCell.h"
    IntCell::Intcell(int initialValue) storedvalue{ initialValue }
    { }

    int IntCell::read() const
    {
      return storedValue;
    }

    void IntCell::write(int x)
    {
      storedValue = x;
    }
    ```

### 1.5 C++细节

1. 指针
   - `new`和`delete`；

2. 左值、右值和引用：
   - 一个左值(lvalue)是一个标识非临时性对象的表达式；一个右值(rvalue)是一个标识临时性对象的表达式，或者是一个不与任何对象相联系的值(如字面值常数)；
   - 左值引用`&`：
     - 给结构复杂的名称起别名；
     - 范围`for`循环；
     - 避免拷贝；
   - 右值引用`&&`：
     - 可以延长右值的声明周期（引用计数为0？？？）；
     - 用于支持C++11的移动语义（移动赋值运算符、移动构造函数）；
     - 完美转发？？？

3. 参数传递：值传递、引用传递（左值引用、常量左值引用传递、右值引用）

4. 返回值传递：值返回、引用返回（左值引用、常量左值引用、右值引用）

5. `std::swap`和`std::move`
   - 在C++11中，如果赋值运算符的右边(或构造函数)是一个右值，那么当对象支持移动操作时能够自动地避免复制；
   - 在C++11中，标准库在`<utility>`中提供函数`std::move`，`std::move`并不能移动任何东西，它唯一的功能是将一个左值强制转化为右值引用，继而可以通过右值引用使用该值，以用于移动语义，确切地说，它使一个值易于移动。从实现上讲，`std::move`基本等同于一个类型转换：`static_cast<T &&>(lvalue)`;

    ```cpp {class=line-numbers}
    void swap(vector<string> &x, vector<string> &y)
    {
      vector<string> tmp = static_cast<vector<string> &&>(x);
      x = static_cast<vector<string> &&>(y);
      y = static_cast<vector<string> &&>(tmp);
    }
    
    void swap(vector<string> &x, vector<string> &y)
    {
      vector<string> tmp = std::move(x);
      x = std::move(y);
      y = std::move(tmp);
    }
    ```

6. 五大函数（拷贝左值，移动右值）：
   - 拷贝构造函数
   - 移动构造函数
   - 拷贝赋值运算符
   - 移动赋值运算符
   - 析构函数

7. C风格数组和字符串

### 1.6 模板

1. 函数模板：
   - 函数模板在需要时可自动展开，每个新类型的展开都会产生附加的代码，当它发生在大的项目中的时候，就叫作代码膨胀(code bloat)；
   - 如果存在一个非模板函数和一个模板函数且都匹配，那么非模板有优先权；
   - 如果出现两个同等近似程度的匹配，那么代码非法并且编译程序将宣示二义性；

2. 类模板：
   - 因为当前模板的分离式编译在许多平台上都不是工作得很好。因此，在许多情形下，整个的类连同它的实现必须放在一个`.h`文件中，STL流行的实现方法遵循的就是这个策略。

3. 函数对象：把函数放入一个对象之内来传递它（定义一个只包含函数的类）；

### 1.7 使用矩阵

## 第2章 算法分析

### 2.1 数学基础

1. $\Omega$, $\omega$, $\Theta$, $O$, $\omicron$

### 2.2 模型

### 2.3 要分析的问题

### 2.4 运行时间计算

## 第3章 表、栈和队列

### 3.1 抽象数据类型

### 3.2 线性表ADT

1. 线性表的简单数组实现
   - 插入：时间复杂度取决于插入的位置，可能会带来元素的移动或者重新分配内存空间尾端插入：$O(1)$
   - 删除：时间复杂度取决于删除的位置，可能会带来元素的移动，尾端插入：$O(1)$
   - 查询：按下标查询：$O(1)$，按值查询：$O(N)$

2. 线性表的链表实现：
   - 单向链表（带头结点、不带头结点）；
   - 双向链表；

### 3.3 STL中的`vector`和`list`

1. 常用操作：
   - 插入：`push_back`, `push_front`, `insert`；
   - 删除：`pop_back`, `pop_front`, `erase`；
   - 查询：`back`, `front`, `at`, `[]`；

2. 迭代器`iterator`：
   - 获取迭代器：`begin()`, `end()`
   - 迭代器方法：
   - 需要迭代器的容器操作

### 3.4 `vector`的实现

```cpp {class=line-numbers}
#include <algorithm>
template <typename Object>
class Vector
{
private:
  int theSize:
  int theCapacity;
  Object *objects;

public:
  static const int SPARE_CAPACITY = 16;

  explicit Vector(int initSize=0) : theSize{ initSize }, 
  theCapacity{ initSize + SPARE_CAPACITY }
  {
    objects = new Object[theCapacity];
  }
  
  Vector(const Vector &rhs ) : theSize{ rhs.theSize }, 
  thecapacity{ rhs.theCapacity }, objects{ nullptr }
  {
    objects = new Object[theCapacity];
    for (int k = 0; k < theSize; ++k)
      objects[k]= rhs.objects[k]; I
  }
  
  Vector & operator=(const Vector &rhs)
  {
    if (this == &rhs)
      return *this;
    Vector tmp = rhs;
    std::swap(*this, tmp);
    return *this;
  }
  
  ~Vector()
  {
    delete [ ]objects;
  }

  Vector(Vector && rhs) : theSize{ rhs.theSize }, 
  thecapacity{ rhs.theCapacity }, objects{ rhs.objects }
  {
    rhs.objects = nullptr;
    rhs.theSize = 0
    rhs.theCapacity = 0;
  }

  Vector & operator=(Vector && rhs)
  {
    std::swap(theSize, rhs.theSize);
    std::swap(theCapacity, rhs.theCapacity);
    std::swap(objects, rhs.objects);
    return *this;
  }

  void resize(int newSize)
  {
    if(newSize > theCapacity)
      reserve(newSize * 2);
    theSize = newSize;
  }
  
  void reserve(int newCapacity)
  {
    if(newCapacity < theSize)
      return;
    Object *newArray = new Object[newCapacity];
    for (int k = 0; k < theSize; ++k)
      newArray[k] = std::move(objects[k]);
    
    theCapacity = newCapacity;
    std::swap(objects, newArray);
    delete []newarray;
  }

  Object & operator[](int index) { return objects[index]; }

  const Object & operator[](int index) const { return objects[index]; }

  bool empty() const{ return size() == 0; }
  
  int size() const { return theSize; }

  int capacity() const { return theCapacity; }
  
  void push_back(const Object &x)
  {
    if (theSize == theCapacity)
      reserve( 2 * thecapacity + 1);
    objects[thesize++] = x;
  }
  
  void push_back(Object && x)
  {
    if (theSize == theCapacity)
      reserve( 2 * theCapacity + 1);
    objects[theSize++] = std::move(x); //x本来就是右值引用，为什么还要std::move()
  }
  
  void pop_back() { --theSize; }

  const Object & back() const { return objects[theSize-1]; }
  
  using iterator = Object *;
  using const_iterator = const Object *;
  
  iterator begin() { return &objects[0]; }

  const_iterator begin() const { return &objects[0]; }
  
  iterator end() { return &objects[size() - 1]; }
  
  const_iterator end() const { return &objects[size() - 1]; }
}
```

### 3.5 `list`的实现

1. `struct`一般用来表示一种主要通过直接存取而不是通过方法来访问的其数据的类。

## 第4章 树

## 第5章 散列

## 第6章 优先队列（堆）

## 第7章 排序

## 第8章 不相交集类
