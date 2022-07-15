#include <bits/stdc++.h>

using namespace std;


#define fo(i,n) for(ll i=0;i<n;i++)
#define fr(i,n) for(ll i=1;i<=n;i++)
#define f(i,l,r) for(ll i=l;i<=r;i++)
#define rf(i,r,l) for(ll i=r;i>=l;i--)
#define inst(v,i,val) v.insert(v.begin()+i,val)
#define pqi priority_queue<int>  // can also be done with typedef
#define minpqi priority_queue<int,vector<int>,greater<int>>
#define INF 9223372036854775807
#define inf 7e18
#define MOD 1000000007
#define MOD2 998244353
#define PI 3.141592653589793238462
#define pb push_back
#define pob pop_back
#define len(x) ((x).size())
#define mpr make_pair
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define amax(x,y) x = max(x,y);
#define amin(x,y) x = min(x,y);



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
 

#ifdef GAURAV_07 
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
template <typename T> void _print(T x) {cerr << x;}
template <typename T, typename V> void _print(pair <T, V> p) {cerr << " pair("; _print(p.first); cerr << ","; _print(p.second); cerr << ")";}
template <typename T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << ", ";} cerr << "]";}
template <typename T> void _print(set <T> v) {cerr << "{ "; for (T i : v) {_print(i); cerr << ", ";} cerr << "}";}
template <typename T, typename V> void _print(map <T, V> mp) {cerr << "[ "; for (auto i : mp) {_print(i.first); cerr<<": "; _print(i.second); cerr<<" , ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}


class defaultdict{  // create object as defaultdict dd(-1); -// -1 is the default value
    ll val;
protected:
    map<ll,ll> mp;

public:
    defaultdict();
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

class Counter: public defaultdict{
public:
    Counter(vll &ar){
        for(ll x: ar){
            if(mp.count(x)) mp[x]++;
            else mp[x]=1;
        }
    }
};

void print(){cout<<'\n';} 
template<typename T, typename ...TAIL>
void print(const T &t, TAIL... tail)
{
    cout<<t<<' ';
    print(tail...);
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

ll modexp(ll a, ll b, ll p)  // calculate (a^b)%MODe
{
    a=a%p; 
    if(b==0) return 1;
    ll x = modexp(a,b/2,p);
    if(b%2==0) return (x*x)%p;
    else return (((x*x)%p)*a)%p;

}
ll pow(ll a, ll b){
    return modexp(a,b,inf);
}
ll modexp2(ll a, ll b, ll c, ll p) // calculate (a^(b^c))%MODe
{
    // By Fermat's Little Theorem (a^(p-1))%p = 1 if p is MODe 
    ll x = modexp(b,c,p-1);  // so we first find remainder when b^c is divided by p-1
    return (modexp(a,x,p));  // then just do (a^remainder)%p

}

// Function for extended Euclidean Algorithm
int gcdExtended(int a, int b, int* x, int* y);

// Function to find modulo inverse of a wrt m
int modInverse(int a, int m)  
{
    int x, y;
    int g = gcdExtended(a, m, &x, &y);
    if (g != 1)
    {
        cout << "Inverse doesn't exist";
        return -1;
    }
    else 
    {
        // m is added to handle negative x
        int res = (x % m + m) % m;
        return res;
    }
}

// Function for extended Euclidean Algorithm
int gcdExtended(int a, int b, int* x, int* y)
{
    
    // Base Case
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }
    
    // To store results of recursive call
    int x1, y1;
    int gcd = gcdExtended(b % a, a, &x1, &y1);

    // Update x and y using results of recursive
    // call
    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
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

    ll dmi = modInverse(dm,p); // modular multiplicative inverse of the denominator;
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

// floor of log10 of x
ll flog10(ll x) 
{
    ll c=0;
    while(x>0)
    {
        c++; 
        x/=10;
    }
    return (c-1);

}

// floor of log2 of x
ll flog2(ll x) 
{
    ll c=0;
    while(x>0)
    {
        c++;
        x/=2;
    }
    return (c-1);

}


int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    fr(_,t)
    {
        ll n,m,k;
        // ll a,b,c,d;
        // ll x,y,z;
        
        cin>>n;
        vll ar(n);
        fo(i,n) cin>>ar[i];

    }

    return 0;
} 