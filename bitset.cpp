#include <iostream>
#include <bitset>   

using namespace std;


int main(){
    bitset<10> b;
    cout<<b<<endl;

    b[1]=1;
    cout<<b<<endl;

    b.set(3);
    cout<<b<<endl;

    b = (b<<2);
    cout<<b<<endl;

    b = (b|bitset<10>("00110"));
    cout<<b<<endl;

    b.set(3,0);
    cout<<b<<endl;

    b.flip();
    cout<<b<<endl;

    b.reset();
    cout<<b<<endl;

}