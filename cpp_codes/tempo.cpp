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


typedef set<int> si;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector < vector<int> >  vii; 


int main()
{   
    ios
    int T=1;
    //cin>>T;
    while(T--)
    {
       int n,p;
       cin>>n>>p;
       string s;
       cin>>s;
       int flag=1;
       for(int i=0;i<p;i++)
       {
           string a;
           a+=s[i];
           for(int j=p+i;j<n;j+=p)
           {
               a+=s[j];
           }
           int l=a.size();
           int y;
           if(l>1)
           {
               for(int j=0;j<l;j++)
               {
                   if(a[j]=='.')
                   {
                       if(a.find('1'))
                        s[j]='0';
                        else
                        s[j]='1';
                        flag=0;
                        y=j;
                        break;
                   }
               }
           }
           if(flag==0)
           {
               for(int j=0;j<n;j++)
               {
                   if(s[j]=='.'&&j!=y)
                    s[j]='0';
               }
               break;
           }
       }
       if(flag==0)
       {
           
           cout<<s;
       }
       else
       cout<<"NO";
       
        
    }
}