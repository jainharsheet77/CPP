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


int LCSuff(string x,string y)
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
                result=max(result,lcs[i][j]);
            }
            else
                    lcs[i][j]=0;
        }
    }
    return result;
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
        cout<<LCSuff(a,b);
    }
}
