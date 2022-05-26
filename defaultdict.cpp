#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class defaultdict{

    ll val=0;
    map<ll,ll> mp;

    public:
    defaultdict(){};
    defaultdict(ll a): val(a) {}

    ll &operator[](const ll &idx) {
        auto itr = mp.find(idx);
        if(itr==mp.end()){
            mp.insert(pair<ll,ll>(idx,val));
            itr = mp.find(idx);
            return itr->second;
        }
        else return itr->second;    
    }

    void clear() { mp.clear(); return;}
    void setdef(ll x) { val =x; return;}
    void erase(ll x) {mp.erase(x); return;}
    vector<ll> keys(){
        vector<ll> kys;
        for(auto i=mp.begin();i!=mp.end();i++)
            kys.push_back(i->first);
        return kys;
    }

};

int main()
{
    defaultdict dd(-1);

    dd[1]=2;
    dd[2]=3;
    dd[-2]=10;
    dd.setdef(0);
    for(int i=-3;i<5;i++) cout<<dd[i]<<endl;
    vector<ll> ar = dd.keys();
    for(ll i:ar) cout<<i<<" ";
    cout<<endl;

}