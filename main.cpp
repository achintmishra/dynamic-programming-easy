#include <iostream>
#include<string>
#include<vector>
#include<math.h>
using namespace std;

int fibohelper(int n,int *ans)
{
  if(n<=1)
  {
    return n;
  }
  if(ans[n]!=-1)
  {
    return ans[n];
  }
  int a =fibohelper(n-1, ans);
  int b =fibohelper(n-2, ans);
  ans[n]=a+b;
  return ans[n];
}
int fibo(int n)
{
  int *ans=new int[n+1];
  for(int i=0;i<=n;i++)
  {
    ans[i]=-1;
  }
  return fibohelper(n,ans);
}

int minsteps(int n)
{
  if(n<=1)
  {
    return 0;
  }
  int y=INT8_MAX;
  int z=INT8_MAX;
  int x=minsteps(n-1);
  if(n%2==0)
  {
    y=minsteps(n/2);
  }
  if(n%3==0)
  {
    z=minsteps(n/3);
  }
  int ans = min(x,min(y,z))+1;
  return ans;
}

int minstepshelper(int n,int *ans)
{
  if(n<=1)
  {
    return 0;
  }
  if(ans[n]!=-1)
  {
    return ans[n];
  }
  int x=minstepshelper(n-1,ans);
  int y=INT8_MAX;
  int z=INT8_MAX;
  if(n%2==0)
  {
    y=minstepshelper(n/2,ans);
  }
  if(n%3==0)
  {
    z=minstepshelper(n/3,ans);
  }
  int output = min(x,min(y,z))+1;
  ans[n]=output;
  return output;
}
int minsteps2(int n)
{
  int *ans=new int[n+1];
  for(int i=0;i<=n;i++)
  {
    ans[i]=-1;
  }
  return minstepshelper(n,ans);
}

int balancedtrees(int height)
{
  if(height<=1)
  {
    return 1;
  }
  int x=balancedtrees(height-1);
  int y=balancedtrees(height-2);
  int ans=(x*x) + 2*x*y;
  return ans;
}

int main()
{
  cout<<fibo(6)<<endl;
  cout<<minsteps2(10)<<endl;
  cout<<balancedtrees(4)<<endl;
}