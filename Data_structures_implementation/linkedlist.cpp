#include <bits/stdc++.h> 
using namespace std;  
class Node
{
public:
    int value;
    Node* nxt;
};
class Node* createnode()
{
    Node* node = new Node;
    return node;
}
void insertb(Node** root,int x)
{
    Node* temp = createnode();
    if(*root==NULL)
    {
        *root=temp;
        temp->value=x;
        temp->nxt=NULL;
    }
    else
    {
        Node* t = *root;
        while(t->nxt!=NULL)
        {
            t=t->nxt;
        }
        t->nxt=temp;
        temp->value=x;
        temp->nxt=NULL;
    }
}
void dee(Node** root, int key)
{
    Node *a,*b;
    a=*root;
    while(a->value!=key && a!=NULL)
    {
        a=a->nxt;
    }
    if(a==NULL) return;
    b=*root;
    while(b->nxt->value!=key && b->nxt!=NULL)
    {
        b=b->nxt;
    }
    b->nxt=a->nxt;
    delete a;
    return;
}
void print(Node* root)
{
    Node* temp= root;
    if(temp==NULL) return;
    else
    {
        while(temp!=NULL)
        {
            cout<<temp->value<<" ";
            temp=temp->nxt;
        }
        cout<<endl;
    }
}

int main()
{
    Node* root=NULL;
    insertb(&root,1);
    insertb(&root,2);
    insertb(&root,2);
    insertb(&root,3);
    insertb(&root,4);
    insertb(&root,5);
    print(root);
}
