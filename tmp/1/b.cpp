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

int n = 8;
char s[10];
const char*r = "cocacola";
int ans = 0;

const int mx_n = 1;
ll inv[mx_n];
ll fac[mx_n];
ll ksm(ll m, int c) {
    ll ans = 1;
    while(c) {
        if(c&1) ans = (ans*m) % mod;
        c >>= 1;
        m = (m*m) % mod;
    }
    return ans;
}
void sol_inv() {
    fac[0] = 1;
    for(int i=1; i<=mx_n; i++) fac[i] = fac[i-1] * i % mod;
    inv[mx_n] = ksm(fac[mx_n], mod-2);
    for(int i=mx_n-1; i; i--) inv[i] = inv[i+1] * (i+1) % mod;
}

int main() {
    cin >> s;
    for(int i=0; i<n; i++) {
        if(r[i] != s[i]) {
            for(int j=i+1; j<n; j++)
                if(r[i] == s[j] && s[j] != r[j]) {
                    swap(s[i], s[j]), ++ans;
                    break;
                }
        }
    }
    cout << ans << endl;
    return 0;
}
/*
alocacoc
*/