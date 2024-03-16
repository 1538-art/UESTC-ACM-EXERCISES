/*
从标准输入设备读入三个整数a、b、c，找出中间数并输出。
 中间数定义为: 若三数不相等，则第2大的数是中间数；
 若有两个数相等，则最大数作为中间数。
 
Standard Input
第一行是T（T<=10），表明后面有T组测试数据，每组测试数据由三个整数构成，相邻两数之间有一个空格。

Standard Output
对应每一组测试数据，输出其中间数。

Samples
Input
8
45 23 85
12 56 12
34 23 34
12 12 12
234 567 890
876 458 321
456 456 777
2345 789 789
 Output
45
56
34
12
567
458
777
2345
 */
#include <algorithm>
#include <iostream>
using namespace std;
int main() {
  int T, nums[3];
  cin >> T;
  for (int i = 0; i < T; i++) {
    cin >> nums[0] >> nums[1] >> nums[2];
    sort(nums,nums+3);
    if (nums[0] != nums[1] && nums[0] != nums[2] &&
        nums[1] != nums[2]) {
      cout<<nums[1] << endl;
    } else {
      cout << nums[2] << endl;
    }
  }
}