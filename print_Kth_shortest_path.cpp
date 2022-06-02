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
vector<vvll> touch;
void kDijkstra(int s, int n, int k)
{
    vll dummy(k,inf);
    vvll touchDummy(k);

    dist.assign(n+1,dummy);
    touch.assign(n+1,touchDummy);

    countPaths.assign(n+1,0);
    dist[s][0]=0;

    priority_queue<vll,vector<vll>,greater<vll>> pq;
    int sz=0;

    pq.push({0,s,-1,0});
    sz++;
 


    while(!pq.empty())
    {
        vll br = pq.top();
        pq.pop();
        sz--;

        int i=br[1];
        ll mn = br[0];

        //if(countPaths[i]==k) continue;
        if(mn>dist[i][k-1]) continue;



        for(vll ar: gr[i])
        {
            int j=ar[0];
            ll w = ar[1];


            if((mn+w)<dist[j][k-1])
            {
                dist[j][k-1]=w+mn;
                sort(dist[j]);
                pq.push({mn+w,(ll)j,i,countPaths[i]});
                sz++;
            }
        }
        touch[i][countPaths[i]] = {br[2],br[3]};
        countPaths[i]++;
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

    // fr(i,n)
    // {
    //     fo(j,k) { cout<<i<<" "<<j<<": "; show(touch[i][j]); }
    // }



    
    cout<<dist[n][k-1]<<endl;  // Kth shortest path from 1 to n

    vll path;
    int curNode=n, curIndex=k-1;
    int c=0;

    while(curNode!=1)
    {

        path.pb(curNode);

        vll ar= touch[curNode][curIndex];
        if(ar.empty()) break;

        curNode = ar[0];
        curIndex = ar[1];

        c++;
        if(c>200) break;
    }
    path.pb(1);
    reverse(path.begin(), path.end());
    show(path);



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