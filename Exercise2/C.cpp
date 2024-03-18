/*
allenlowesy突然从Marswind那里得知，光纤技术要结课了，期末考试内容是一篇论文。
 allenlowesy以为可以不动脑筋地水过去，但是那位他从来没有见过的老师却规定，
 论文字数不得少于2000字，更要命的是，参考文献必须是IEEE或者CSA的论文。

众所周知，IEEE上有很多很多很多很多论文。当allenlowesy打开IEEE的搜索界面寻找关键词为fiber的论文时，
 系统返回给他一大堆结果。allenlowesy纠结了，他不可能把所有的论文都看了来确定是否有用。
 于是他假设，如果论文的标题中有一个单词是关键词（大小写也要一致），那么这篇论文是有用的。
现在allenlowesy需要从搜索结果中找到这些他认为有用的论文，那么这些论文有多少呢？

Standard Input
含多组测试数据，输入首先是一个整数T表示测试数据组数(≤T≤20)。

每组数据开始为一个整数N(≤N≤100),表示检索到的论文数

接下来1行是allenlowesy搜索的关键词，长度不超过20，只包括小写字母和大写字母。

接下来N行，每一行是一个论文的标题，长度不超过100，只包括小写字母、大写字母和空格

Standard Output
每组数据输出一个整数M，表示allenlowesy认为有用的论文数。
如果没有一篇论文的标题包含有关键词，则输出Do not find。

在每组输出结果后再输出一个空行。

Samples
    Input
3
2
fiber
optical fiber
optical Fiber
3
Sensors
Optical Fiber Sensing in Mechanical Measurement
A New Approach to Build AdvancedSensors
Comparison to different Sensors
2
xmm
lcy
silentsky
 	Output
1

1

Do not find
 */
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
  int T;
  cin >> T;
  cin.ignore();
  while (T--) {
    int N;
    cin >> N;
    cin.ignore();
    string keyword;
    getline(cin, keyword);
    int count = 0;
    for (int i = 0; i < N; i++) {
      string title;
      getline(cin, title);
      stringstream ss(title);
      string word;
      while (ss >> word) {
        if (word == keyword) {
          count++;
          break;
        }
      }
    }
    if (count == 0) {
      cout << "Do not find" << endl;
    } else {
      cout << count << endl;
    }
    if (T > 0) {
      cout << endl;
    }
  }
  return 0;
}

