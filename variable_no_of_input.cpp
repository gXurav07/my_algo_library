
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int k;
    string st;
    //cin.ignore();   Use sometimes
    for(int j=0;j<3;j++)  // 10 lines input. each line has variable number of space-separated integers
    {
        getline(cin,st,'\n');
        istringstream s(st);
        while(s>>k) { cout<<k*k<<endl; }
        s.clear();
    }
    return 0;
}