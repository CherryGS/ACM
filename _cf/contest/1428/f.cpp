#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n;
char s[1001000];
int st_l[22][500050];
int st_r[22][500050];

int fdl(int loc, cint lim) {
    if(loc == 0) return 1;
    for(int j=21; j>=0; j--) {
        int r = max(1, loc-(1<<j));
        if(st_r[j][loc] < lim) loc = r-1;
        // cout << loc << "---" << endl;
    }
    return loc+1;
}

int fdr(int loc, cint lim) {
    if(loc == n+1) return n;
    for(int j=21; j>=0; j--) {
        int r = min(n, loc+(1<<j));
        if(st_l[j][loc] <= lim) loc = r+1;
    }
    return loc-1;
}

ll cacu(ll x) {
    return x*(x+1)/2*x - x*(x+1)*(x*2+1)/6 + (x+1)*x/2;
}

int main() {
    cin >> n;
    cin >> s;
    for(int i=1; i<=n; i++) {
        if(s[i-1] == '1') {
            st_l[0][i] = st_l[0][i-1]+1;
        }
    }
    for(int i=n; i>=1; i--) {
        if(s[i-1] == '1') {
            st_r[0][i] = st_r[0][i+1]+1;
        }
    }
    for(int j=1; j<=21; j++) {
        for(int i=1; i<=n; i++) {
            int r = min(n, i+(1<<(j-1)));
            st_l[j][i] = max(st_l[j-1][i], st_l[j-1][r]);
        }
        for(int i=n; i>=1; i--) {
            int r = max(1, i-(1<<(j-1)));
            st_r[j][i] = max(st_r[j-1][i], st_r[j-1][r]);
        }
    }
    ll ans = 0;
    for(ll i=1; i<=n; i++) if(s[i-1] == '1'){
        if(st_l[0][i] == 1) {
            ll l = fdl(i-st_l[0][i], st_r[0][i]);
            ll r = fdr(i+st_r[0][i], st_r[0][i]);
            ans += (i-l)*(r-i-st_r[0][i]+1)*st_r[0][i];
            ans += cacu(st_r[0][i]);
        }
        ll l = fdl(i-st_l[0][i], st_l[0][i]);
        ll r = fdr(i+st_r[0][i], st_r[0][i]);
        ans += (i-l-st_l[0][i]+1)*st_l[0][i];
        ans += (r-(i+st_r[0][i])+1)*st_r[0][i];
        cout << i << ' ' << l << ' ' << r << ' ' << st_l[0][i] << ' ' << st_r[0][i] << ' ' << (i-l-st_l[0][i]+1)*st_l[0][i] << ' ' << (r-(i+st_r[0][i])+1)*st_r[0][i] << endl;
    }
    // cout << cacu(1) << endl;
    cout << ans << endl;
    return 0;
}