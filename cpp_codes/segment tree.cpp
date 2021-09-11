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
int n;
int tree[2*n];   // the segment tree array representaion.
int A[n];       // array of integers

// recurssive method
void build_tree(int node,int start,int end)
{
    if(start==end)  //  if the node is a leaf
    {
        tree[node]=A[start];  
    }
    else
    {
        int mid=(start+end)/2;
        build_tree(2*node,start,mid);
        build_tree(2*node,mid+1,end);
        tree[node]=tree[2*node]+tree[2*node+1];   // left child is at 2n and right child is at 2n+1 position in the arra
    }
}


void update(int node,int start,int end,int ind,int val)
{
    if(start==end)
    {
        A[ind]=val;
        tree[node]=val;
    }
    else
    {
        int mid=(start+end)/2;
        if(start<=ind && ind<=mid)  // if ind is the left child
        {
            update(2*node,start,mid,ind,val);
        }
        else        // if ind is the right child
        {
            update(2*node+1,mid+1,end,ind,val);
        }
        tree[node]=tree[2*node]+tree[2*node+1];
    }

}


int query(int node,int start,int end,int l,int r)
{
    if(r<start || end< l)       // the range is compeletly outside the node representation
    {
        return 0;
    }
    if(l<=start && end<= r)     // node is compeletly inside the given range
    {
        return tree[node];
    }
    

    // now only partial overlap remains
    int mid=(start+end)/2;
    int p1=query(2*node,start,mid,l,r);
    int p2=query(2*node+1,mid+1,end,l,r);

    return p1+p2;
}


// Iterative method
int n;
vector<int> segtree(2*n+1);
vector<int> a(n);
void build_segment_tree( vector<int> &a)
{
    for(int i=0;i<n;i++)    //value of leaves equal to aray elements 
    {
        segtree[n+i]=a[i];
    }

    for(int i=n-1;i>0;i--)    // value of internal nodes equal to sum of child nodes
    {
        segtree[i]=segtree[2*i]+segtree[2*i+1];
    }

}

void update_segment_tree(int ind,int val)
{
    tree[ind+n]=val;
    a[ind]=val;
    ind+=n;
    
    for(int i=ind;i>1;i>>=1)   // move upward and build the tree
    {
        tree[i>>1]=tree[i]+tree[i^1];   // tree[i/2]=tree[i]+tree[i+1];
    }

}


int query(int l,int r)
{
    int res=0;
    // loop to find the sum in the range

    for(l+=n,r+=n; l<r ; l>>=1,r>>=1)
    {
        if(l&1)
        {
            res+=tree[l++];
        }
        if(r&1)
        {
            res+=tree[--r];
        }
    }
    return res;
}

int main()
{   
    
}