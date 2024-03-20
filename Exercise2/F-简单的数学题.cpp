/*
这是一道简单的数学题，简单到题目只给你一个正整数N，而你则输出一个M，
 这个M是由N的各个位数重新排列而来的（比如，N=123，则M可以为123,213,321,312,132,231）。
 由于M有许多许多，所以要求你输出一个满足|N-M| % 9 =0 的最小M。

A % 9 = 0的含义为 A是9的倍数，比如9,18,0,9999等。

Standard Input
一个正整数N(1<N<10^1000 )，保证N的每一位都不是0。

注意:因为N实在太大请使用至少1001位的char数组保存而非int保存N

Standard Output
一个正整数M，如题目要求的那样。

Samples
Input	Output
91      19
 */
#include <bits/stdc++.h>

using namespace std;

void swapChar(char *p, char *q) {
  char temp;
  temp = *q;
  *q = *p;
  *p = temp;
}

void proSort(char c[]) {
  int len = strlen(c);
  int i, j;
  for (i = 0; i < len; i++)
    for (j = 0; j < len - i - 1; j++)
      if (c[j] > c[j + 1]) swapChar(&c[j], &c[j + 1]);
}

int main() {
  char c[1001] = {0};
  scanf("%s", c);
  proSort(c);
  cout << c;
  return 0;
}

