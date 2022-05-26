//  SUM QUERY + POINT UPDATE
#include <bits/stdc++.h>

using namespace std;

#define fr(i,n) for(int i=1;i<=n;i++)
#define fo(i,n) for(int i=0;i<n;i++)

typedef long long ll;


ll tree[(int)8e5+1]; // Assuming n<= 2.10^5

void build(int i, int l, int r, vector<ll> &ar)
{
    if(l==r){
        tree[i]=ar[l];
        return;
    }

    int mid= (l+r)/2;
    build(2*i,l,mid,ar);
    build(2*i+1,mid+1,r,ar);
    tree[i] = tree[2*i]+tree[2*i +1];  // For sum queries
    return;
}


ll query(int i, int l , int r, int a, int b) // query asked for subarray from a to b
{
    if((a>r)||(b<l)) return 0;
    if((a<=l)&&(r<=b)) return tree[i];

    int mid=(l+r)/2;
    ll ans=0;

    ans = query(2*i,l,mid,a,b) + query(2*i+1,mid+1,r,a,b);
    return ans;
}

void update(int i, int l, int r, int j, ll val) // update jth element to be val
{
    if((j<l)||(j>r)) return;

    if((l==j)&&(r==j)) 
    {
        tree[i]=val;
        return;
    }
    int mid=(l+r)/2;

    update(2*i,l,mid,j,val);
    update(2*i+1,mid+1,r,j,val);
    tree[i] = tree[2*i] + tree[2*i +1];
    return;



}

int main()
{
    int n;
    cin>>n;
    vector<ll> ar(n);
    fo(i,n) cin>>ar[i];

    build(1,0,n-1,ar);
    // fo(i,4*n) cout<<tree[i]<<" ";
    // cout<<endl;

    int typ;

    while(1)
    {
        cin>>typ;
        if(typ==1)
        {
            int a,b; 
            cin>>a>>b; 
            cout<<query(1,0,n-1,a-1,b-1)<<endl; // remember the -1 with a and b ( for 0 indexed ar)
        }
        else if(typ==2)
        {
            ll val;
            int j;
            cin>>j>>val;
            update(1,0,n-1,j-1,val);  // remember the -1 with j (0 indexed array)
        }
        else break;
    }

}