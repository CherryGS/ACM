#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

typedef pair<int, int> pii;
int n;
ll c[1001];
map<ll, ll> e;

ll cacu(ll x) {
    return (x+1)*x/2;
}

int main() {
    cin >> n;
    for(int i=1; i<=n; i++) cin >> c[i];
    ll ans = 0;
    // stack<pii> e;
    ll s = 0;
    for(int i=1; i<=n; i++) {
        ll r = c[i];
        if(i&1) {
            s += r;
        }
        else {
            if(e.find(s) != e.end())
            e.erase(e.find(s));
            for(auto k : e) {
                if(k.first > s-r) {
                    ans += cacu(k.second+1) - cacu(k.second);
                }
            }
            s -= r;
            if(s >= 0) e[s]++;
            if(s < 0) e.clear();
        }
    }
    cout << ans << endl;
    return 0;
}