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
struct node
{
    int val;
    node *next;
    node * random;
    node(int d)
    {
        val=d;
        next=random=NULL;
    }
};

node* clone(node* A)
{
    node* root1,*root2,* temp1,*temp2;
    
    root1=A;
    temp1=root1;
  
    while(temp1!=NULL)
    {
        temp2=temp1->next;
        temp1->next=new node(temp1->val);
        temp1->next->next=temp2;
        temp1=temp2;
        
    }
    temp1=root1;
    
    while(temp1!=NULL)
    {
        if(temp1->next)
        temp1->next->random= temp1->random ? temp1->random->next : temp1->random;
        

        temp1= temp1->next ? temp1->next->next: temp1->next;
        
    }
     node* orig=A,* copy=A->next;
    temp2=copy;
    while(orig&& copy)
    {
        orig->next= orig->next ? orig->next->next: orig->next;
        copy->next= copy->next ? copy->next->next: copy->next;
        
        orig=orig->next;
        copy=copy->next;
    }
   
  
    return copy;
}

int main()
{   
    ios
    int T=1;
    //cin>>T;
    while(T--)
    {

    }
}
