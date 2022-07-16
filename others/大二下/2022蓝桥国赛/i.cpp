// mn log a
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m;
int ql, qr, qv;
int a[200020], b[200020];
ll sum[200020];
ll sum_a[200020];
ll pre[1000001];

void init() {
    for(int i=1; i<=1000001; i++) {
        pre[i] = (1ll * i * i - i) / 2 + i;
    }
}

ll cacu(int h, int da, int na, bool st) {
    if(st == 1) {
        // zuo di you gao
        if(h >= na) {
            return pre[na] - pre[na-da];
        } else {
            int dx = max(da - (na - h + 1), 0);
            return 1ll * h * da - pre[dx];
        }
    }
    else {
        if(h >= na) {
            return pre[da];
        } else {
            if(da <= h) {
                return pre[da];
            }
            else {
                return 1ll * da * h - pre[h-1];
            }
        } 
    }
}

bool check(int x) {
    int le = lower_bound(sum_a+1, sum_a+n, ql) - sum_a + 1;
    int ri = lower_bound(sum_a+1, sum_a+n, qr+1) - sum_a - 1;
    if(le - ri == 2) {
        // cout << le << " ----- " << ri << ' ' << x << endl;
        // cout << cacu(x, sum_a[le-1] - ql + 1, a[le-1], b[le-1]^1) << " - - " << cacu(x, sum_a[le-1] - qr + 1, a[le-1], b[le-1]) << endl; 
        return (cacu(x, sum_a[le-1] - ql + 1, a[le-1], b[le-1]^1) \
            - cacu(x, sum_a[le-1] - qr + 1, a[le-1], b[le-1])) >= qv;
    }
    ll ans1 = 0, ans2 = 0, ans3 = 0;
    for(int i=le; i<=ri; i++) {
        ans1 += pre[a[i]];
        if(a[i] > x) { ans1 -= pre[a[i]-x]; }
    }
    if(ql <= sum_a[le-1]) {
        ans2 += cacu(x, sum_a[le-1]-ql+1, a[le-1], b[le-1]^1);
    }
    if(qr > sum_a[ri]) {
        ans3 += cacu(x, qr-sum_a[ri], a[ri+1], b[ri+1]);
    }
    ll ans = ans1 + ans2 + ans3;
    // cout << ans1 << ' ' << ans2 << ' ' << ans3 << endl;
    // cout << ans << ' ' << x << ' ' << le << ' ' << ri << ' ' << sum_a[le-1] << ' ' << sum_a[ri] << endl;
    return ans >= qv;
}

int main() {
    //freopen("1.in", "r", stdin);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    init();
    for(int i=1; i<=n; i++) { cin >> a[i] >> b[i]; }
    for(int i=1; i<=n; i++) {
        sum[i] = sum[i-1] + pre[a[i]];
        sum_a[i] = sum_a[i-1] + a[i];
    }
    for(int i=1; i<=m; i++) {
        cin >> ql >> qr >> qv;
        int l = 0, r = 1e6+1, mid;
        while(l < r) {
            mid = l + ((r-l) >> 1);
            // cout << l << " --- " << r << endl;
            if(check(mid)) { r = mid; }
            else { l = mid + 1; }
        }
        if(r == 1e6+1) { cout << -1 << '\n'; }
        else { cout << r << '\n'; }
    }
    return 0;
}