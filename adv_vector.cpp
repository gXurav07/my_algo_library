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
void prefixsum(vector<T> const& v, vector<T> &ps)  // to use initialize empty vector ps and send it 
{
    
    T s = 0;
    int n = ps.size();
    fo(i,n)
    {
        s+=v[i];
        ps.push_back(s);

    }
    return;
}

int main()
{
    vector<string> v(5);  // initialization
    v={"34","3","345","hgfh","34"};  // assignmnet

    cout<<max(v)<<" "<<min(v)<<endl;  // max , min
    // cout<<sum(v)<<endl; //sum
    cout<<index(v,"3")<<endl;
    cout<<count(v,"34")<<endl;

    show(v);

    sort(v);
    show(v);



    

    return 0;
}