#include <bits/stdc++.h>

using namespace std;


#define fo(i,n) for(int i=0;i<n;i++)
#define fro(i,n) for(int i=0;i<=n;i++)
#define fr(i,n) for(int i=1;i<=n;i++)
#define f(i,l,r) for(int i=l;i<r;i++)
#define inst(v,i,val) v.insert(v.begin()+i,val)

typedef long long ll;
typedef deque<ll> dll;
typedef deque<string> ds;
typedef deque<int> di;

void print(){cout<<'\n';} 
template<typename T, typename ...TAIL>
void print(const T &t, TAIL... tail)
{
    cout<<t<<' ';
    print(tail...);
}

template<typename T>
void show(deque<T> v){   // prints the entire deque
    fo(i,v.size()) cout<<v[i]<<" ";
    cout<<"\n";
    return; }
template<typename T>
T max(deque<T> &v) { return *max_element (v.begin(), v.end()); }
template<typename T>
T min(deque<T> &v) { return *min_element (v.begin(), v.end()); }
template<typename T>
T sum(deque<T> &v) { return accumulate(v.begin(),v.end(),0);}
template<typename T, typename G>
int count(deque<T> &v, G x){ return count(v.begin(),v.end(),x); }
template<typename T, typename G>
int index(deque<T> &v, G x) { return find(v.begin(),v.end(),x)-v.begin(); }

template<typename T, typename G>
T pop(deque<T> &v, G i){
    T x = v[i];
    v.erase(v.begin()+i);
    return x;
}

template<typename T>
T pop(deque<T> &v){
    T i = v.size()-1;
    T x = v[i];
    v.erase(v.begin()+i);
    return x;
}

template<typename T>
void sort(deque<T> &v) { sort(v.begin(), v.end()); } // sorts the original
template<typename T>
void reverse(deque<T> &v) { reverse(v.begin(), v.end()); } // reverses the original
template<typename T>
deque<T> srt(deque<T> v) { sort(v.begin(), v.end()); return v; } // doesn't sorts the original
template<typename T>
deque<T> rev(deque<T> v) { reverse(v.begin(), v.end()); return v; } // doesn't reverses the original

template <typename T>
deque<T> slicing(deque<T> const& v,
                  int X, int Y)
{
 
    // Begin and End iterator
    auto first = v.begin() + X;
    auto last = v.begin() + Y + 1;
 
    // Copy the element
    deque<T> deque(first, last);  // contains elements from index X to index Y
 
    // Return the results
    return deque;
}

template <typename T>
deque<T> prefixsum(deque<T> const& v)
{
    deque<T> ps;
    int n = v.size();
    T s = 0;
    fo(i,n)
    {
        s+=v[i];
        ps.push_back(s);

    }
    return s;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t,n;

    dll v={1,-2,5,5,6,0,2};
    sort(v);
    show(v);

    return 0;
}