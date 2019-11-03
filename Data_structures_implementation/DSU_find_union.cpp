
//Given input no. of vertices and no. of edges and the edges, determine whether the graph is cyclic or not//

#include <bits/stdc++.h> 
using namespace std; 
const int N= 4e6;

vector <pair <int, int> > edges;
int rankv[N];
int parent[N];

int find(int x)
{
    if(x!=parent[x])
    {
        //Path_compression
        parent[x]= find(parent[x]);
    }

    return parent[x];
}

void union_do(int x, int y)
{
    int rx= find(x);
    int ry= find(y);
    if(rx!=ry)
    {
        //Weighted union by rank
        if(rankv[rx]<rankv[ry])
        {
            parent[rx]= ry;
        }
        else if(rankv[rx]>rankv[ry])
        {
            parent[ry]= rx;
        }
        else if(rankv[rx]==rankv[ry])
        {
            //Rank shall change only when ranks of both are same
            parent[rx]= ry;
            rankv[ry]++;
        }
    }
}

bool is_cyclic()
{
    for(int i=0; i<edges.size(); i++)
    {
        int rx= find(edges[i].first);
        int ry= find(edges[i].second);
        if(rx==ry)
        {
            //If for an edge, both vertices have same root, then a cycle is found
            return 1;
        }
        //Else do union
        union_do(rx, ry);
    }
    return 0;
}

int main()
{
    //Take input no of vertices
    int n;
    cin>> n;
    //Initialize parents of all nodes as themselves and rank as 0//
    for(int i=1; i<=n; i++)
    {
        parent[i]=i;
        rankv[i]=0;
    }
    //Take input number of edges
    int e;
    cin>> e;
    for(int i=0; i<e; i++)
    {
        //Take input edges
        int x, y;
        cin>>x >>y;
        edges.push_back({x,y});
    }
    if(is_cyclic())
    {
        cout<< "Given graph is cyclic";
    }
    else 
    {
        cout<< "Given graph is acyclic";
    }

}
