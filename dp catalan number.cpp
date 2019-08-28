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

ll cata(int n)
{
    if(n<=1)
        return 1;
    vector< ll> catalan(n+1);
    catalan[0]=catalan[1]=1;

    for(int i=2;i<=n;i++)
    {
        catalan[i]=0;
        for(int j=0;j<i;j++)
            catalan[i]+=catalan[j]*catalan[i-j-1];

    }
    return catalan[n];
}


int main()
{   
    ios
    int T=1;
    //cin>>T;
    while(T--)
    {
        for(int n=0;n<=10;n++)
        cout<<cata(n)<<" ";
              
    }
}