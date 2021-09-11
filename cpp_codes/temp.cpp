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
    	makeset(7);
		makeset(6);
		unionize(7,6);
		makeset(5);
		makeset(8);
		unionize(7,5);
		for(auto i:maps)
			cout<<i.F<<" "<<i.S->parent->data<<endl;		



    }
}
