#include <bits/stdc++.h>
using namespace std;

// Finds all primes from 1 to n
// After calculation primes vector contains all the prime numbers in range [1,n]
void sieve(vector<long long> &primes, long long n) 
{
    vector<long long> helpr(n+1,1);

    helpr[0]=0;
    helpr[1]=0;

    for(long long i = 2; i<=n; i++)
    {
        if(helpr[i]==1)
        {
            primes.push_back(i);
            for(long long j=i*i;j<=n;j+=i) helpr[j]=0;
        }
    }

    return;
}

int main()
{
    long long n;
    cin>>n;
    vector<long long> primes;
    sieve(primes,n);
    for(auto i:primes) cout<<i<<" ";
    return 0;
}