#include<algorithm>
#include<vector>
#include<iostream>
#include<cstring>
#include<cmath>
 
using namespace std;

#define mod 1000000007
 
// DSU 
 
long long int parent[100001],rankv[100001];
 
void make_set(long long int x)
{
    parent[x]=x;
    rankv[x]=1;
}
 
long long int find_set(long long int x)
{
    if (x==parent[x]) return x;
    return parent[x]=find_set(parent[x]);
}
 
void union_set(long long int a, long long int b)
{
    a=find_set(a);
    b=find_set(b);
    if (a!=b)
    {
        if (rankv[a]<rankv[b]) swap(a,b);
        parent[b]=a;
        rankv[a]+=rankv[b];
    }
}
 
int main()
{
    long long int n,m;
    vector<pair<long long int,pair<long long int,long long int> > > a;
    vector<pair<long long int,long long int> > result;
    cin>>n>>m;
    for (long long int i=1;i<=n;i++) make_set(i); //  creating of sets
 
    // reading graph
    for (long long int i=0;i<m;i++)
    {
        long long int x,y,s; // x,y - vertex, s - weight of edge
        cin>>x>>y>>s;
        a.push_back(make_pair(s,make_pair(x,y)));
    }
 
    sort(a.begin(),a.end()); // sorting edges
    long long int answer=1;
 
    // finding result
    for (long long int i=m-1;i>=0;i--)
    {
        long long int x=a[i].second.first,y=a[i].second.second,s=a[i].first;
        if (find_set(x)!=find_set(y))
        {
            answer= ((answer)%mod*(s)%mod)%mod;
            union_set(x,y);
        }
    }
 
    cout<< answer;
}
