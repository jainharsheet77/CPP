#include<bits/stdc++.h>
using namespace std;


const int n=11;
vector<int> adj[n];
vector<bool> vis(n,0);
vector<int> parent(n,-1);
queue<int> q;

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

void bfs(int str,int dest)
{

    vis[str]=1;
    int j;
    q.push(str);
    while(!q.empty())
    {
        j=q.front();
        q.pop();
        for(auto i:adj[j])
        {
            if(vis[i]==0) 
            {
                vis[i]=1;
                q.push(i);
                parent[i]=j;
            }
        }
    
    }
    int g=parent.size();
    int i=dest;
     while(i!=str)
     {
        
         if(parent[i]!=-1)
         {
             cout<<i<<" , ";
             i=parent[i];
         }
         else 
         {
             cout<<"no path";
             break;
         }
     }
     cout<<str;
    
}
int main()
{ 
    
    
   { 
    addedge(1,2);
    addedge(1,3);
    addedge(1,4);
    addedge(2,3);
    addedge(4,5);
    addedge(4,8);
    addedge(5,6);
    addedge(5,7);
    addedge(6,8);
    addedge(6,9);
    addedge(6,7);
    addedge(8,9);
    //addedge(9,10);
    
   }
   print();
   
   bfs(1,10);
    
}
