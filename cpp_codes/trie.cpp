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

struct TrieNode
{
    map<char,TrieNode*> children;
    bool isend;
};

// creates a new node
TrieNode* newnode()
{
    TrieNode* pnode= new TrieNode;
    pnode->isend=false;
    return pnode;
}

void insert( TrieNode* root, string key)
{
    TrieNode* pcrawl= root;

    for(int i=0;i<key.size();i++)
    {
        if(!pcrawl->children[key[i]])
        {
            pcrawl->children[key[i]]=newnode();

        }
        pcrawl=pcrawl->children[key[i]];
    }
    pcrawl->isend=true;
}

bool search(TrieNode* root,string key)
{
    TrieNode* pcrawl=root;
    for(int i=0;i<key.size();i++)
    {
        if(pcrawl->children[key[i]]==0)
            return false;
        pcrawl=pcrawl->children[key[i]];
    }
    return (pcrawl!=NULL&&pcrawl->isend);
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
        TrieNode* root=newnode();
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>s;
            insert(root,s);

        }
        cout<<search(root,"klm");
       
    }
}