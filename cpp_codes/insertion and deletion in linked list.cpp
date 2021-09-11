
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


typedef set<int> si;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector < vector<int> >  vii; 


class N
{
    public:
    int data;
    N *next;
    N(int d=1)
    {
        data=d;
        next=NULL;
    }
    
};


 
void print_ll(N *n) // function to print a liked list from node n passed into argument .
{
    while(n!=NULL)
    {
        cout<<n->data<<endl;
        n=n->next;
    }
    
}

N * delete_first(N* head)   //fuction to delete first element from a linked list(method 1).
{
    if(head!=NULL)
    {
        N* temp=head;
        head=head->next;
        free(temp);

    }
    return head;
    
}


void dp_delete_first(N ** head_ref)     //function to delete first element from a linked list (method 2-double pointer method).
{
    if(*head_ref!=NULL)
    {
        N * temp= *head_ref;
        *head_ref=(*head_ref)->next;
        free(temp); 
    }
}


/* Given a reference (pointer to pointer) to the head of a list and  
   an int, inserts a new node on the front of the list. */
void push_into_linkedlist(N ** head_ref,int d=0)    //function to insert before first element by double pointer method
{
    N* newnode=new N();
    newnode->data=d;
    newnode->next=(*head_ref);
    (*head_ref)=newnode;
}

/* Given a node prev_node, insert a new node after the given  
   prev_node */
void insert_after(N* node,int d=0)             //funnction to insert a node after a given node (with or without a double pointer)
{
    N* newnode=new N();
    newnode->data=d;
    newnode->next=(node)->next;
    (node)->next=newnode;

}



/* Given a reference (pointer to pointer) to the head 
   of a list and an int, appends a new node at the end  */
void append(N **head,int d=0)           //function to append a value to a given liked list (DOUBLE POINTER METHOD).
{
    N* newnode=new N();
    N* last=(*head);
    newnode->data=d;
    newnode->next=NULL;

    if((*head)==NULL)
    {
        *head=newnode;
        return;
    }
    else
    {
        while(last->next!=NULL)
        {
            last=last->next;
        }
        last->next=newnode;
        return;
    }
}

int main()
{   
    ios
    int T=1;
    //cin>>T;
    while(T--)
    {
        N* head=new N();
        N* second=new N();
        N* third=new N();

        head->data=1;
        head->next=second;
        second->data=7;
        second->next=third;
        third->data=3;
        third->next=NULL;
        print_ll(head);
        eol;       

        pushll(head,19);
        print_ll(head); 
        eol;

        popll(head);
        print_ll(head);
        eol;

        insert_after(second,63578);
        print_ll(head);
        eol;
        append(&head,15);
        print_ll(head);
        eol;

        return 0;


    }
}