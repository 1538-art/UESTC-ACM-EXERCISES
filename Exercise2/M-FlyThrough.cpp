//
// Created by Thomas on 2024/3/19.
//
#include <bits/stdc++.h>

using namespace std;

#define N 100001
int a[N];

int main()
{
  int n,m,t,i;
  memset(a,0,sizeof(a));
  scanf("%d%d",&n,&m);
  for(i=0;i<n;i++)
  {
    scanf("%d",&t);
    a[t]++;
  }
  for(i=N-2;i>=1;i--)
  {
    a[i]+=a[i+1];
  }
  while(m--)
  {
    scanf("%d",&t);
    printf("%d\n",a[t]);
  }
  return 0;
}
