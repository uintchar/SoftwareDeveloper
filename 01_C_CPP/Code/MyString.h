#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>

class MyString
{
public:
  /* 定义类型成员 */
  // typedef unsigned int size_type;
  using size_type = unsigned long long;

  /* 构造和析构函数 */
  MyString() = default; //默认构造函数
  MyString(const char *c_str); //c风格字符串构造函数，不加explicit会产生隐式类型转换
  MyString(const MyString &str); //拷贝构造函数，深拷贝
  MyString(MyString &&str); //移动构造函数
  MyString(const std::string &str); //标准字符串类构造函数
  MyString(const char *c_str, size_type n);
  MyString(MyString &str, size_type pos);
  MyString(MyString &str, size_type pos, size_type n);


  ~MyString() = default;

  /* 重载运算符 */
  // MyString &operator=(const char *c_str);
  // MyString &operator=(const MyString &str); //拷贝赋值运算符，深拷贝，拷贝前释放自己已分配的内存
  // MyString &operator=(MyString &&str); //移动赋值运算符
  /* 
  输入和输出运算符
  算术和关系运算符
  赋值运算符
  下标运算符
  递增和递减运算符
  成员访问运算符
  函数调用运算符
  重载、类型转换与运算符 
  */
  
  /* 成员函数 */
  size_type size() const {return len;} //隐式内联

  /* 友元函数 */
  friend void print_mystr(const MyString &str);

private:
  // mutable size_t access_ctr = 0; //可变数据成员，const成员函数也能对其进行修改
  char *c_str = nullptr;
  size_type len = 0;

};

/* 友元函数 */
void print_mystr(const MyString &str);


#endif