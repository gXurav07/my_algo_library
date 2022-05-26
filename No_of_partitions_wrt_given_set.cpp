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
T sum(vector<T> &v) { return accumulate(v.begin(),v.end(),0);}
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

int ispal(ll n)
{
    ll r,sum=0,temp=n;    
    
    while(n>0)    
    {    
        r=n%10;    
        sum=(sum*10)+r;    
        n=n/10;    
    } 
    return (temp==sum); 
}
void gen(vll &pal)
{
    
    fr(i,40000){
        if(ispal(i)) pal.push_back((ll)i);

    }

    return;

} 

ll solve(vector<vll> &dp,vll &pal, ll i, ll j)
{
    if(dp[i][j]>0) return dp[i][j];
    if(i==1) {
        dp[i][j]=1;
        return 1; 
        }
    if(pal[j]>i)
    {
        dp[i][j] = solve(dp, pal, i, j-1);
        return dp[i][j];
    }
    if(pal[j]==i)
    {
        dp[i][j] = solve(dp, pal, i, j-1)+1;
        return dp[i][j];
    }
    dp[i][j] = solve(dp, pal, i-pal[j],j);
    if(j>0) dp[i][j]+=dp[i][j-1];
    dp[i][j]%=prim;
    return dp[i][j];

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vll pal;
    gen(pal);
    vll v(499,-1);
    vector<vll> dp(40003,v);
    fr(i,40000)
    {
        print(i,":- ");
        fo(j,498)
        {
            dp[i][j]=solve(dp,pal,i,j);
            //if(i>39900) cout<< dp[i][j]<<" ";
        }
       // cout<<"\n";
       


    }

    
    ll t,n;
    cin>>t;
    fr(_,t)
    {
        cin>>n;
        print(dp[n][497]);

    }
    

    return 0;
}