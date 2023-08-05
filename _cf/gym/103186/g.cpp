#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;
typedef pair<int, int> pii;

const int mod = 998244353;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n;
ll a[1001000];
ll s1[100100];
ll s2[100100];
ll ksm(ll bs, int x) {
    ll ans = 1;
    while(x) {
        if(x&1) ans = ans * bs % mod;
        bs = bs * bs % mod;
        x >>= 1;
    }
    return ans;
}

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    s1[0] = 1;
    s2[n+1] = 1;
    for(int i=1; i<=n; i++) s1[i] = s1[i-1] * a[i] % mod;
    for(int i=n; i>=1; i--) s2[i] = s2[i+1] * a[i] % mod;
    for(int i=1; i<=n; i++) {
        cout << s1[i-1] * s2[i+1] % mod << ' ';
    }
    cout << endl;
    return 0;
}