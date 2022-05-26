#include <bits/stdc++.h>
using namespace std;


int dnqsolve(vector<int> &v, int n)  // O(nlog(n))
{
    if(n==1) return v[0];
    vector<int> v1(v.begin(),v.begin()+n/2),v2(v.begin()+n/2,v.end());
    int a= dnqsolve(v1,n/2), b= dnqsolve(v2,n-n/2);
    int x = max(a,b),s=0;
    a=v[n/2-1];
    b=v[n/2];
    for(int i=n/2-1;i>=0;i--)
    {
    s+=v[i];
    a = max(a,s);
    }
    s=0;
    for(int i=n/2;i<n;i++)
    {
    s+=v[i];
    b = max(b,s);
    }
    return max(x,a+b);

}

int dpsolve(vector<int> &v)  // O(n)
{
    int n = v.size();
    int ans=v[0],s=0;
    for(int i=0;i<n;i++)
    {
        s+=v[i];
        ans =max(ans,s);
        s=max(s,0);
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];

    cout<<dnqsolve(v, n)<<" "<<dpsolve(v)<<endl;

    return 0;
}

