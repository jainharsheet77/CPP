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

// void printing(int dp[][],int n,int w)
// {
//     vector<int> ans;
//     int curr=w;
//     int r=n;
//     for(int j=curr;j>=0;j--)
//     {
//         if(dp[r-1][j] != dp[r][j])
//         {
//             ans.push_back(vl[i-1]);
//             r=r-wt[i-1];
//         }
//         else
//         {
//             r--;
//         }
        
//     }
//     for(auto i:ans)
//     cout<<i<<" ";
//     cout<<endl;
    
// }

int knapsack(int val[],int wt[],int n,int w)
{
    int dp[n+1][w+1];
   
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=w;j++)
        {
            
            if(i==0||j==0)
                dp[i][j]=0;
            
            else if(wt[i-1]<=j)
            {
                
                dp[i][j]=max( (val[i-1] + dp[i-1][ j - wt[i-1] ] ), dp[i-1][j] );
                
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    // to print the values in the knap sack problem
    int j=w;
    int res=dp[n][w];
    for(int i=n;i>0&&res>0;i--)
    {
        if(res== dp[i-1][j])
            continue;
        else
        {
            cout<<val[i-1]<<" ";
            res=res-val[i-1];
            j=j-wt[i-1];
        }
    }
    cout<<endl;
    return dp[n][w];
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
        int val[n],wt[n];
        int w;
        cin>>w;
        
        for(int i=0;i<n;i++)
        {
            cin>>wt[i];
        }
        
        for(int i=0;i<n;i++)
        {
            cin>>val[i];
        }
        
        cout<<knapsack(val,wt,n,w)<<endl;
        

    }
}



/* python programm
def knapsack(w,wt, val ,n):
    dp=[[0 for i in range (w+1)] for j in range (n+1)]
    for i in range (n+1):
        for j in range (w+1):
            if i==0 or w==0:
                dp[i][j]=0
            elif wt[i-1]> j:
                dp[i][j]=dp[i-1][j]
            else:
                dp[i][j]=max( val[i-1] +dp[i-1][j - wt[i-1] ], dp[i-1][j])
                
    return dp[n][w]
    
val = [60, 100, 120] 
wt = [10, 20, 30] 
w = 50
n=len(val)

print(knapsack(w,wt,val,n))
*/