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
    
    for(lli i=0; i<m; i++)
    {
        lli x, y;
        cin>>x >>y;
        adjacency[x].push_back(y);
        adjacency[y].push_back(x);
    }
    if(check(n)==true)
    {
        cout<<"YES";
    }
    else 
    {
        cout<< "NO";
    }
}
