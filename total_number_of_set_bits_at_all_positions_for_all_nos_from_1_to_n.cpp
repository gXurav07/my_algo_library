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

void nop(ll n, vll &v)
{
    if(n<=1) 
    {
        v[0]=n;
        return;
    }

    ll c=1,k;
    fo(i,19)
    {
        v[i]+=c;
        for(int j=i-1;j>=0;j--)
        {
            v[j]*=2;
        }

        c=c*2;
        if(2*c>n)
        {
            k=i;
            break;
        
        }
        
    }

    ll x = n-c+1;
    fo(j,k+1)
    {
        ll y = pow(2,j);
        v[j]+=(x/(2*y))*y + max((ll)0,x%(2*y)-y); 
    }
    v[k+1]= x;
    return;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    vll v(23,0);
    nop(n,v);
    show(v);
    return 0;
}