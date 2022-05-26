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
    map<int, int> mp;
  
    // insert elements in random order
    mp.insert({ 2, 30 });
    mp.insert({ 1, 40 });
    mp.insert({ 3, 60 });
    mp.insert({ 9, 20 });
    mp.insert({ 5, 50 });
    cout<<mp.count(1);

    for ( auto itr = mp.begin(); itr != mp.end(); ++itr) {
        cout << '\t' << itr->first << '\t' << itr->second
             << '\n';
    }
    return 0;
}