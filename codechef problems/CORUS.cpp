// https://www.codechef.com/MAY20B/problems/COVID19
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
#define hell INT_MIN;
#define heaven INT_MAX;
typedef long long ll;


void solve()
{
    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    map<char,int>cnt;
    int ct=0;
    for(int i=0;i<n;i++)
    {
        if(cnt[s[i]]==0)
            ct++;
        cnt[s[i]]++;
    }
    // for(auto i:cnt)
    //     cout<<i.F<<" "<<i.S<<endl;
    // cout<<ct<<endl;
    while(q--)
    {
        int c;
        cin>>c;
        int more=0;
        // cout<<c<<" ";
        for(auto i:cnt)
            if(i.S>c)
                more+=(i.S-c);
        cout<<more<<endl;
    }

}

 
signed main()
{   
    ios
    int T=1;
    cin>>T;
  	while(T--)
    {      
        // cout<<endl;
		solve();
        
    }
    
}  
