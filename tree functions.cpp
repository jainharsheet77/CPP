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
    
    node *left;
    node *right;
    node(int key)
    {
        data=key;
        left=right=NULL;
    }
};

node* newnode(int key)
{
    node* temp=newnode(key);
    temp->data=key;
    temp->left=temp->right=NULL;
    return temp;
}
//function to get height of tree
int height(node* node)
{
    if(node==NULL)
    return 0;
    else
    {
        int lheight=height(node->left);
        int rheight=height(node->right);
        if(lheight>rheight)
            return(lheight+1);
        else
            return(rheight+1);
    }

}
void preorder(node *root)
{
    if(root==NULL)  return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

//function to print preorder without reccurssion
void preorder_stack(node* root)
{
    stack<node*>s;
    s.push(root);
    while(!s.empty())
    {
        node* temp=s.top();
        s.pop();
        cout<<temp->data;
        if(temp->right)
        s.push(temp->right);
        if(temp->left)
        s.push(temp->left);
    }
}

void inorder(node *root)
{
    if(root==NULL)  return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

//function to print inorder without reccurssion
void inorder_stack(node* root)
{
    stack<node*>s;
    node* temp;
    while(temp!=NULL||s.empty()==0)
    {
        while(temp!=NULL)
        {
            s.push(temp);
            temp=temp->left;
        }
        temp=s.top();
        s.pop();
        cout<<temp->data;
        temp=temp->right;
    }
}
 

//function to traverse inorder without recursion and stack
// Morris traversal
void morrisTraversal(node* root)
{
    node* curr,*pre;
    if(root==NULL)
    return;
    curr=root;
    while(curr)
    {
        if(curr->left==NULL)
        {
            cout<<curr->data;
            curr=curr->right;
        }
        else
        {
            pre=curr->left;
            while(pre->right!=NULL&&pre->right!=curr)
            {
                pre=curr->left;
                if(pre->right==NULL)
                { 
                       pre->right=curr;
                       curr=curr->left;
                }
                else
                {
                    pre->right=NULL;
                    cout<<curr->data;
                    curr=curr->right;
                }

            }   
        }
    }
}

void postorder(node *root)
{
    if(root==NULL)  return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

//funtion to print post order without reccurssion and 2 stacks
void postorder_2stacks(node* root)
{
    stack<node*> s1,s2;
    s1.push(root);
    while(!s1.empty())
    {
        node* temp=s1.top();
        s2.push(temp);
        if(temp->left)
            s1.push(temp->left);
        if(temp->right)
            s1.push(temp->right);
    }
        while(!s2.empty())
        {
            cout<<s2.top()->data;
            s2.pop();
        }
}



//   function to print given level of tree 
//              O(n)
void print_given_level(node * tree,int level)
{
    if(tree==NULL)
    return;
    if(level ==1)
    {
        cout<<tree->data;
    }
    else
    {
        print_given_level(tree->left,level-1);
        print_given_level(tree->right,level-1);
    }
}

//   function to print level order of tree using two function
//             O(n^2)
void print_levelorder(node * tree)
{
    int h=height(tree);
    for(int i=1;i<=h;i++)
        print_given_level(tree,i);
}


//function for level order traversal of tree using queue
void print_levelorder_queue(node* root)
{
    if(root==NULL)
        return ;
    queue<node*>q;
    q.push(root);
    while(!q.empty())
    {
        node * node=q.front();
        cout<<node->data<<" ";
        q.pop();
        if(node->left!=NULL)
            q.push(node->left);
        if(node->right!=NULL)
            q.push(node->right);
    }
}

// function to insert inorder in a tree
void insert_inorder(node * root,int key)
{
    queue<node* > q;
    q.push(root);

    while(!q.empty())
    {
        node* node=q.front();
        q.pop();
        if(node->left==NULL)
        {
            node->left=newnode(key);
            break;
        }
        else
        {
            q.push(node->left);
        }
        if(node->right==NULL)
        {
            node->right=newnode(key);
            break;
        }
        else
        {
            q.push(node->right);
        }

    }
}
//function to delete a node of given pointer to node
void delete_given(node* root,node* d_node)
{
    node* temp=d_node;
    queue<node*>q;
    q.push(root);
    while(!q.empty())
    {
        node* t=q.front();
        q.pop();
        if(t->left!=NULL)
        {   
            q.push(t->left);
            if(t->left==temp)
            {
                t->left=NULL;
                delete(temp);
                break;
            }
        }
        if(t->right!=NULL)
        {   
            q.push(t->right);
            if(t->right==temp)
            {
                t->right=NULL;
                delete(temp);
                break;
            }
        }
    }

}



//function to delete a data from a binary tree and placing rightmost key at that place
void delete_in_tree(node* root,int key)
{
    if(root==NULL)
        return;
    queue<node*> q;
    q.push(root);
    node* temp,*keynode;
    while(!q.empty())
    {
        temp=q.front();
        q.pop();
        if(temp->left!=NULL)
            q.push(temp->left);
        if(temp->right!=NULL)
            q.push(temp->right);
        if(temp->data==key)
            keynode=temp;
    }
    if(keynode!=NULL)
    {
        int x=temp->data;
        delete_given(root,temp);
        keynode->data=x;
    }

}



//function to calculate size of tree(number of nodes)
//   recursively
int size(node* root)
{
    if(root==NULL)
        return 0;
    else
    {
        return(size(root->left)+1+size(root->right));
    }
}



//function to do binary search in binary search tree
node* bin_search(node* root,int key)
{
    if(root==NULL)
        return root;
    if(root->data==key)
        return root;
    if(root->data>key)
        return(bin_search(root->left,key));
    if(root->data<key)
        return(bin_search(root->right,key));
}


//function to insert in a binary tree
//          iteratively
node* bin_insert_iter(node*root,int key)
{
    node* temp=newnode(key);
    node* parent=NULL,* curr=root;
    if(root==NULL)
        return temp;
    while(curr!=NULL)
    {
        parent=curr;
        if(curr->data>key)
        {
            curr=curr->left;
        }
        else if(curr->data<key)
        {
            curr=curr->right;
        }
    }
    if(parent->data>key)
    {
        parent->left=temp;
    }
    else
    {
        parent->right=temp;
    }
    return root;

}



//function to insert in a binary search tree
//           recursively
node* bin_insert(node*root,int key)
{
    node*  node=newnode(key);
    if(root==NULL)
    {
        
        root=node;
        return root;
    }
    if(root->data>key)
        root->left=bin_insert(root->left,key);
    else if(root->data<key)
        root->right=bin_insert(root->right,key);
    return root;
}

//function to check wether a tree is continuous or not
bool is_conti(node* node)
{
    if(node==NULL)
        return 1;
    if(node->right==NULL&&node->left==NULL)
        return 1;
    if(node->right==NULL)
        return(abs(node->data-node->left->data)&&is_conti(node->left));
    if(node->left==NULL)
        return(abs(node->data-node->right->data)&&is_conti(node->right));
    return(abs(node->data-node->right->data)&&is_conti(node->right)&&abs(node->data-node->left->data)&&is_conti(node->left));

}

int search(char in[],char ch,int instrt,int inend)
{
    
    for(int i=instrt;i<=inend;i++)
    {
        if(in[i]==ch)
            return i;
    }
   
        return -1;
}

int preind=0;
//function to construct postorder from Inorder and Preorder
node * buildtree(char in[],char pr[],int instrt,int inend)
{
    if(instrt>inend)
    {
        return NULL;
    }
    
    node* tnode=newnode(pr[preind++]);
    int inindex=search(in,tnode->data,instrt,inend);

    if(instrt==inend)
    return tnode;
    tnode->left=buildtree(in,pr,instrt,inindex-1);
    tnode->right=buildtree(in,pr,inindex+1,inend);
    return tnode;
    
    
}






int main() 
{ 
    node* root = newnode(10); 
    root->left = newnode(11); 
    root->left->left = newnode(7); 
    root->right = newnode(9);  
    root->right->left = newnode(15); 
    root->right->right = newnode(8); 
  
    cout << "Inorder traversal before insertion:"; 
    inorder(root); 
      
    int key = 12; 
    insert_inorder(root, key); 
  
  
    cout << endl; 
    cout << "Inorder traversal after insertion:"; 
    inorder(root); 
    return 0; 
}