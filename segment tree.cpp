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

void buildtree(vector<int>& arr,vector<int>& tree,int start,int end,int node)
{
    if(start==end)          // if leaf node
    {    tree[node]=arr[start];
        return;
    }
    int mid=(start+end)/2;
    // recursively build left subtree and right subtree
    buildtree(arr,tree,start,mid,2*node);
    buildtree(arr,tree,mid+1,end,2*node+1);
    tree[node]=tree[2*node]+tree[2*node+1];
}
void update(vector<int>&arr,vector<int>&tree,int start,int end,int val,int idx,int node)
{
    if(start==end)          //if leaf
    {
        arr[idx]=val;
        tree[node]=val;
        return;
    }
    int mid=(start+end)/2;
    if(start<=idx&&mid>=idx)        // if idx is in the left subtree
        update(arr,tree,start,mid,val,idx,2*node);
    if(idx>mid&&idx<=end)           // if idx is in the right subtree
        update(arr,tree,mid+1,end,val,idx,2*node+1);
    tree[node]=tree[2*node]+tree[2*node+1];

}

int query(vector<int>&tree,int l,int r,int node,int start,int end)
{
    if(l<=start&&r>=end)        //total overlap so return value of the node
        return tree[node];
    if(l>end||r<start)          //no overlap so return 0 for sum and INT_MAX for minimum
        return 0;
    // partial overlap    
    int mid=(start+end)/2;      
    return query(tree,l,r,2*node,start,mid)+query(tree,l,r,2*node+1,mid+1,end);
}

void lazy_prop()
{
    
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
        vector<int> v(n);
        for(int i=0;i<n;i++)
            cin>>v[i];
        vector<int>tree(2*n+5);
        buildtree(v,tree,0,n-1,1);

        for(auto i:tree)
            cout<<i<<" ";
        cout<<endl;

        update(v,tree,0,9,1000,5,1);

        for(auto i:v)
            cout<<i<<" ";
        cout<<endl;
        cout<<query(tree,4,8,1,0,9);
       
    }
}
