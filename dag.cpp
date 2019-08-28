 #include<bits/stdc++.h>
using namespace std;
#define rep(i,n,m) for(int i=n;i<m;i++)
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define all(c) c.begin(), c.end()
#define desc_sort(v) sort(v.rbegin(),v.rend())

const int n=8;

vector<int> adj[2*n];
vector<bool> vis(2*n,0);
vector<int> parent(2*n,-1);
vector<int> pre(2*n),post(2*n);
queue<int> q;
int ct=0;
queue<int>zero;
vector<int> indegree(2*n,0);

void addedge(int u, int v)
{
    //adj[u].push_back(v);
    adj[v].push_back(u);
    sort(all(adj[v]));
}

void print()
{
    for(int i=1;i<=n;i++)
    {
        cout<<"adjacency list of vertex "<<i<<endl<<"->";
        for(auto j:adj[i])
        {
            cout<<j<<" ";
        }
cout<<endl;
    }
}
 

void dfs(int strt)
{
    vis[strt]=1;
    pre[strt]=ct;
    ct++;
    for(auto i:adj[strt])
    {
        if(!vis[i])
        {
            vis[i]=1;
            dfs(i);
            ct++;
        }
        post[strt]=ct;
        
    }
}

void topological()
{
    for(int i=1;i<=n;i++)
    {
        if(indegree[i]==0)
        {
            zero.push(i);
        }
    }
    while(!zero.empty())
    {
        int j=zero.front();
        cout<<j<<" -> ";
        zero.pop();
        for(auto i:adj[j])
        {
            indegree[i]--;
            if(indegree[i]==0)
            zero.push(i);
        }
        
    }

}
int main()
{ 
    
    
   { 
    addedge(1,3);
    addedge(3,6);
    addedge(6,7);
    addedge(7,8);
    
    addedge(2,8);
    addedge(2,3);
    addedge(1,4);
    addedge(1,5);
    addedge(4,6);
    addedge(4,8);
    
    addedge(5,8);
    
      
   }
   
print();

topological();

    
}  
