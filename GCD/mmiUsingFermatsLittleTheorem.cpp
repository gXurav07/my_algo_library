#include <iostream>
using namespace std;

/*
According to Fermat's Little theorem if,
1) p is a prime number, and 
2) N is coprime to p

then (N^(p-1))%p = 1
=> (N.N^(p-2))%p = 1;
Therefore,
     N^(p-2) is a valid Modular Multiplicative inverse of N wrt p
*/

template <typename T>
T powr(T a, T b, T p){ // calculates (a^b)%p
    if(b==0) return 1;
    T y = powr(a,b/2,p);
    
    if(b%2) return (a*((y*y)%p))%p;
    else return (y*y)%p;

}
template <typename T>
T mmi(T N, T p){      
    return powr(N,p-2,p);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        long long a, m;
        cin>>a>>m;
        cout<<mmi(a,m)<<endl;
    }
    return 0;
}
