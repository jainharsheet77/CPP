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
 
#define print(v) for(auto i:v) cout<<i<<" "
#define printl(v) for(auto i:v) cout<<i<<endl
#define println(v) for(auto i:v) cout<<i<<" "; cout<<endl

typedef set<int> si;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector < vector<int> >  vii; 

int main()
{   
    ios
    int T=1;
    // cin>>T;
    
    while(T--)
    {
        int n;
        cin>>n;
        ll sum=0;
        ll a[n][n],b[n+2][n+2],c[n+2][n+2];
        rep(i,0,n) 
        {
        	rep(j,0,n) 
        		cin>>a[i][j],cout<<a[i][j];
        	cout<<endl;
        }

        rep(i,0,n+2)
        {
        	rep(j,0,n+2)    
        		b[i][j]=0;
        }
        rep(i,1,n+1)
        {
            rep(j,1,n+1)
            {
                b[j][i]=b[j+1][i-1]+a[j-1][i-1];
                
            }
          
        }
       
        rep(i,0,n+2)
        {
        	rep(j,0,n+2)
        		cout<<b[i][j]<<" " ;
        	cout<<endl;
        }
        vector<pair<ll,int>> row;
        rep(i,0,n+1)
        {
        	row.pb({b[1][i],i});
        }
        sort(all(row));
        int t=row.size();
        cout<<row[t-1].F<<" "<<row[t-2].F<<endl;
        cout<<row[t-1].S<<" "<<row[t-2].S<<endl;
        sum+=(row[t-1].F+row[t-2].F);
            
       
       
       rep(i,0,n+2)
        {
        	rep(j,0,n+2)    
        		c[i][j]=0;
        }
        rep(i,1,n+1)
        {
            rep(j,1,n+1)
            {
                c[i][j]=c[i-1][j-1]+a[i-1][j-1];
                
            }
          
        }
       
        rep(i,0,n+2)
        {
        	rep(j,0,n+2)
        		cout<<c[i][j]<<" " ;
        	cout<<endl;
        }
        vector<pair<ll,int>> col;
        rep(i,0,n+2)
        {
        	col.pb({c[n][i],i});
        }
        
        sort(all(col));
        int  p=col.size();
        cout<<col[p-1].F<<" "<<col[p-2].F<<endl;
        cout<<col[p-1].S<<" "<<col[p-2].S<<endl;
    	sum+=(col[p-1].F+col[p-2].F);
    	cout<<sum;
    	
    	pair<int,int> p1,p2;
    	p1={1,row[t-1].S};
    	p2={n,col[p-1].S};
    	// while(p1!=p2)
    	// {
    	// 	p1.F++;
    	// 	p1.S--;
    	// 	p2.F--;
    	// 	p2.S--;
    	// }
    	cout<<endl<<p1.F<<" " <<p1.S<<endl<<p2.F<<" "<<p2.S<<endl;
    	
        
        
    }
}
