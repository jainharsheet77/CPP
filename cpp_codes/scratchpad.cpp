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

// #define rsort(all(a)) sort(all(a),greater<int>()) 
typedef set<int> si;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector < vector<int> >  vii; 
 
 
ll fastpow(ll a, ll pw,int mod) 
{
    ll res = 1;
    a %= mod;
    while(pw > 0) {
        if(pw & 1) res = (res*a)%mod;
        a = (a*a)%mod;
        pw >>= 1;
    }
    return res;
}
 
// ll min(ll a,ll b)
// {
// 	if(a<=b)
// 		return a;
// 	else 
// 		return b;
// }
 
// ll max(ll a,ll b)
// {
// 	if(a>=b)
// 		return a;
// 	else
// 		return b;
// }
 
// ll mint(ll a, ll b ,ll c)
// {
// 	ll res=min(a,b);
// 	return min(res,c);
// }
 
// string tobin(int n)
//  {
//  	string ans="";
//  	while(n>0)
//  	{
//  		ans+=to_string(n%2);
//  		n/=2;
//  	}
//  	return ans;
//  }
 
 //void swap(char *a,char *b)
 //{
 //	char *t=a;
 //	a=b;
 //	b=t;
 
 //}
 
// ll ceil(ll a,ll b)
// {
 
// 	ll res=a/b;
// 	if(res*b!=a)
// 		res++;
 
// 	return res;
// }
//  bool divi(string s,int b)
//  {
//  		ll num=0;
//  		int i=0;
//  		int n=s.size();
// 		while(i<n)
// 		{
// 			num=num%b;
// 			num=num*10+(s[i]-'0');
// 			i++;

// 		}
// 		if(num%b==0)
// 			return 1;
// 		else
// 			return 0;
		
//  }
 

int main()
{   
    ios
    int T=1;
    cin>>T;
    
    while(T--)
    {
    	int n,m,k;
        cin>>n>>m>>k;
        ll x,y;
        cin>>x>>y;
        vector<pair<ll,ll>> a(n),b(m),c(k);
        for(int i=0;i<n;i++)
        {
            ll p,q;
            cin>>p>>q;
            a[i]={p,q};
        }
        for(int i=0;i<m;i++)
        {
            ll p,q;
            cin>>p>>q;
            b[i]={p,q};
        }
        for(int i=0;i<k;i++)
        {
            ll p,q;
            cin>>p>>q;
            c[i]={p,q};
        }
        ll mind=10000000000000000,x1,x2,y1,y2;
        map<int,int > minab,minba,minbc,mincb;

        ll dfromst=(a[0].F-x)*(a[0].F-x)+(a[0].S-y)*(a[0].S-y);
        int minst;
        for(int i=0;i<n;i++)
        {
            if(dfromst>(a[i].F-x)*(a[i].F-x)+(a[i].S-y)*(a[i].S-y))
            {
                dfromst=(a[i].F-x)*(a[i].F-x)+(a[i].S-y)*(a[i].S-y);
                minst=i;
            }
            mind=(a[i].F-b[0].F)*(a[i].F-b[0].F)+(a[i].S-b[0].S)*(a[i].S-b[0].S);
            ll minj=0;
            for(int j=0;j<m;j++)
            {
                double d=(a[i].F-b[j].F)*(a[i].F-b[i].F)+(a[i].S-b[i].S)*(a[i].S-b[i].S);
                if(mind>d)
                {
                    mind=d;
                    // x2=b[j].F;
                    // y2=b[j].S;
                    minj=j;
                }
            }
            minab[i]=minj;
        }


        
        for(int i=0;i<m;i++)
        {
            
            mind=(b[i].F-c[0].F)*(b[i].F-c[0].F)+(b[i].S-c[0].S)*(b[i].S-c[0].S);
            ll minj=0;
            for(int j=0;j<k;j++)
            {
                double d=(b[i].F-c[j].F)*(b[i].F-c[i].F)+(b[i].S-c[i].S)*(b[i].S-c[i].S);
                if(mind>d)
                {
                    mind=d;
                    // x2=b[j].F;
                    // y2=b[j].S;
                    minj=j;
                }
            }
            minbc[i]=minj;
        }

        int xfst=a[minst].F;
        int yfst=a[minst].S;
        cout<<x<<" "<<y<<endl;
        cout<<xfst<<" "<<yfst<<endl;
        double d1=(x-xfst)*(x-xfst)+(y-yfst)*(y-yfst);
        d1=sqrt(d1);

        int xfab=b[minab[minst]].F;
        int yfab=b[minab[minst]].S;
        cout<<xfab<<" "<<yfab<<endl;
        d1+= sqrt( (xfab-xfst)*(xfab-xfst)+(yfab-yfst)*(yfab-yfst) );

        int xfbc=c[minbc[minab[minst]]].F;
        int yfbc=c[minbc[minab[minst]]].S;
        cout<<xfbc<<" "<<yfbc<<endl;
        d1+=sqrt( (xfab-xfbc)*(xfab-xfbc)+(yfab-yfbc)*(yfab-yfbc) );


        cout<<d1<<endl<<endl;
		

        ll d2=10000000000000000;
        for(int i=0;i<n;i++)
        {
            int j=minab[i];
            int k=minbc[j];
            ll temp=sqrt( (a[i].F-b[j].F)*(a[i].F-b[j].F)+(a[i].S-b[j].S)*(a[i].S-b[j].S) );
            temp+= sqrt(  (c[k].F-b[j].F)*(c[k].F-b[j].F)+(c[k].S-b[j].S)*(c[k].S-b[j].S) );
            if(temp<d2)
            {
                d2=temp;
                mini=i;
            }
        }

        d2+=sqrt( (a[i].F-x)*(a[i].F-x)+(a[i].S-y)*(a[i].S-y) );

        if(d2<d1)
            cout<<setprecision(15)<<d2<<endl;
        else
            cout<<setprecision(15)<<d1<<endl;







        


    }
}
