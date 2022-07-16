#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int n, m, q;
bool mp[2][100010];

int main() {
    cin >> n >> m >> q;
    int sum = 0;
    int t, c;
    int now = 0;
    ll ans = 0;
    for(int i=1; i<=q; i++) {
        cin >> t >> c;
        if(!mp[t][c]) { mp[t][c] = 1; }
        else { continue; }
        if(t == 0) {
            ans += m;
            ++sum;
        }
        else {
            ++now;
        }
    }
    cout << 1ll * n * m - ans - 1ll * now * n + 1ll * sum * now << endl;
}