#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define si size()
#define bk back()
#define popb pop_back()
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl "\n"
#define lb lower_bound
#define ub upper_bound
#define emp empty()
#define beg begin()
#define en end()
#define forl(i,a,n) for(ll i=a;i<n;i++)
#define rfor(i,n,a) for(ll i=n;i>=a;i--)
#define fore(i,a,n) for(ll i=a;i<=n;i++)
ll mod=1e9+7;
ll power(ll num,ll r){
    if(r==0) return 1;
    if(r==1) return num%mod;
    ll ans=power(num,r/2)%mod;
    if(r%2==0) {
        return (ans*ans)%mod;
    } return (((ans*ans)%mod)*num)%mod;
}
ll modinv(ll num){
    return power(num,mod-2);
}

class Node
{
    public:
    ll key;
    ll recharge;
    Node *left;
    Node *right;
    ll height;
};

ll height(Node *n)
{
    if(n==NULL)
    {
        return 0;
    }
    else 
    {
        return n->height;
    }
}

Node *newnode (ll key)
{
    Node *node= new Node();
    node->left= NULL;
    node->right = NULL;
    node->key= key;
    node->height= 1;
    return (node);
}

Node *rightrotate (Node *y)
{
    Node *x= y->left;
    Node *t2= x->right;
    x->right= y;
    y->left= t2;
    y->height= max(height(y->left), height(y->right)) + 1;
    x->height= max(height(x->left), height(x->right)) + 1;

    return x;
}

Node *leftrotate (Node *x)
{
    Node *y= x->right;
    Node *t1= y->left;
    y->left= x;
    x->right= t1;
    y->height= max(height(y->left), height(y->right)) + 1;
    x->height= max(height(x->left), height(x->right)) + 1;

    return y;
}

ll balancefactor (Node *n)
{
    if(n==NULL)
    {
        return 0;
    }

    return height(n->left)-height(n->right);
}

Node *search (Node *root, ll key)
{
    if(root==NULL || root->key == key)
    {
        return root;
    }

    if(key> root->key)
    {
        return search(root->right, key);
    }
    if(key< root->key)
    {
        return search(root->left, key);
    }
}

//Insert a key in the subtree with root as node and the function returns the new root of the subtree//

Node *insert (Node *node, ll key)
{
    if(node==NULL)
    {
        return newnode(key);
    }
    if(key< node->key)
    {
        node->left= insert(node->left, key);
    }
    else if(key> node->key)
    {
        node->right= insert(node->right, key);
    }
    else 
    {
        return node;
    }

    node->height= 1+ max(height(node->left), height(node->right));

    ll balance= balancefactor(node);

    //Left left case//

    if(balance>1 && key<node->left->key)
    {
        return rightrotate(node);
    }

    //Left right case//

    if(balance>1 && key>node->left->key)
    {
        node->left= leftrotate(node->left);
        return rightrotate(node);
    }

    //Right right case//
    if(balance<-1 && key>node->right->key)
    {
        return leftrotate(node);
    }

    //Right left case//

    if(balance<-1 && key<node->right->key)
    {
        node->right= rightrotate(node->right);
        return leftrotate(node);
    }

    return node;
}

Node *root= NULL;
//------------------------------------------------------------
 
int main()
{
	ll n,q;
	cin>>n>>q;
    pair <ll, ll> maxi;
	maxi= {-1, -1};
	while(q--){
		ll t;
		cin>>t;
		if(t==1)
        {
			ll x;
            ll y;
            cin>>x >>y;
            if(root==NULL)
            {
                root= newnode(x);
                root->recharge= y;
                if(maxi.fi<y)
                {
                    maxi= {root->recharge, root->key};
                }
            }
            else if(search(root, x)!=NULL)
            {
                //If node with key x is found, increment its recharge value by y//
                Node *temp= search(root, x);
                temp->recharge= temp->recharge + y;
                if(maxi.fi<temp->recharge)
                {
                    maxi= {temp->recharge, temp->key};
                }
            }
            else if(search(root, x)== NULL) 
            {
                root= insert(root, x);
                Node *temp= search(root, x);
                temp->recharge= y;
                if(maxi.fi<temp->recharge)
                {
                    maxi= {temp->recharge, temp->key};
                }
            }
		}
		else if(t==2)
        {
			if(maxi.fi==-1) 
            {
                cout<<"No data available"<<endl;
            }
			else 
            {
                cout<< maxi.se <<endl;
            }
		}
	}
	return 0;
}
