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
struct Edge
{
    int src,dest,weight;


};

struct Graph
{
    int V,E;
    struct Edge * edge;
};
Graph * creategraph(int v,int e)
{
    struct Graph* graph=new Graph;
    graph->V=v;
    graph->E=e;
    graph->edge=new Edge[e];
    return graph;

}

void print(int dist[],int n)
{
    for(int i=0;i<n;i++)
        cout<<dist[i]<<" ";
}


void bellmen_ford(Graph * graph,int src)
{
    int V=graph->V;
    int E=graph->E;
    int dist[V];

    for(int i=0;i<V;i++)
    {
        dist[i]=INT_MAX;
    }
    dist[src]=0;
    for(int i=1;i<=V-1;i++)
    {
        for(int j=0;j<E;j++)
        {
            int u=graph->edge[j].src;
            int v=graph->edge[j].dest;
            int w=graph->edge[j].weight;
            if(dist[u]!=INT_MAX && dist[u]+w <dist[v])
            {
                dist[v]=dist[u]+w;
            }
        }
    }
    for(int i=0;i<E;i++)
    {
        int u=graph->edge[i].src;
        int v=graph->edge[i].dest;
        int w=graph->edge[i].weight;
        if(dist[u]+w<dist[v])
        {
            cout<<"negative cycle present";
            return;
        }
    }
    print(dist,V);

}


int main()
{   
    ios
    int T=1;
    //cin>>T;
    while(T--)
    {
        int V,E;
        cin>>V>>E;
        int src=0;
        Graph* graph=creategraph(V,E);
        for(int i=0;i<E;i++)
        {
            int v,u,w;
            cin>>u>>v>>w;
            graph->edge[i].src=u;
            graph->edge[i].dest=v;
            graph->edge[i].weight=w;
        }
        bellmen_ford(graph,src);
    }
}
