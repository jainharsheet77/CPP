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

void multiply(int f[2][2],int m[2][2])
{
    int x=f[0][0]*m[0][0]+f[0][1]*m[1][0];
    int y=f[0][0]*m[0][1]+f[0][1]*m[1][1];
    int z=f[1][0]*m[0][0]+f[1][1]*m[1][0];
    int w=f[1][0]*m[0][1]+f[1][1]*m[1][1];

    f[0][0]=x;
    f[0][1]=y;
    f[1][0]=z;
    f[1][1]=w;
    
}

void power(int f[2][2],int n)
{
    if(n==0||n==1)
        return ;
    int m[2][2]={ {1,1},{1,0}};
    power(f,n/2);
    multiply(f,f);
    if(n%2!=0) 
        multiply(f,m);

}

int fib(int n)
{
    int f[2][2]={ {1,1},{1,0}};
    if(n==0)
        return 0;
    power(f,n-1);
    return f[0][0];
}


// function to return fibbo by formula
int fibbo(int n)
{
    double phi=(sqrt(5)+1)/2;
    return (round(pow(phi,n)/sqrt(5)));

}

int main()
{   
    ios
    int T=1;
    //cin>>T;
    while(T--)
    {
        for(int n=1;n<=10;n++)
        cout<<fib(n)<<" "<<fibbo(n)<<endl;
              
    }
}
