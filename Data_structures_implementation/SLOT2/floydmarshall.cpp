#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ld long double
#define st string
#define sexy ios_base::sync_with_stdio(false); cin.tie(NULL)
#define mod 1000000007
const ll N=1e6+5;
int main()
{
    ll n,m;
    cin >> n >> m;
    ll adj[n][n];
    for(ll i=0;i<m;i++){
        ll p,q,w;
        cin>>p>>q>>w;
        adj[p][q]=w;
        adj[q][p]=w;
    }
    ll distance[n][n];
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            if (i == j)
                distance[i][j] = 0;
            else if (adj[i][j])
                distance[i][j] = adj[i][j];
            else
                distance[i][j] = 99999999999999;
        }
    }
    for (ll k = 1; k <= n; k++)
    {
        for (ll i = 1; i <= n; i++)
        {
            for (ll j = 1; j <= n; j++)
            {
                distance[i][j] = min(distance[i][j],
                                     distance[i][k] + distance[k][j]);
            }
        }
    }
}
