 #include <bits/stdc++.h>

using namespace std;


#define fo(i,n) for(ll i=0;i<n;i++)
#define fr(i,n) for(ll i=1;i<=n;i++)
#define f(i,l,r) for(ll i=l;i<=r;i++)
#define rf(i,l,r) for(ll i=r;i>=l;i--)
#define inst(v,i,val) v.insert(v.begin()+i,val)
#define pqi priority_queue<int>  // can also be done with typedef
#define minpqi priority_queue<int,vector<int>,greater<int>>
#define inf 9123372036854775807
#define pb push_back 

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<int> vi;






template<typename T>
void show(vector<T> v){   // prints the entire vector
    fo(i,v.size()) cout<<v[i]<<" ";
    cout<<"\n";
    return; } 
template<typename T>
void sort(vector<T> &v) { sort(v.begin(), v.end()); } // sorts the original



#define max_siz 100007
vector<vll> gr[max_siz];

void reset(int n) // resets the graph
{
    fo(i,n+1) { gr[i].clear();}
    return; 
}

// Adds an edge from u to v;
void addedge(int u, int v, int w) { gr[u].push_back({v,w}); }


vvll dist;
vi countPaths;
void kDijkstra(int s, int n, int k)
{
    vll dummy(k,inf);
    dist.assign(n+1,dummy);
    countPaths.assign(n+1,0);
    dist[s][0]=0;

    while(1)
    {
        int c=0;
        int imn;
        ll mn=inf;
        fr(i,n)
        {
            if((countPaths[i]<k)&&(dist[i][countPaths[i]]<mn))
            {
                mn=dist[i][countPaths[i]];
                imn=i;
                c=1;
            }
        }

        for(vll ar: gr[imn])
        {
            int j=ar[0];
            ll w = ar[1];

            dist[j][k-1] = min(dist[j][k-1],mn+w);
            sort(dist[j]);
        }

        if(!c) break;

        countPaths[imn]++;
    }


}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,m,k;


    cin>>n>>m>>k;
    reset(n);

    fo(i,m)
    {
        ll u,v,w;
        cin>>u>>v>>w;
        addedge(u,v,w);
    }

    kDijkstra(1,n,k);
    show(dist[n]);







    
    return 0;
}

/*
4 6 3
1 2 1
1 3 3
2 3 2
2 4 6
3 2 8
3 4 1
*/