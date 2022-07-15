#include <bits/stdc++.h>

using namespace std;
  

#define fo(i,n) for(ll i=0;i<n;i++)
#define fr(i,n) for(ll i=1;i<=n;i++)
#define f(i,l,r) for(ll i=l;i<=r;i++)
#define rf(i,r,l) for(ll i=r;i>=l;i--)
#define inst(v,i,val) v.insert(v.begin()+i,val)
#define pqi priority_queue<int>  // can also be done with typedef
#define minpqi priority_queue<int,vector<int>,greater<int>>
#define inf 9223372036854775807
#define prim 1000000007
#define pb push_back

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef priority_queue<ll> pqll;
typedef priority_queue<ll,vector<ll>,greater<ll>> minpqll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int,string> pis;
typedef pair<string,int> psi;
typedef pair<ll,string> pls;
typedef pair<string,ll> psl;
typedef unordered_map<ll,ll> umll; 

class defaultdict{  // create object as defaultdict dd(-1); -// -1 is the default value
    ll val;
    map<ll,ll> mp;

    public:
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

void print(){cout<<'\n';} 
template<typename T, typename ...TAIL>
void print(const T &t, TAIL... tail)
{
    cout<<t<<' ';
    print(tail...);
}

void Debug(){} 
template<typename T, typename ...TAIL>
void Debug(const T &_, TAIL... tail)
{
    debug(_);
    Debug(tail...);
}




template<typename T>
void show(vector<T> v){   // prints the entire vector
    fo(i,v.size()) cout<<v[i]<<" ";
    cout<<"\n";
    return; }
template<typename T>
T max(vector<T> &v) { return *max_element (v.begin(), v.end()); }
template<typename T>
T min(vector<T> &v) { return *min_element (v.begin(), v.end()); }
template<typename T>
T sum(vector<T> &v) { return accumulate(v.begin(),v.end(),(T)0);}
template<typename T, typename G>
int count(vector<T> &v, G x){ return count(v.begin(),v.end(),x); }
template<typename T, typename G>
int index(vector<T> &v, G x) { return find(v.begin(),v.end(),x)-v.begin(); }

template<typename T, typename G>
T pop(vector<T> &v, G i){
    T x = v[i];
    v.erase(v.begin()+i);
    return x;
}

template<typename T>
T pop(vector<T> &v){
    T i = v.size()-1;
    T x = v[i];
    v.erase(v.begin()+i);
    return x;
}

template<typename T>
void sort(vector<T> &v) { sort(v.begin(), v.end()); } // sorts the original
template<typename T>
void reverse(vector<T> &v) { reverse(v.begin(), v.end()); } // reverses the original
template<typename T>
vector<T> sorted(vector<T> v) { sort(v.begin(), v.end()); return v; } // doesn't sorts the original
template<typename T>
vector<T> reversed(vector<T> v) { reverse(v.begin(), v.end()); return v; } // doesn't reverses the original

template <typename T>
vector<T> slicing(vector<T> const& v,
                  int X, int Y)
{
 
    // Begin and End iterator
    auto first = v.begin() + X;
    auto last = v.begin() + Y + 1;
 
    // Copy the element
    vector<T> vector(first, last);  // contains elements from index X to index Y
 
    // Return the results
    return vector;
}

template<typename T, typename G>
int ispresent(vector<T> &v, G x) { 
    for(T y: v) { if(x==y) return 1;}
    return 0; }

template <typename T>
vector<T> prefixsum(vector<T> const& v)
{
    vector<T> ps;
    int n = v.size();
    T s = 0;
    fo(i,n)
    {
        s+=v[i];
        ps.push_back(s);

    }
    return ps;
}
template <typename T,typename G>
void cprn(T t,G y)
{
    cout<<"Case #"<<t<<": "<<y<<endl;
    return;
}

template <typename T>
void hcprn(T t)
{
    cout<<"Case #"<<t<<": ";
    return;
}

ll modexp(ll a, ll b, ll p)  // calculate (a^b)%prime
{
    if(b==0) return 1;
    ll x = modexp(a,b/2,p);
    if(b%2==0) return (x*x)%p;
    else return (((x*x)%p)*(a%p))%p;

}
ll modexp2(ll a, ll b, ll c, ll p) // calculate (a^(b^c))%prime
{
    // By Fermat's Little Theorem (a^(p-1))%p = 1 if p is prime 
    ll x = modexp(b,c,p-1);  // so we first find remainder when b^c is divided by p-1
    return (modexp(a,x,p));  // then just do (a^remainder)%p

}
template <typename T>
T mmi(T N, T p){    // Modular Multiplicative Inverse    
    return powr(N,p-2,p);
}

ll npr(ll n, ll r, ll p)
{
    ll x=1;
    for(ll i = (n-r+1);i<=n;i++) x = (x*i)%p;
    return x;

}

ll ncr(ll n, ll r, ll p)
{
    ll nm = npr(n,r,p); // numerator
    ll dm=1;
    for(ll i=1;i<=r;i++) dm = (dm*i)%p;

    ll dmi = mmi(dm,p); // modular multiplicative inverse of the denominator;
    return (nm*dmi)%p;

}

ll catalan(ll n, ll p)
{
    return (ncr(2*n,n,p)-ncr(2*n,n-1,p))%p;
}
int index(string &st, char ch)
{
    fo(i,st.size()) { if(st[i]==ch) return i;}
    return -1;
}
ll count(string &st, char ch)
{
    ll c=0;
    for(char x: st) 
    {
        if(x==ch) c++;
    }
    return c;
}



template<typename T>
T Max(T &a){
    return a;
}
template<typename T, typename ...TAIL>
T Max(const T &t, TAIL... tail){
    return max(t,Max(tail...));
}

template<typename T>
T Min(T &a){
    return a;
}
template<typename T, typename ...TAIL>
T Min(const T &t, TAIL... tail){
    return min(t,Min(tail...));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t,n,m,k;
    ll a,b,c,d;
    ll x,y,z;
    cin>>t;
    fr(_,t)
    {
        cin>>n;
        vll ar(n);
        fo(i,n) cin>>ar[i];


    }

 

    return 0;
} 