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
#define N 4

typedef set<int> si;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector < vector<int> >  vii; 

bool isSafe(int maze [N][N],int x,int y)
{
    return (x>=0&&x<N&&y>=0&&y<N&& maze[x][y]==1);
}

void printSolution(int sol[N][N]) 
{ 
    for (int i = 0; i < N; i++) 
    {

        for (int j = 0; j < N; j++) 
            cout<<sol[i][j]; 
        cout<<endl; 
    }
    
} 
bool solveUtil(int maze[N][N],int s,int e,int sol[N][N]) 
{
    if(s==N-1&&e==N-1)
    {
    sol[s][e]=1;
    return 1;
    }
    if(isSafe(maze,s,e))
    {
        sol[s][e]=1;
        if(solveUtil(maze,s+1,e,sol)==1)
            return 1;
        if(solveUtil(maze,s,e+1,sol)==1)
            return 1;
        sol[s][e]=0;
        return 0;
    }
    return 0;
}
void solveMaze(int maze[N][N])
{
    int sol[N][N]=
    {
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0}
    };
    if(solveUtil(maze,0,0,sol))
        printSolution(sol);
    else
    {
        cout<<"path not found";
    }    
}


int main()
{   
    ios
    int T=1;
    //cin>>T;
    while(T--)
    {
       int maze[N][N]=
       {
           {1,0,0,0},
           {1,1,0,1},
           {0,1,0,0},
           {1,1,1,1}
       };

       solveMaze(maze);

       
    }
}
