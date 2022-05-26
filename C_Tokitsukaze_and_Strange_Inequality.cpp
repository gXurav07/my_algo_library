#include <bits/stdc++.h>

using namespace std;


#define fo(i,n) for(int i=0;i<n;i++)
#define fro(i,n) for(int i=0;i<=n;i++)
#define fr(i,n) for(int i=1;i<=n;i++)
#define f(i,l,r) for(int i=l;i<r;i++)
#define inst(v,i,val) v.insert(v.begin()+i,val)
#define pqi priority_queue<int>  // can also be done with typedef
#define minpqi priority_queue<int,vector<int>,greater<int>>
#define inf 9223372036854775807
#define prim 1000000007

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef priority_queue<ll> pqll;
typedef priority_queue<ll,vector<ll>,greater<ll>> minpqll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int,string> pis;
typedef pair<string,int> psi;
typedef pair<ll,string> pls;
typedef pair<string,ll> psl;


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
vector<T> srt(vector<T> v) { sort(v.begin(), v.end()); return v; } // doesn't sorts the original
template<typename T>
vector<T> rev(vector<T> v) { reverse(v.begin(), v.end()); return v; } // doesn't reverses the original

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
    return s;
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
    else return (((x*x)%prim)*a)%p;

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


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t,n,k;
    //ll a,b,c,d;
    //ll x,y,z;
    cin>>t;
    fr(_,t)
    {
        cin>>n;
        vll pr(n);
        fo(i,n) cin>>pr[i];

        ll s=(ll)0;

        vll v(n,0);
        vector<vll> dp(n,v);

        fo(i,n)
        {
            fo(j,n)
            {
                if((j-i)<2) continue;
                if(i>0) dp[i][j]=dp[i-1][j] + ((pr[i]<pr[j])?1:0);
                else dp[i][j] = ((pr[i]<pr[j])?1:0);
            }
        }

        for(int b=1;b<(n-2);b++)
        {
            vll br(n,(ll)0);
            for(int c=b+1;c<(n-1);c++)
            {
                br[c] = br[c-1] + dp[b-1][c];
            }
            for(int d= b+2;d<n;d++)
            {
                if(pr[b]<pr[d]) continue;

                s+=br[d-1];
            

                // O(1)---> 2D prefix sum
                // for(int b=a+1;b<c;b++)
                // {
                //     for(int d=c+1;d<n;d++)
                //     {
                //         if(pr[b]>pr[d]) s++;
                //     }
                // } 
            }
        }

        print(s);

    }
    

    return 0;
}