/* 
Author : H77
*/
#include<bits/stdc++.h>
using namespace std;
 
 
#define rep(i,n,m) for(int i=n;i<m;i++)
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define all(c) c.begin(), c.end()
#define desc_sort(v) sort(v.rbegin(),v.rend())
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define M 1000000007 
#define pushll(head,d) push_into_linkedlist(&head,d)
#define popll(head) dp_delete_first(&head)
#define eol cout<<"\n"
#define N 1000000

typedef long long ll;
typedef long double ld;

const ld PI = 3.141592653589793;
// #define int long long
 

// #ifdef _DEBUG
// //  freopen("input.txt", "r", stdin);
// //	freopen("output.txt", "w", stdout);
// #endif


void solve()
{
  int n,k;
  cin>>n>>k;
  vector<int> v(n);
  rep(i,0,n)
  {
      cin>>v[i];
  }
  sort(all(v));
  int ans=-1;
  for(int i=0;i<n;i++)
  {
      if(k%v[i]==0)
      {
          ans=v[i];
      }
  }
  cout<<ans;
  return;

  
}

 
signed main()
{   
    ios
    int T=1;
    cin>>T;
  	while(T--)
    {      
		  solve();
      cout<<endl;
    }
}

 
