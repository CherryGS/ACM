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

ll n, w;
ll a[200200];

int main() {
    cin >> n >> w;
    ll aa, bb, pp;
    for(int i=1; i<=n; i++) {
        cin >> aa >> bb >> pp;
        a[aa] += pp;
        a[bb] -= pp;
    }
    ll tmp = 0;
    for(int i=0; i<=200000; i++) {
        tmp += a[i];
        if(tmp > w) {
            cout << "No";
            break;
        }
        if(i==n) {
            cout << "Yes";
        }
    }
    return 0;
}