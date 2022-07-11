#include <iostream>
#include <tuple> 
using namespace std;


// finds X and Y for the eqn Xa + Yb = gcd(a,b)
template <typename T>
pair<T,T> extEuclid(T a, T b){ 
    if(b==0){
        return make_pair(1,0); // Base Case
    }

    T x1,y1;
    tie(x1,y1) = extEuclid(b,a%b);

    T X = y1, Y = x1 - (a/b)*y1;
    return make_pair(X,Y);
}

// Inverse exists only if gcd(a,m) = 1
template <typename T>
T mmi(T a, T m){
    T X;
    tie(X,ignore) = extEuclid(a,m);
    return (X+m)%m; 
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


/*
Modular Muliplicative Inverse of a number a  w.r.t. m is 
another number b such that (a.b)%m = 1

NOTICE: 
if m is prime and a<m then gcd(a,m) = 1 
=> X.a + Y.m = 1 has integral solutions for X and Y
Now, taking modulus of the expression on both sides w.r.t. m we get:-
    (X.a + Y.b)%m = 1%m
=>   (X.a)%m = 1
Therefore, X is a valid Modular Muliplicative Inverse of a number a  w.r.t. m 


If b is mmi of a wrt m
then b%m is also mmi of a wrt a
*/