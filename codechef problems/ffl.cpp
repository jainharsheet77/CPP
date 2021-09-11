//https://www.codechef.com/LTIME83B/problems/FFL
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
#define int long long
 
typedef long long ll;


void solve()
{
    int n,s;
    cin>>n>>s;
    vector<int> p(n);
    rep(i,0,n)
        cin>>p[i];

    vector<int> d,f;
    rep(i,0,n)
    {
        int t;
        cin>>t;
        if(t==0)
            d.pb(p[i]);
        else
            f.pb(p[i]);
    }
    sort(all(d));
    sort(all(f));
    if(f.size() && d.size() && s+d[0]+f[0]<=100)
        cout<<"yes";
    else
        cout<<"no";
  
    // return;
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
 
