#include <bits/stdc++.h>
using namespace std;


// Finds all primes in range [l,r]
// After calculation primes vector contains all the prime numbers in range [l,r]
void segsieve(vector<long long> &primes, long long l, long long r) 
{
    long long sr = (long long)sqrt(r);
    vector<long long> helpr2(r-l+1,1), helpr1(sr+1,1);

    helpr1[0]=0;
    helpr1[1]=0;

    for(long long i = 2; i<=sr; i++)
    {
        if(helpr1[i]==1)
        {
            for(long long k=max((long long)(i*ceil(l/(i*1.0))),(long long)i*2);k<=r;k+=i) helpr2[k-l]=0;
            
            for(long long j=i*i;j<=sr;j+=i) helpr1[j]=0;


        }
    }
    for(long long i = l; i<=r; i++)
    {
        if(helpr2[i-l]) { primes.push_back(i); }
  
    }


    return;
}

int main()
{
    long long l,r;
    cin>>l>>r;  // l,r <= 10^11 but r-l is <= 10^6
    vector<long long> primes;
    segsieve(primes,l,r);

    for(auto i:primes) cout<<i<<" ";
    cout<<endl;

    return 0;
}