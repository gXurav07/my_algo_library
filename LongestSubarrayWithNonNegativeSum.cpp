#include <bits/stdc++.h>

using namespace std;


#define fo(i,n) for(int i=0;i<n;i++)
#define fro(i,n) for(int i=0;i<=n;i++)
#define fr(i,n) for(int i=1;i<=n;i++)
#define f(i,l,r) for(int i=l;i<r;i++)

typedef long long ll;
typedef vector<ll> vll;
void print(){cout<<'\n';}
template<typename T, typename ...TAIL>
void print(const T &t, TAIL... tail)
{
    cout<<t<<' ';
    print(tail...);
}  

void show(vll v){   // prints the entire vector
    fo(i,v.size()) cout<<v[i]<<" ";
    cout<<"\n";
    return; }

ll max(vll &v) { return *max_element (v.begin(), v.end()); }
ll min(vll &v) { return *min_element (v.begin(), v.end()); }
ll sum(vll &v) { return accumulate(v.begin(),v.end(),0);}
void sort(vll &v) { sort(v.begin(), v.end()); } // sorts the original
void reverse(vll &v) { reverse(v.begin(), v.end()); } // reverses the original
vll srt(vll v) { sort(v.begin(), v.end()); return v; } // doesn't sorts the original
vll rev(vll v) { reverse(v.begin(), v.end()); return v; } // doesn't reverses the original
template <typename T>
void prefixsum(vector<T> const& v, vector<T> &ps)
{
    
    T s = 0;
    int n = v.size();
    fo(i,n)
    {
        s+=v[i];
        ps.push_back(s);

    }
    return;
}

int ispresent(vll ps, int k)
{
    int n = ps.size();
    if(ps[k-1]>=0) return 1;
    f(i,1,n-k+1)
    {

        if((ps[i+k-1]-ps[i-1])>=0) return 1;
        
    }
    return 0;
}

int lswnns(vll v)
{
    int n = v.size();
    int l=0,r=n,m;
    vll ps;
    prefixsum(v,ps);
    while(l<r)
    {
        m = (l+r)/2;
        if(ispresent(ps,m)) l=m+1;
        else r=m-1;
    }
    if(!ispresent(ps,l)) l--;
    return l;  
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;

    cin>>n;
    vector<ll> v(n);
    fo(i,n) cin>>v[i];
    print(lswnns(v));
    return 0;
}