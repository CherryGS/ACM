// n^3 log(1e8)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n;
ll q;

int mp1[101][101];
int mp2[101][101];
int mp[101][101];

bool check(int x) {
    memset(mp, 0x3f, sizeof mp);
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=i; j++) {
            int ds = (x/n)*2 + (x%n >= i) + (x%n >= j);
            mp[i][j] = max(mp2[i][j], mp1[i][j] - ds);
        }
    }
    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<i; j++) {
                mp[i][j] = min(mp[i][j], mp[i][k] + mp[k][j]);
            }
        }
    }
    ll sum = 0;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=i; j++) {
            sum += mp[i][j];
        }
    }
    // cout << x << ' ' << sum << endl;
    return sum*2 <= q;
}

int main() {
    // freopen("1.in", "r", stdin);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> mp1[i][j];
        }
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> mp2[i][j];
        }
    }
    int l = 0, r = 10000001, mid;
    while(l < r) {
        mid = l + ((r-l) >> 1);
        if(check(mid)) { r = mid - 1; }
        else { l = mid + 1; }
    }
    if(l == 10000001) { cout << -1 << '\n'; }
    else { cout << l << '\n'; }
}