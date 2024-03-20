//
// Created by Thomas on 2024/3/19.
//
#include <iostream>

using namespace std;

int main()
{
  int n,m,k;
  scanf("%d%d%d",&m,&n,&k);
  if(k==-1&&(n+m)%2) printf("0");
  else printf("%d",1<<(n-1)*(m-1));
  return 0;
}
