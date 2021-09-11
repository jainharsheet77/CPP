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
#define dp subset
typedef set<int> si;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector < vector<int> >  vii; 

bool ** dp;
void print(const vector<int> & v)
{
    for(int i=0; i<v.size() ; ++i )
    {
        cout<<v[i];
    }
    cout<<endl;
}



void printsubsetRec(int arr[],int i,int sum,vector<int>&p)
{
    if(i==0&&sum!=0&&dp[0][sum]==0)
    {
        p.push_back(arr[i]);
        print(p);
        return;
    }

    if(sum==0&&i==0)
    {
        print(p);
        return ;
    }
    if(dp[i-1][sum]==1)
    {
        vector<int> b=p;
        printsubsetRec(arr,i-1,sum,b);
    }
    if(sum>=arr[i]&&dp[i-1][sum-arr[i]])
    {
        p.push_back(arr[i]);
        printsubsetRec(arr,i-1,sum-arr[i],p);
    } 

}

void createdp(int arr[],int n,int sum)
{
    if( n==0 ||sum < 0 )
        return ;
    dp=new bool*[n];
    for( int i=0 ; i<n ; ++i )
    {
        dp[i]=new bool[sum + 1];
        dp[i][0]=true;
    }
    if(arr[0]<=sum )
        dp[0][arr[0]]=true;
    for(int i=1;i<n;++i)
    {
        for(int j=0;j<sum+1;++j)
        {
            dp[i][j]=( arr[i] <= j )? dp[i-1][j]||dp[i-1][j-arr[i]] : dp[i-1][j];

        }
    }
    if(dp[n-1][sum]==false)
    {
        cout<<"No subset";
        return ;
    }
    vector<int> p;
    printsubsetRec(arr, n-1 , sum , p);
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
        int set[n];
        for(int i=0;i<n;i++)
            cin>>set[i];
        int sum;
        cin>>sum;
        createdp(set,n,sum);
    }
}
