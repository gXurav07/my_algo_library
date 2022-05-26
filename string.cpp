#include <bits/stdc++.h>

using namespace std;


#define fo(i,n) for(int i=0;i<n;i++)
#define fro(i,n) for(int i=0;i<=n;i++)
#define fr(i,n) for(int i=1;i<=n;i++)
#define f(i,l,r) for(int i=l;i<r;i++)

typedef long long ll;

void print(){cout<<'\n';}
template<typename T, typename ...TAIL>
void print(const T &t, TAIL... tail)
{
    cout<<t<<' ';
    print(tail...);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string st2 = R"(Geeks.\nFor.\nGeeks.\n)", st = st2.substr(2);
    cout<<st2<<" \n"<<st;
}