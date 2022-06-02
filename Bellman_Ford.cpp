#include <bits/stdc++.h>

using namespace std;

#define fo(i,n) for(int i=0;i<n;i++)
#define inf 912337203685477580

typedef long long ll;
typedef vector<ll> vll;

vector<vector<ll>> gr[200005];
vll dist;
vector<int> touch;

void addedge(ll u, ll v, ll w) {gr[u].push_back({v,w});}


void bellmanFord(int source,int n) // Complexity= O(V.E)
{
    dist.assign(n+1,inf);
    touch.assign(n+1,source);
    dist[source]=0;
    touch[source]=-1;

    fo(i,n-1)  // n-1 iterations
    {
        int c=0;
        for(int u=1;u<=n;u++)
        {
            for(vll ar: gr[u])
            {
                int v = ar[0];
                ll w = ar[1];
                if(dist[v]>(dist[u]+w))
                {
                    c=1;
                    touch[v]=u;
                    dist[v]=dist[u]+w;
                }
   
            }
        }


        if(!c) break;

    }
    return;
}

int main()
{
    int n,m,u,v;
    ll w;
    cin>>n>>m;
    fo(i,m)
    {
        cin>>u>>v>>w;
        addedge(u,v,w);
    }

    bellmanFord(1,n);
    for(int i=1;i<=n;i++) cout<<dist[i]<<" ";
    cout<<endl;

}

/*
5 8
1 2 3
3 2 5
1 3 2
3 1 1
1 4 2
5 2 4
4 3 -3
5 1 -1
*/