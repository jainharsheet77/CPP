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

typedef set<int> si;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector < vector<int> >  vii; 

int L_bitonic_subsequence(vector<int>& v)
{
    int n=v.size();
    vector<int>dp1(n),dp2(n),res(n);
    for(int i=0;i<n;i++)
    {
        dp1[i]=1;
        dp2[i]=1;
    }
    for(int i=1;i<n;i++) 
    {
        for(int j=0;j<i;j++)
        {
            if(v[i]>v[j])
            {
                dp1[i]=max(dp1[i],dp1[j]+1);
            }
        }
    }
    for(int i=n-2;i>=0;i--)
    {
        for(int j=n-1;j>i;j--)
        {
            if(v[i]>v[j])
            {
                dp2[i]=max(dp2[i],dp2[j]+1);
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        res[i]=dp1[i]+dp2[i]-1;
    }
    return *max_element(res.begin(),res.end());
}


int main()
{   
    ios
    int T=1;
    //cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
        }
        cout<<L_bitonic_subsequence(v);
    }
}
