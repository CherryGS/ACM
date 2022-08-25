#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&
#define Pi acos(-1)

const int mod = 998244353;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int a, b;
int mp[101][101];


int main() {
    cin >> a >> b;
    --a, --b;
    int i1 = 1;
    for(;i1<=100 && a; i1+=2)
        for(int j=1; j<=100&&a; j+=2)
            mp[i1][j] = 1, --a;
    for(int i= i1+2; i<=100; i++)
        for(int j=1; j<=100; j++)
            mp[i][j] = 1;
    for(int i=i1+3; i<=100&&b; i+=2)
        for(int j=1; j<=100&&b; j+=2)
            mp[i][j] = 0, --b;
    cout << 100 << ' ' << 100 << endl;
    for(int i=1; i<=100; i++) {
        for(int j=1; j<=100; j++)
            if(!mp[i][j]) cout << '#';
            else cout << '.';
        cout << endl;
    }
    return 0;
}