#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pii>
#define mi map<int, int>
#define mii map<int, pii>
#define all(a) (a).begin(), (a).end()
#define x first
#define y second
#define sz(x) (int)x.size()
#define hell 1000000000
#define endl '\n'
#define rep(i, a, b) for (int i = a; i < b; i++)
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node()
    {
        val = 0;
        next = NULL;
    }
};

class MyLinkedList
{
private:
    Node *Head;
    int Size;
    Node *getNode(int data)
    {
        Node *newNode = new Node();
        newNode->val = data;
        newNode->next = NULL;
        return newNode;
    }

public:
    /** Initialize your data structure here. */
    MyLinkedList()
    {
        Head = NULL;
        Size = 0;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index)
    {
        Node *itr = Head;
        int ct = 1;
        while (itr != NULL)
        {
            if (ct == index)
            {
                return itr->val;
            }
            ct++;
            itr = itr->next;
        }
        return -1;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val)
    {
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val)
    {
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val)
    {
        if (index < 1 || index > Size + 1)
        {
            cout << "Invalid Index";
            return;
        }
        while(index--)
        {
            if(!index)
            {
                Node * newNode=getNode(val);
                
            }
        }
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index)
    {
        Node *node = Head;
        int ct = 1;
        while (ct < index)
        {
            ct++;
            node = node->next;
            if (node = NULL)
                return;
        }
        if (node->next != NULL)
        {
            node->next = node->next->next;
        }
        Size--;
        return;
    }
    void print()
    {
        Node *node = Head;
        while (node != NULL)
        {
            cout << node->val << " ";
            node = node->next;
        }
        return;
    }
};

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    MyLinkedList myLinkedList = MyLinkedList();
    rep(i, 0, 10)
        myLinkedList.addAtIndex(i, i);
    myLinkedList.print();
}