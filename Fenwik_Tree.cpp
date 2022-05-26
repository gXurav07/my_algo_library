// RANGE SUM QUERY + POINT UPDATES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// -x = 2's complement of x = ( x with inverted bits) + 1
int lsb(int x) { return (x&(-x));} 

# define max_size 1000007
ll ftar[max_size];

ll query(int idx) // O(logN)
{
    ll ans=0;
    while(idx>0)
    {
        ans+=ftar[idx];
        idx-=lsb(idx);

    }
    return ans;

}

// Update operation:- adding val to idx th inder of the array
void update(int idx, ll val, int n) // O(logN)
{
    while(idx<=n)
    {
        ftar[idx]+=val;
        idx+=lsb(idx);
    }
    return;

}


int main()
{
    int n,q,typ,l,r,t;
    ll val; 
    cin>>t;
    while(t--)
    {
        cin>>n>>q;

        for(int i=0;i<=n;i++) ftar[i]=0;

        for(int i=1;i<=n;i++) { cin>>val; update(i,val,n);}



        for(int i=0;i<q;i++)
        {
            cin>>typ;
            if(typ==1){ cin>>l>>r; cout<<(query(r)-query(l-1))<<endl;}
            else { cin>>l>>val; update(l,val,n);}
        }
    }

    return 0;




}