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

int r1, c1, r2, c2;

int main() {
    cin >> r1 >> c1 >> r2 >> c2;
    if(r1+c1==r2+c2) cout << 1 << endl;
    else if(r1-c1==r2-c2) cout << 1 << endl;
    else if(abs(r1-r2)+abs(c1-c2)<=3) cout << 1 << endl;
    else if(!(abs(r1+c1-r2-c2)&1) || !(abs(r1-c1-r2+c2)&1)) cout << 2 << endl;
    else if()
    else cout << 3 << endl;
    return 0;
}