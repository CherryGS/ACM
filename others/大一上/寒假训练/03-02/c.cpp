#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&
#define Pi acos(-1)

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

ll q;
ll n;
bool flag;

ll check(ll x) {
    ll num = 0;
    while(x) {
        if(!(x&1)) flag = 1;
        ++num;
        x >>= 1;
    }
    return num;
}

int main() {
    cin >> q;
    while(q--) {
        flag = 0;
        cin >> n;
        ll r = check(n);
        if(flag) {
            cout << (1<<r) - 1 << endl;
        } else {
            cout << (1<<(r-1)) - 1 << endl;
        }
    }
    return 0;
}