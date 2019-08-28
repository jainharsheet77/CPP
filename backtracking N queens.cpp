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

void printSol(int board[N][N])
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
            cout<<board[i][j];
        cout<<endl;
    }
}
bool isSafe(int board[N][N],int row,int col)
{
    int i,j;
    for(i=0;i<col;i++)
        if(board[row][i]==1)
            return false;
    for(i=row,j=col;i>=0&&j>=0;i--,j--)
        if(board[i][j]==1)
            return false;
    for(i=row,j=col;i<N&&j>=0;i++,j--)
        if(board[i][j]==1)
            return false;
    return true;
}
bool solveUtil(int board[N][N],int col)
{
    if(col>=N)
        return true;
    for(int i=0;i<N;i++)
    {
        if(isSafe(board,i,col))
        {
            board[i][col]=1;
            if(solveUtil(board,col+1)==1)
            return true;
            board[i][col]=0;
        }

    }
    return false;
}
void solve()
{
    int board[N][N] = { { 0, 0, 0, 0 }, 
                        { 0, 0, 0, 0 }, 
                        { 0, 0, 0, 0 }, 
                        { 0, 0, 0, 0 } }; 
    
    if(solveUtil(board,0)==1)
        printSol(board);
    else
        cout<<"No way to arrange";
    
}
int main()
{   
    ios
    int T=1;
    //cin>>T;
    while(T--)
    {
       
       
    }
}
