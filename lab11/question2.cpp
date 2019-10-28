#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
const int N= 4e6+1;

vector <lli> adjacency[N+1];

//Checking bipartite in a subtree//
bool checkbipartite( lli vertex, lli colour[])
{
    //Define non colorable as -1//
    
    //Define first colour by 1//
    colour[vertex]=1;
    queue <lli> q;
    q.push(vertex);
    while(!q.empty())
    {
        lli parent= q.front();
        q.pop();
        for(auto ass: adjacency[parent])
        {
            if(colour[ass]==-1)
            {
                if(colour[parent]==0)
                {
                    colour[ass]=1;
                }
                else 
                {
                    colour[ass]=0;
                }
                q.push(ass);
            }
            else if(colour[ass]==colour[parent])
            {
                return false;
            }
        }
    }
    return true;
}

bool check(lli n)
{
    //Checking for disconnected graph//
    lli colour[n+1];
    for(lli i=1; i<=n; i++)
    {
        colour[i]=-1;
    }
    for(lli i=1; i<=n; i++)
    {
        if(colour[i]==-1 && checkbipartite(i, colour)==false)
        {
            return false;
        }
    }
    return true;

}

int main()
{
    lli n, m;
    cin>>n >>m;
    lli dummy_count=0;
    
    while(m--)
    {
        lli x, y, z;
        cin>>x >>y >>z;
        lli dummy=n+1;
        if(z%2==1)
        {
        adjacency[x].push_back(y);
        adjacency[y].push_back(x);
        }
        else 
        {
            adjacency[dummy].push_back(x);
            adjacency[dummy].push_back(y);
            adjacency[x].push_back(dummy);
            adjacency[y].push_back(dummy);
        }
        dummy= dummy+1;
        dummy_count++;
    }

    if(check(n+dummy_count)==true)
    {
        cout<<"NO";
    }
    else 
    {
        cout<< "YES";
    }
}
