#include <bits/stdc++.h>

using namespace std;


class dsu{
    int n=0;
    vector<int> parent={0}; 
    vector<int> height={1};  // Helps in Keeping find complexity O(logn)
    map<string,int> idx;
    vector<string> val={""};

    public:
    dsu() {}
    dsu(int a){
        n=a;
        parent.assign(n+1,0);
        height.assign(n+1,0);
        for(int i=1;i<=n;i++){   // 1 to n indexing
            parent[i]=i; 
            }
    }
    void makeset(vector<string> &ar){
        n=ar.size();
        parent.assign(n+1,0);
        height.assign(n+1,0);
        for(int i=1;i<=n;i++){   // 1 to n indexing
            parent[i]=i; 
            idx[ar[i-1]]=i;
            val[i]=ar[i-1];
        }
        

                 
    }

    int find(string &st){
        int i =idx[st];
        int j=i;
        while(parent[i]!=i) i=parent[i];
        while(j!=i) {int k =parent[j]; parent[j]=i; j=k;} // Path Compression
        return i;
    }

    int find(int i){
        int j=i;
        while(parent[i]!=i) i=parent[i];
        while(j!=i) {int k =parent[j]; parent[j]=i; j=k;} // Path Compression
        return i;
    }

    void Union(string &s1,string &s2){
        int a = find(s1), b=find(s2);
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
            cout<<val[id.first]<<" : ";
            for(int i: id.second) cout<<val[i]<<" ";
            cout<<endl;
        }
        return;


    }

    int areconnected(string &x, string &y){
        return ((find(x)==find(y)));
    }

    void add(string st){
        if(idx.count(st)) return;
        n++;
        parent.push_back(n);
        height.push_back(0);
        val.push_back(st);
        idx[st]=n;
        return;

    }

};


int main()
{

    dsu s;
    int m; 
    cin>>m;
    string a,b;
    for(int i=0;i<m;i++){

        cin>>a;
        cin>>b;
        s.add(a);
        s.add(b);
        s.Union(a,b);

    }
    s.printset();
}