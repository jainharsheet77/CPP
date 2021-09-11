 #include<bits/stdc++.h>
using namespace std;


const int n=12;
vector<int> adj[2*n];
vector<bool> vis(2*n,0);
vector<int> parent(2*n,-1);
vector<int> pre(2*n),post(2*n);
queue<int> q;
int ct=0;

void addedge(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
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

int main()
{ 
    
    
   { 
    addedge(1,2);
    addedge(1,5);
    addedge(5,9);
    addedge(5,10);
    addedge(9,10);
    addedge(6,6);
    addedge(3,4);
    addedge(3,7);
    addedge(3,8);
    addedge(4,8);
    addedge(7,8);
    addedge(7,11);
    addedge(11,8);
    addedge(8,12);
      
   }
   for(int i=1;i<=n;i++)
   {
       if(!vis[i])
       {
           dfs(i);
           ct++;
       }
   }
print();
   for(int i=1;i<=n;i++)
   cout<<pre[i]<<" "<<post[i]<<endl;


    
}  
