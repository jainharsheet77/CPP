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


class node
{
    public:
    int data;
    node * next;
    node(int d=1)
    {
        data=d;
        next=NULL;
    }
    
};

void print_ll(node *n) // function to print a liked list from node n passed into argument .
{
    while(n!=NULL)
    {
        cout<<n->data<<" ";
        n=n->next;
    }
    
}

node * delete_first(node* head)   //fuction to delete first element from a linked list(method 1).
{
    if(head!=NULL)
    {
        node* temp=head;
        head=head->next;
        free(temp);

    }
    return head;
    
}


void dp_delete_first(node ** head_ref)     //function to delete first element from a linked list (method 2-double pointer method).
{
    if(*head_ref!=NULL)
    {
        node * temp= *head_ref;
        *head_ref=(*head_ref)->next;
        free(temp); 
    }
}

void delete_key(node** head_ref,int k)         //function deletes the  given key,k, from ll.
{
    node * temp=new node(),*prev=new node();
    temp=*head_ref;
    if(temp!=NULL&&temp->data==k)
    {
        *head_ref=(*head_ref)->next;
    }
    
    while(temp!=NULL&&temp->data!=k)
    {
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL)return;
    prev->next=temp->next;
}



void delete_pos(node** head_ref,int pos)           //function deletes value the given position starting from 0
{
    node* temp=*head_ref;
    if(*head_ref!=NULL&&pos==0)
    {
        *head_ref=temp->next;
    }
    for(int i=0;temp!=NULL&&i<pos-1;i++)
    temp=temp->next;
    if(temp==NULL||temp->next==NULL)
    return;
    else
    {
        temp->next=temp->next->next;
        
    }
}


void delete_list(node** head_ref)              //function to delete entire list
{
    node* curr=*head_ref;
    node* next=new node();
    while(curr!=NULL)
    {
        next=curr->next;
        free(curr);
        curr=next;
    }
    *head_ref=NULL;
    cout<<"LIST deleted";
}

void push_into_linkedlist(node ** head_ref,int d)    //function to insert before first element by double pointer method
{
    node* newnode=new node();
    newnode->data=d;
    newnode->next=(*head_ref);
    (*head_ref)=newnode;
}


void insert_after(node* n,int d=0)             //funnction to insert a node after a given node (with or without a double pointer)
{
    node* newnode=new node();
    newnode->data=d;
    newnode->next=(n)->next;
    (n)->next=newnode;

}

void append(node **head,int d=0)           //function to append a value to a given liked list (DOUBLE POINTER METHOD).
{
    node* newnode=new node();
    node* last=(*head);
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

int length_ll(node* head)              //function returns length of the linked list
{
    int l=0;
    node* temp=head;
    while(temp!=NULL)

    {
        temp=temp->next;
        l++;
    }
    return l;
}
int is_present(node* head,int k)           //function returns 1 if the key is present and 0 if it is not present
{
    node* temp=head;
    while(temp->data!=k)
    {
        temp=temp->next;
        if(temp==NULL)
        return 0;
    }
    
    
    return 1;
}

int  get_nth(node* head,int k)         //function returns the value at the given pos
{
    node* temp=head;
    int count=0;
    while(temp!=NULL)
    {
        if(count==k)
        {
            return temp->data;
        }
        
        temp=temp->next;
        count++;
        
    }
    assert(0);
    
}
int print_nth_from_end(node* head,int k)           //function returns nth node from last
{
    node* ref=head;
    node* m=head;
    int ct=0;
    if(head!=NULL)
    {
        while(ct<k)
        {
            ref=ref->next;
            ct++;
            if(ref==NULL)
            {
                cout<<"n is greater than length";
                assert(0);
            }

        }
        while(ref!=NULL)
        {
            ref=ref->next;
            m=m->next;
        }
        return m->data;

    }

}
int mid_element(node* head)        //function returns mid element in a ll
{
    node* slow=head;
    node* fast=head;
    
        while(fast!=NULL&&fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
    return slow->data;
}

int count_ll(node*head,int k)          //function to return occurences of a given number k
{
    int ct=0;
    node* temp=head;
    while(temp!=NULL)
    {
        
        if(temp->data==k)
        {
            ct++;
        }
        temp=temp->next;
    }
    return ct;
}


bool loop_is_present(node * head)           //functio returns if there is a loop in ll or not (1 loop )(0  no loop)
{
    node* fast=head;
    node* slow=head;
    while(fast!=NULL&&fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
        if(fast==NULL)
        {
            return 0;
        }
        if(fast==slow)
        {
            return 1;
        }
    }
}

int loop_len(node * head)           //function to return the length of loop in a ll(returns 0 if no loop)
{
    int ct=0;
    node* fast=head;
    node* slow=head;
    while(slow!=NULL&&fast!=NULL&&fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow)
        {
            node*temp=slow;
            node* curr=temp->next;
            ct++;
            while(curr!=temp)
            {
                curr=curr->next;
                ct++;
            }
            return ct;
        }
    }
    return ct;

}


int is_pallindrome(node * head)         //function returns if a ll is pallindrome or not
{
    node* temp=head;
    stack <int> dat;
    int flag=0;
    while(temp!=NULL)
    {
        dat.push(temp->data);
        temp=temp->next;
    }
    node* t=head;
    while(t!=NULL)
    {
        int d=dat.top();
        dat.pop();
        if(d==t->data)
        flag=1;
        else
        {
            flag=0;
            return 0;
        }
        
        t=t->next;
    }
    if(flag==1)
    return 1;
    else
    return 0;
}

node* delete_multiple(node * head)          //function to remove duplicate elements from a sorted linked list
{
    node * temp=head;
    node * prev=head;
    while((prev->next)!=NULL)
    {
        
        if(prev->data==prev->next->data)
        {
            temp=prev->next->next;
            free(prev->next);
            prev->next=temp;
        }
        else
        {
            prev=prev->next;
        }
    }
    return head;
}

void swap_ll(node **head,int a,int b)           //function to swap two links without swapping data
{
    node * temp =*head;
    node * A=*head;
    node* B=*head;
    node* prev_A=NULL;
    node* prev_B=NULL;
   
    if(a==b)
    return;
while(A&&A->data!=a)
{
    prev_A=A;
    A=A->next;
}
while(B&&B->data!=b)
{
    prev_B=B;
    B=B->next;
}
if(A==NULL||B==NULL)
return;
if(prev_A!=NULL)
prev_A->next=B;
else
*head=B;
if(prev_B!=NULL)
prev_B->next=A;
else
*head=A;
temp=B->next;
B->next=A->next;
A->next=temp;
}


void last_to_first(node ** head)        //function to bring last element from last to first
{
    node* temp=*head;
    node* hea=*head;
    node*prev=NULL;
    while(temp->next!=NULL)
    {
        prev=temp;
        temp=temp->next;
        
    }
   
     
    *head=temp;
    temp->next=hea;
    
    prev->next=NULL;
    
    
}



int main()
{   
    ios
    int T=1;
    //cin>>T;
    while(T--)
    {
        node* head=new node();
        head=NULL;
        for(int i=1;i<10;i++)
        pushll(head,i);

        print_ll(head); 
        eol;

        popll(head);
        print_ll(head);
        eol;
        append(&head,15);
        print_ll(head);
        eol;
        delete_key(&head,6);
        print_ll(head);
        eol;
        cout<<length_ll(head);
        eol;
        cout<<is_present(head,23 );
        eol;
        cout<<get_nth(head,1);
        eol;
        cout<<print_nth_from_end(head,2);
        eol;
        cout<<mid_element(head);
        eol;
        cout<<count_ll(head,15);
        eol;
        cout<<loop_is_present(head);
        eol;
        cout<<loop_len(head);
        eol;
        cout<<is_pallindrome(head);
        eol;
        swap_ll(&head,4,7);
        print_ll(head);
        eol;

        return 0;


    }
}