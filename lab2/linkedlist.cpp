#include<bits/stdc++.h>
using namespace std;

struct node
{
    int x;
    int y;
    struct node *next;
};

struct node *head = NULL;

void addfirst(int a,int b)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->x = a;
    temp->y = b;
    temp->next = head;
    head = temp;
}

int delfirst()
{
    struct node *temp;
    if(head == NULL)
    {
        return -1;
    };
    temp = head;
    head = head->next;
    delete temp;
    temp = NULL;
    return 1;
}

int del(int a,int b)
{
    struct node *temp,*prev = NULL;
    temp = head;
    int f=0;
    while(temp != NULL)
    {
        if(temp->x==a  && temp->y==b)
        {
            struct node *temp2;
            temp2= temp->next;
            if(prev==NULL){
                head= temp2;

                delete(temp);
                temp = NULL;
            }
            else{
                prev->next = temp2;
                delete(temp);
                temp = NULL;
            }
            return 1;
        }
        else
        {
            prev = temp;
            temp = temp->next;
        }
    }
    return -1;
}

void search(long long int d)
{
    struct node *temp;
    int flag=0;
    temp = head;
    long long int f;
    long long int a,b;
    while(temp!= NULL){
        a = temp->x;
        b= temp->y;
        f = (a*a + b*b);
        //cout<<a;
        //f = f*f;
        //cout<<f;
        if(f<=d*d)
        {
            cout<<"("<<temp->x<<","<<temp->y<<") ";
            flag++;
        };
        temp = temp->next;
    };
    if(flag==0)
    {
        cout<<"-1" <<endl;
    }
    else{
        cout<<"\n";
    }
}

bool searchpoint(int a,int b)
{
    struct node *temp;
    temp = head;
    while(temp!=  NULL)
    {
        if(temp->x == a  && temp->y==b){
            return true;
        }
        temp= temp->next;
    };
    return false;
};

int length(){
    int counter=0;
    struct node *temp;
    temp = head;
    while(temp!= NULL)
    {
        counter++;
        temp = temp->next;
    }
    return counter;
}

int main()
{
    int a,b,c;
    int t;
    long long int d;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>a;
        if(a==1)
        {
            cin>>b>>c;
            addfirst(b,c);
        }
        else if(a==2)
        {
            cout<< delfirst() <<endl;
        }
        else if(a==3)
        {
            cin>>b>>c;
            cout<< del(b,c) <<endl;
        }
        else if(a==4){
            cin>>d;
            search (d);
        }
        else if(a==5){
            cin>>b>>c;

            if(searchpoint(b,c))cout<<"TRUE" <<endl;
            else cout<<"FALSE" <<endl;
        }
        else
            {

            b= length();
            cout<<b<<endl;
        };
    };
    return 0;
}
