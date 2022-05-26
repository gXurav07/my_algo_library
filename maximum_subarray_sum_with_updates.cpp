  //  SUM QUERY + POINT UPDATE
#include <bits/stdc++.h>

using namespace std;

#define fr(i,n) for(int i=1;i<=n;i++)
#define fo(i,n) for(int i=0;i<n;i++)
#define inf 9223372036854775807
typedef long long ll;


vector<ll> tree[(int)4e5+1]; // Assuming n<= 2.10^5
// < max sum seg >    < sum >    < max prefix sum >     < max suffix sum >

void build(int i, int l, int r, vector<ll> &ar)
{
    tree[i].assign(4,0);
    if(l==r){
        tree[i][0]=max((ll)0,ar[l]);
        tree[i][1]=ar[l];
        tree[i][2]=max((ll)0,ar[l]);
        tree[i][3]=max((ll)0,ar[l]);
        return;
    }

    int mid= (l+r)/2;
    build(2*i,l,mid,ar);
    build(2*i+1,mid+1,r,ar);
    tree[i][1]=tree[2*i][1]+tree[2*i+1][1];
    tree[i][2]= max(tree[2*i][2],tree[2*i][1]+tree[2*i+1][2]);
    tree[i][3]= max(tree[2*i+1][3],tree[2*i+1][1]+tree[2*i][3]);
    tree[i][0]=max(tree[2*i][3]+tree[2*i+1][2],max(tree[2*i][0],tree[2*i+1][0]));

    return;

}


vector<ll> query(int i, int l , int r, int a, int b) // query asked for subarray from a to b
{
    if((a>r)||(b<l)) return {0,0,0,0};
    if((a<=l)&&(r<=b)) return tree[i];

    int mid=(l+r)/2;
    vector<ll> ans1,ans2,ans(4);

    ans1 = query(2*i,l,mid,a,b);
    ans2= query(2*i+1,mid+1,r,a,b);

    ans[1]=ans1[1]+ans2[1];
    ans[2]= max(ans1[2],ans1[1]+ans2[2]);
    ans[3]= max(ans2[3],ans2[1]+ans1[3]);

    ans[0]=max(ans1[3]+ans2[2],max(ans1[0],ans2[0]));

    return ans;
    
}

void update(int i, int l, int r, int j, ll val) // update jth element to be val
{
    if((j<l)||(j>r)) return;

    if((l==j)&&(r==j)) 
    {
        tree[i]={max((ll)0,val),val,max((ll)0,val),max((ll)0,val)};
        return;
    }
    int mid=(l+r)/2;

    update(2*i,l,mid,j,val);
    update(2*i+1,mid+1,r,j,val);

    tree[i][1]=tree[2*i][1]+tree[2*i+1][1];
    tree[i][2]= max(tree[2*i][2],tree[2*i][1]+tree[2*i+1][2]);
    tree[i][3]= max(tree[2*i+1][3],tree[2*i+1][1]+tree[2*i][3]);
    tree[i][0]=max(tree[2*i][3]+tree[2*i+1][2],max(tree[2*i][0],tree[2*i+1][0]));
    return;

}

int main()
{
    int n,q;
    cin>>n>>q;

    vector<ll> ar(n);
    fo(i,n) cin>>ar[i];

  
    build(1,0,n-1,ar);


    cout<<query(1,0,n-1,0,n-1)[0]<<endl;
    fo(i,q)
    {
        ll val;
        int j;
        cin>>j>>val;
        update(1,0,n-1,j,val);  // remember the -1 with j (0 indexed array)
        cout<<query(1,0,n-1,0,n-1)[0]<<endl;
        
    }



}