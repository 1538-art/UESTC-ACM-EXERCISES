/*
Littlte_Pro像很多学生一样生活在清水河畔，同时周围也住着大量的driver朋友们，
 总共有 n个drivers和Little_Pro生活在清水河畔，所有的driver都被Little_Pro用特殊的魔法祝福过，
 所以这些driver只能是good driver 或者 bad driver 这2个对立事件中的一个。

Littlte_Pro 是一个聪明的小司机。有一天，他想让所以的 drivers朋友们排成一个队列。
 然而作为一个与众不同的小司机，他想让这些队列的good driver、baddriver交替出现，
 从而为我校交通事业做出了巨大的贡献。我们的 Little_Pro 同时也是一位大魔法师. 每一次施法，
 他可以在一瞬间交换2个driver的在队列中的位置, 或者改变driver叔叔的性质
 (把一个good driver 变成 bad driver 或者把一个bad driver 变成 good driver)，
 无论是无所畏惧的Zhong大司机title，还是三金在手的cx大司机，
 Littlte_Pro都可以用魔法瞬间把他们变成坏司机 (偷笑)，搞怪结束了再把他们又变回来。

虽然Little_Pro是一位无所不能的小司机，但还是请你帮忙找到最少的施法次数，
 从而使这些driver朋友们在队列中good driver、bad driver交替出现。

test 1即样例，如果出现本机通过样例，提交出现wrong answer on test 1的情况，
 请检查在gets或者scanf("%c")之前是否已经使用getchar()将上一行的空格吸收。

Standard Input
第一行输入一个 integer n (1<=n<=100,000) — 表示drivers的数量.

第二行输入一个包含n个元素的字符串, 其中包括字符’1’ 和字符 ‘0’，其中’1’ 代表 bad driver、 ‘0’ 代表 good driver.

Standard Output
输出一个 integer — Little_Pro 需要的最少的施法次数，从而使这些driver在队列中good driver、bad driver交替出现。

Samples
Input	Output
5       1
01100

5       2
11111

3       0
010
 */
#include<iostream>

using namespace std;

int main() {
  int n, ans1 = 0, ans2 = 0, ans3 = 0, ans4 = 0, ans_1, ans_2, ans;
  string s;
  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    if ((i + 1) % 2 == 0) {
      if (s[i] != '0') ans2++;
    } else {
      if (s[i] != '1') ans1++;
    }
  }
  ans_1 = max(ans1, ans2);
  
  for (int i = 0; i < n; i++) {
    if ((i + 1) % 2 == 0) {
      if (s[i] != '1') ans3++;
    } else {
      if (s[i] != '0') ans4++;
    }
  }
  ans_2 = max(ans3, ans4);
  
  cout << min(ans_1, ans_2);
  return 0;
}
