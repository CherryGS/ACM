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
int n;
int a[101];
int sum[2001000];

// const int mx_n = 20000000;
// bool vis[mx_n+1];
// int prim[mx_n+1], cnt;

// void liner_sieve() {
//     int rt = 0;
//     for(int i=2; i<=mx_n; i++) {
//         if(!vis[i]) prim[++cnt] = i;
//         for(int j=1; j<=cnt; j++) {
//             if(1ll*prim[j]*i>mx_n) break;
//             vis[prim[j]*i] = 1;
//             if(!(i%prim[j])) break;
//         }
//     }
// }

bool cacu(cint x) {
    vector<int> q;
    int r;
    bool st = 0;
    for(int i=1; i<=n; i++) {
        r = (a[i]%x+x) % x;
        sum[r]++;
        q.push_back(r);
        if(sum[r] >= n/2) { st = 1; break; }
    }
    for(int i: q) sum[i]--;
    return st;
}

int main() {
    ios::sync_with_stdio(false);
    // liner_sieve();
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i=1; i<=n; i++) cin >> a[i];
        sort(a+1, a+1+n);
        int st = 1, pre = 0;
        int mx = 0;
        for(int i=1; i<=n; i++) {
            mx = max(mx, abs(a[i]));
            if(a[st] != a[i]) {
                pre = max(pre, i-st);
                st = i;
            }
        }
        if(st != n) pre = max(pre, n-st+1);
        if(pre >= n/2) cout << -1 << endl;
        else {
            ll ans = 1;
            for(int i=2; i<=2*mx; i++) {
                for(ll j=i; j<=mx*2; j+=i) {
                    if(cacu(j)) ans = max(ans, j);
                    else break;
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}