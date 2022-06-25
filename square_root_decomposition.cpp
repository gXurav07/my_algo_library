#include <bits/stdc++.h>

using namespace std;

#define INITIAL_VALUE 0

template<typename T>
T operation(T a, T b){
    return a+b;
}

template<typename T>
void build(int n, vector<T> &A, vector<T> &B){
    int sq = sqrt(n);
    B.assign(ceil(n/(sq*1.0)),(T)INITIAL_VALUE);
    for(int i=0;i<n;++i){
        B[i/sq]=operation(B[i/sq],A[i]);
    }
    return;
}

template<typename T>
T query(int n,int l, int r, vector<T> &A, vector<T> &B){
    --l; --r;  // if l and r are given in 1 based index
    int sq = sqrt(n);

    T s=INITIAL_VALUE;
    while(l<=r){
        if((l%sq==0)&&((l+sq-1)<=r)){
            s=operation(s,B[l/sq]);
            l+=sq;
        }
        else{
            s=operation(s,A[l]);
            ++l;
        }
        
    }
    return s;

}

// A[i] --- > val
template<typename T>
void update(int n, int i, T val, vector<T> &A, vector<T> &B){
    --i; // for 1 based indexing

    int sq = sqrt(n);
    A[i]=val;

    int k = i/sq;
    B[k]= INITIAL_VALUE;

    int start = (i/sq)*sq;
    for(int j=0;j<sq;++j){
        B[k]=operation(B[k], A[start + j]);
    } 
    return;
}


// Range  sum query ---> all queries and updates in O(√n)
int main(){
    int n;
    cin>>n;
    
    vector<int> A(n),B;
}