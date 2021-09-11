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


string LCSuff(string x,string y)
{
    int m=x.size();
    int n=y.size();
    int lcs[m+1][n+1];
    int result=0;
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0||j==0)
            {
                lcs[i][j]=0;
            }
            else if(x[i-1]==y[j-1])
            {
                lcs[i][j]=lcs[i-1][j-1]+1;
                
            }
            else
                    lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
        }
    }
    string longest;
    int i=m,j=n;
    {
        while(i>0&&j>0)
        {
            if(x[i-1]==y[j-1])
            {
                longest+=x[i-1];
                i--;
                j--;
            }
            else if( lcs[i-1][j]> lcs[i][j-1])
            {
                i--;
            }
            else
            {
                j--;

            }
            
        }
    }
    reverse(longest.begin(),longest.end());
    return longest;
}

string LCSuff(string a,string b,string c)
{
    int n=a.size();
    int m=b.size();
    int o=c.size();
    int dp[n+1][m+1][o+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            for(int k=0;k<=o;k++)
            {
                if(i==0||j==0||k==0)
                    dp[i][j][k]=0;
                else if(a[i-1]==b[j-1]==c[k-1])
                {
                    dp[i][j][k]=dp[i-1][j-1][k-1];
                }
                else
                {
                    dp[i][j][k]=max(max( dp[i-1][j][k],dp[i][j-1][k]),dp[i][j][k-1]);
                }
            }
        }
    }
    return dp[n][m][o];
}

int main()
{   
    ios
    int T=1;
    //cin>>T;
    while(T--)
    {
        string a,b;
        cin>>a>>b;
        string ans=LCSuff(a,b);
        cout<<ans<<ans.size();
    }
}
