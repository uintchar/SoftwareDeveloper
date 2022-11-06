#include <iostream>

#include "MyString.h"

/* 构造和析构函数 */
MyString::MyString(const char *c_str)
{
  //统计c风格字符串长度；
  //为字符串分配存储空间；
  //to do
}


MyString::MyString(const MyString &str)
{

}


MyString::MyString(const std::string &str)
{

}

//拷贝赋值运算符，深拷贝，拷贝前释放自己已分配的内存
// MyString &MyString::operator=(const MyString &str)
// {
//   //先将底层数据拷贝到临时对象，为了防止自身给自身赋值
//   //在销毁原对象底层数据
//   //将临时对象拷贝给原对象的底层数据

//   //先判断是不是自己给自己赋值，如果是，则直接返回自身。
//   return *this;
// }


/* 友元函数 */
void print_mystr(const MyString &str)
{
  if (!str.c_str)
  {
    std::cout << "Null String\n";
    return;
  }
  std::cout << str.c_str << std::endl;
}