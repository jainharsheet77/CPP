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
const int N=8;

typedef set<int> si;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector < vector<int> >  vii; 


// a utility function to check if i and j are valid indexes for N*N chessboard
bool isSafe(int x,int y,int sol[N][N])
{
    return (x>=0&&x<N&&y>=0&&y<N&& sol[x][y]==-1);
}


int solveKTutil(int x,int y,int movei,int sol[N][N],int xmove[],int ymove[])
{
    int k,next_x,next_y;
    if(movei ==N*N)
        return true;
    for(int k=0;k<N;k++)
    {
        next_x=x+xmove[k];
        next_y=y+ymove[k];
        if(isSafe(next_x,next_y,sol))
        {
            sol[next_x][next_y]=movei;
            if(solveKTutil(next_x,next_y,movei+1,sol,xmove,ymove)==true)
                return true;
            else
            {
                sol[next_x][next_y]=-1;
            }
        }
    }
    return false;
}


// A utility function to print solutin of matrix
void printSol(int sol[N][N])
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout<<sol[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool solveKT()
{
    int sol[N][N];

    for(int x=0;x<N;x++)
    {
        for(int y=0;y<N;y++)
        {
            sol[x][y]=-1;
        }
    }



    int  xmove[]= {2,1,-1,-2,-2,-1,1,2}; 
    int  ymove[]= {  1, 2,  2,  1, -1, -2, -2, -1 }; 

    sol[0][0]= 0;

    if(solveKTutil(0,0,1,sol,xmove,ymove)==false)
    {
        cout<<"No solution";
        return false;
    }
    else
    {
        printSol(sol);
    }
}



int main()
{   
    ios
    int T=1;
    //cin>>T;
    while(T--)
    {
       solveKT();
       return 0;
       
    }
}
