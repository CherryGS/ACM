#include <bits/stdc++.h>
using namespace std;

std::mt19937 rng(std::random_device{}());
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;
typedef pair<int, int> pii;
typedef const ll& cll;

#define ls (loc<<1)
#define rs ((loc<<1)|1)

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n;
int a[1001000];
int r[1001000];
ll rr[1001000];
char s[1001000];

int gcd(cint x, cint y) {
    return y == 0 ? x : gcd(y, x%y);
}

int cacu(cint loc, ll w, cint st) {
    if(loc >= n) { rr[st] = w; return n; }
    if(r[loc] > loc) return cacu(r[loc], w*rr[loc], st);
    for(int i=loc; i<=n; i++) {
        // cout << i << ' ' << loc << ' ' << n << ' ' << st << ' ' << endl;
        if(s[i-1] == '*') {
            if(i == r[i]) { return cacu(i+1, w, st); }
            return cacu(r[i], w*rr[i], st);
        }
        else{
            if(w%a[i]) {
                rr[st] = w;
                return i-1;
            }
            w /= a[i];
        }
        if(loc == n) { rr[st] = w; return n; }
    }
    return 0;
}

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    cin >> s;
    for(int i=1; i<=n; i++) rr[i] = 1;
    for(int i=n; i>=1; i--) {
        if(s[i-1] == '*') {
            r[i] = cacu(i+1, a[i], i);
        }
        else {
            if(a[i] == 1) r[i] = cacu(i+1, 1, i);
        }
    }
    ll ans = 0;
    for(int i=1; i<=n; i++) {
        // cout << r[i] << endl;
        if(r[i] >= i) ans += r[i]-i+1;
    }
    cout << ans << endl;
    return 0;
}
/*
5
1 1 1 1 1
/////
*/