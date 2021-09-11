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
#define int long long
 
typedef long long ll;

int n,m,a,b,c,d,p,q,r;
vector<ll> v;
ll zero=0,one=0,two=0;
string s,u;




// ll fastpow(ll a, ll pw) 
// {
//     ll res = 1;
//     a %= mod;
//     while(pw > 0) {
//         if(pw & 1) res = (res*a)%mod;
//         a = (a*a)%mod;
//         pw >>= 1;
//     }
//     return res;
// }

// ll min(ll a,ll b)
// {
// 	if(a<=b)
// 		return a;
// 	else 
// 		return b;
// }

 
// ll max(ll a,ll b)
// {
// 	if(a>=b)
// 		return a;
// 	else
// 		return b;
// }

//  bool divi(string s,int b)
//  {
//     ll num=0;
//     int i=0;
//     int n=s.size();
//     while(i<n)
//     {
//         num=num%b;
//         num=num*10+(s[i]-'0');
//         i++;

//     }
//     if(num%b==0)
//         return 1;
//     else
//         return 0;
		
//  }
 
void input()
{
	// cin>>a>>b;
	v.clear();
	// zero=0;
	// one=0;
	// two=0;
	cin>>n;
	rep(i,0,2*n)
	{
		ll t;
		cin>>t;
		v.pb(t);
	}
}


ll solve()
{
	ll ans=0;
	
	
	
	return ans;
	
}


signed main()
{   
    ios
    int T=1;
    cin>>T;
    while(T--)
    {
		input();
		cout<<solve()<<endl;
    }
}