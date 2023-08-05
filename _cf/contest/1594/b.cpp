#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;
typedef pair<int, int> pii;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int t;
ll n, k;

ll ksm(ll pre, int x) {
    ll ans = 0;
    ll bs = 1;
    while(x) {
        if(x&1) ans = (ans + bs) % mod;
        bs = bs*pre % mod;
        x >>= 1;
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