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
    a=a%p; 
    if(b==0) return 1;
    ll x = modexp(a,b/2,p);
    if(b%2==0) return (x*x)%p;
    else return (((x*x)%p)*a)%p;

}
ll modexp2(ll a, ll b, ll c, ll p) // calculate (a^(b^c))%prime
{
    // By Fermat's Little Theorem (a^(p-1))%p = 1 if p is prime 
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

void kruskal(int n, vvll &ar, vvi &edges)
{
    sort(ar);
    dsu ds(n);
    int m=0;

    for(auto ed: ar){
        if(!ds.areconnected(ed[1],ed[2])) {
            edges.push_back({(int)ed[1],(int)ed[2]});
            m++;
            ds.Union(ed[1],ed[2]);
        }
        if(m==(n-1)) break;

    }
    return;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t,n,m,k;
    //ll a,b,c,d;
    //ll x,y,z;
    cin>>t;
    fr(_,t)
    {
        vvll ar;
        cin>>n>>m;
        fo(i,m)
        {
            ll u,v,w;
            cin>>u>>v>>w;
            ar.pb({w,u,v});
        }

        vvi edges;
        kruskal(n,ar,edges);

        for(auto a: edges) show(a);
    }
 

    return 0;
} 