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
// floyd warshall is O( v^3)
// solving all pair shortest path problem
int ** graph,** sol;
void floyd_warshal(int n)
{
    sol=new int*[n];
    for(int i=0;i<n;i++)
    {
        sol[i]=new int[n];
        for(int j=0;j<n;j++)
        {
            sol[i][j]=graph[i][j];
        }
    }
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(sol[i][j]>sol[i][k]+sol[k][j])
                {
                    sol[i][j]=sol[i][k]+sol[k][j];
                }
            }
        }
    }
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
        graph=new int*[n];
        for(int i=0;i<n;i++)
        {
            
            graph[i]=new int[n];
            for(int j=0;j<n;j++)
            {
                
                int t;
                cin>>t;
                graph[i][j]=t;
            }
        }

        floyd_warshal(n);

    }
}
