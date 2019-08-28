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

typedef set<int> si;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector < vector<int> >  vii; 

struct node
{
    int data;
    node(int data)
    {
        this->data=data;
        left=right=NULL;
    }
    node *left;
    node *right;
};

void preorder(node *root)
{
    if(root==NULL)  return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(node *root)
{
    if(root==NULL)  return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(node *root)
{
    if(root==NULL)  return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
int main()
{   
    ios
    int T=1;
    //cin>>T;
    while(T--)
    {
        struct node *root =new node(1);
        root->left=new node(2);
        root->right=new node(3);
        root->left->left=new node(4);
        root->left->right=new node(5);
        preorder(root);
        cout<<endl;
        inorder(root);
        cout<<endl;
        postorder(root);
        cout<<endl;
        stack <node *> s;
        node * curr=root;
        while(curr!=NULL||s.empty()==false)
        {
            while(curr!=NULL)
            {
                s.push(curr);
                curr=curr->left;
            }
            curr=s.top();
            cout<<curr->data<<" ";
            s.pop();
            curr=curr->right;

        }
        
        return 0;


    }
}