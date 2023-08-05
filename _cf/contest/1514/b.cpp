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

int t;
ll n, k;

ll ksm(ll x, ll y) {
    ll ans = 1;
    while(y) {
        if(y&1) ans = (ans*x) % mod;
        x = (x*x) % mod;
        y >>= 1;
    }
    return ans;
}

int main() {
    cin >> t;
    while(t--) {
        cin >> n >> k;
        cout << ksm(n, k) << endl;
    }    
    return 0;
}