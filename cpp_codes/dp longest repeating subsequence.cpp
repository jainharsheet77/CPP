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

string L_repeating_subq(string s)
{
    int n=s.size();
    int dp[n+1][n+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
            dp[i][j]=0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(s[i-1]==s[j-1]&&i!=j)
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    
    string res="";
    int i=n;
    int j=n;
    while(i>0&&j>0)
    {
        if(dp[i][j] == dp[i-1][j-1] + 1)
        {
            res+=s[i-1];
            i--;
            j--;
            
        }
        else if(dp[i][j] == dp[i-1][j])
            i--;
        else 
            j--;
    }
    reverse(res.begin(),res.end());
    return res;
}

int main()
{   
    ios
    int T=1;
    //cin>>T;
    while(T--)
    {
        string s;
        cin>>s;
        cout<<L_repeating_subq(s);
    }
}
