#include<bits/stdc++.h>
using namespace std;

int solve(int arr[],int n,int s)
{
    map<int,int> maps;
    for(int i=0;i<n;i++)
    {
      maps[arr[i]]++;
    }    
    for(int i=0;i<n;i++)
    {
      if(arr[i]!=s-arr[i])
      {
        if(maps[s-arr[i]])
          return 1;
      }
      else{
        if(maps[s-arr[i]]>1)
        {
          return 1;
        }
      }
    }
    return 0;

}

 
signed main()
{   
  int n,s;
  cin>>n>>s;
  int arr[n];
  for(int i=0;i<n;i++)
    cin>>arr[i];
  cout<<solve(arr,n,s);
}

