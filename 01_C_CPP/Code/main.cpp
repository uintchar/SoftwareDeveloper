#include <iostream>
#include <fstream>
#include <iterator>
#include <memory>

// 泛型算法
#include <algorithm>
#include <numeric>

// 顺序容器
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <array>

// 顺序适配器
#include <stack>
#include <queue>

// 关联容器
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

#include <cmath>

#include <stdio.h>

// #include "Solution.h"

#include "MySmartPtr.h"

using namespace std;

#define TRAING

int main()
{
#ifdef TRAING
  const std::string traingFilePath = "E:\\Job\\Markdown-Note\\Code\\trainData1.txt";
  std::freopen(traingFilePath.c_str(), "r", stdin);
#endif

  // string s;
  // getline(cin, s);

  // MyUniquePtr<int> p1(new int(1));
  // MyUniquePtr<int> p0(std::move(p1));

  // int *q1 = p1.release();
  // shared_ptr<int> p;
  // int count = p.use_count();

  int x = -10;
  cout << ((x ^ 0x00000000) == x) << endl;
  cout << ((x ^ 0xFFFFFFFF) == ~x) << endl;

  cout << "end" << endl;

  return 0;
}

