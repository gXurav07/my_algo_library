#include <bits/stdc++.h>

using namespace std;

class dsu{
    int n;
    int *parent; 
    int *height;  // Helps in Keeping find complexity O(logn)
    public:
    dsu() {}
    dsu(int a){
        n=a;
        parent = new int[n+1];
        height = new int[n+1];
        for(int i=1;i<=n;i++){   // 1 to n indexing
            parent[i]=i; 
            height[i]=0; 
            }
    }
    void makeset(int a){
        n=a;
        parent = new int[n+1];
        height = new int[n+1];
        for(int i=1;i<=n;i++){   // 1 to n indexing
            parent[i]=i; 
            height[i]=0; 
            }     
    }

    int find(int i){
        int j=i;
        while(parent[i]!=i) i=parent[i];
        while(j!=i) {int k =parent[j]; parent[j]=i; j=k;} // Path Compression
        return i;
    }

    void Union(int i, int j){
        int a = find(i), b=find(j);
        if(a==b) return;
        if(height[a]>height[b]) swap(a,b);
        if(height[a]==height[b]) height[b]++;
        parent[a] = b; 
        return;

    }

    void printset()
    {
        map<int,vector<int>> mp;

        for(int i=1;i<=n;i++){
            int id = find(i);
            if(mp.count(id)) mp[id].push_back(i);
            else mp[id]={i};
        }


        for(auto id: mp)
        {
            cout<<id.first<<" : ";
            for(int i: id.second) cout<<i<<" ";
            cout<<endl;
        }
        return;


    }

    int areconnected(int x, int y){
        return ((find(x)==find(y)));
    }


};


int main()
{
    int n;
    cin>>n;
    dsu s(n);
    int m; 
    cin>>m;

    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        s.Union(x,y);
    }
    s.printset();
}