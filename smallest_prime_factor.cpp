#include <bits/stdc++.h>
using namespace std;
#define inf 9223372036854775807

// Finds smallest frime factor for all numbers in range [l,r]
void smallest_prime_factor(vector<long long> &spf, long long l, long long r) 
{
    for(long long i=0;i<(r-l+1);i++) spf[i]=i+l;
    long long sr = (long long)sqrt(r);
    vector<long long> helpr1(sr+1,1);

    helpr1[0]=0;
    helpr1[1]=1;

    for(long long i = 2; i<=sr; i++)
    {
        if(helpr1[i]==1)
        {
            for(long long k=(long long)(i*ceil(l/(i*1.0)));k<=r;k+=i) spf[k-l]=min(spf[k-l],i);
            
            for(long long j=i*i;j<=sr;j+=i) helpr1[j]=0;


        }
    }


    return;
}

int main()
{
    long long l,r;
    cin>>l>>r;  // l,r <= 10^11 but r-l is <= 10^6
    vector<long long> spf(r-l+1);  // smallest prime factor of n = spf[n-l]
    smallest_prime_factor(spf,l,r);  

    for(long long i=l;i<=r;i++) cout<<i<<" --> "<<spf[i-l]<<endl;
    cout<<endl;

    return 0;
}