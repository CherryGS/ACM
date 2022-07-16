// nlogn
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
bool vis[1000010];
vector<int> q;

void init() {
    q.push_back(2);
    for(int i=3; i<=1000000; i+=2) {
        if(vis[i]) { continue; }
        q.push_back(i);
        for(int j=3; i*j <= 1000000; j+=2) {
            vis[i*j] = 1;
        }
    }
}

int main() {
    // freopen("1.in", "r", stdin);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    init();
    cin >> n;
    if(n == 1) { cout << -1 << '\n'; return 0;}
    int mx = -1;
    for(int i=q.size()-1; i >= 0; i--) {
        if((n % q[i]) == 0 && n != q[i]) { mx = q[i]; break; }
    }
    if(mx == -1) { cout << n << '\n'; return 0; }
    // cout << mx << endl;
    int ans = n+1;
    for(auto &k: q) {
        for(int j=2; k*j < n; j++) {
            if(n-mx+1 <= k*j) {
                // cout << k << ' ' << k*(j-1)+1 << endl;
                ans = min(ans, k*(j-1)+1);
            }
        }
    }
    if(ans > n) { cout << -1 << '\n'; }
    else { cout << ans << '\n'; }
    return 0;
}