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

ll s, p;

int main() {
    cin >> s >> p;
    int ans=0;
    for(ll i=1; i <= sqrt(p); i++)
        if((s-i)*i == p) ans += 2;
    if(ans) cout << "Yes";
    else cout << "No";
    return 0;
}