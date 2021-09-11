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

string lcs( string s,string rev)
{
    int n=s.size();
    int m=rev.size();
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0||j==0)
            {
                dp[i][j]=0;
            }
            else if(s[i-1]==rev[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else
            {
                dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
            }

        }
    }

    string ans="";
    int i=n,j=m;
    while(i>0&&j>0)
    {
        if(s[i-1]==rev[j-1])
        {
            ans+=s[i-1];
            i--;
            j--;
        }
        else if(dp[i-1][j]>dp[i][j-1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    return ans;
}


string L_P_subsequence( string s)
{
    // without lcs
    int n=s.size();
    int dp[n][n];
    for(int i=0;i<n;i++)
    {
        dp[i][i]=1;
    }
    for(int l=2;l<=n;l++)
    {
        for(int i=0;i<n-l+1;i++)
        {
            int j=i+l-1;
            if(l==2&&s[i]==s[j])
            {
                dp[i][j]=2;
            }
            else if(s[i]==s[j])
            {
                dp[i][j]=dp[i+1][j-1]+2;
            }
            else
            {
                dp[i][j]=max(dp[i][j-1],dp[i+1][j]);
            }
        }
    }
    
    
    
    /// using longest common subsequance
    string rev=s;
    reverse(rev.begin(),rev.end());
    string ans=lcs(s,rev);
    return ans;



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
        cout<<L_P_subsequence(s);
    }
}
