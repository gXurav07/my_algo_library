 //  SUM QUERY + POINT UPDATE
#include <bits/stdc++.h>

using namespace std;

#define fr(i,n) for(int i=1;i<=n;i++)
#define fo(i,n) for(int i=0;i<n;i++)
#define inf 9223372036854775807
typedef long long ll;


ll tree[(int)8e5+1]; // Assuming n<= 2.10^5
int num[(int)8e5+1];

void build(int i, int l, int r, vector<ll> &ar)
{
    if(l==r){
        tree[i]=ar[l];
        num[i]=1;
        return;
    }

    int mid= (l+r)/2;
    build(2*i,l,mid,ar);
    build(2*i+1,mid+1,r,ar);
    tree[i] = min(tree[2*i],tree[2*i +1]);  // For sum queries
    num[i]=0;
    if(tree[i]==tree[2*i]) num[i]+=num[2*i];
    if(tree[i]==tree[2*i+1]) num[i]+=num[2*i+1];
    return;
}


vector<ll> query(int i, int l , int r, int a, int b) // query asked for subarray from a to b
{
    if((a>r)||(b<l)) return {inf,0};
    if((a<=l)&&(r<=b)) return {tree[i],num[i]};

    int mid=(l+r)/2;
    vector<ll> ans1,ans2,ans(2);

    ans1 = query(2*i,l,mid,a,b);
    ans2= query(2*i+1,mid+1,r,a,b);

    ans[0]=min(ans1[0],ans2[0]);
    ans[1]=0;
    if(ans1[0]==ans[0]) ans[1]+=ans1[1];
    if(ans2[0]==ans[0]) ans[1]+=ans2[1];
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
    tree[i] = min(tree[2*i] ,tree[2*i +1]);
    num[i]=0;
    if(tree[i]==tree[2*i]) num[i]+=num[2*i];
    if(tree[i]==tree[2*i+1]) num[i]+=num[2*i+1];
    return;

}

int main()
{
    int n,q;
    cin>>n>>q;
    vector<ll> ar(n);
    fo(i,n) cin>>ar[i];

    build(1,0,n-1,ar);


    int typ;

    fo(i,q)
    {
        cin>>typ;
        if(typ==2)
        {
            int a,b; 
            cin>>a>>b; 
            vector<ll> ans = query(1,0,n-1,a,b-1); // remember the -1 with a and b ( for 0 indexed ar)
            cout<<ans[0]<<" "<<ans[1]<<endl;
        }
        else if(typ==1)
        {
            ll val;
            int j;
            cin>>j>>val;
            update(1,0,n-1,j,val);  // remember the -1 with j (0 indexed array)
        }
    }



}