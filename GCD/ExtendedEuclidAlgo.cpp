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


int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        int x,y;
        tie(x,y) = extEuclid(a,b);
        cout<<x<<" "<<y<<endl<<flush;
    }
    return 0;
}
