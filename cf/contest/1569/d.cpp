#include <bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#define pr1(x) cout << x << ' ';
#define pr2(x) cout << x << endl;
#else
#define pr1(x)
#define pr2(x)
#endif
typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;
typedef pair<int, int> pii;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int t, n, m, k;
int x[200200], y[200200];

int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    while(t--) {
        cin >> n >> m >> k;
        for(int i=1; i<=n; i++) cin >> x[i];
        for(int i=1; i<=m; i++) cin >> y[i];
        int tx, ty;
        vector<int> q1, q2;
        for(int i=1; i<=k; i++) {
            cin >> tx >> ty;
            int id1 = lower_bound(x+1, x+1+n, tx) - x;
            int id2 = lower_bound(y+1, y+1+m, ty) - y;
            if((x[id1] == tx || id2 > m) ^ (y[id2] == ty || id1 > n)) {
                if(x[id1] == tx) q1.push_back(ty);
                else q2.push_back(tx);
            }
        }
        sort(q1.begin(), q1.end());
        sort(q2.begin(), q2.end());
        deque<int> r;
        int id = 0;
        ll ans = 0;
        x[0] = -1;
        y[0] = -1;
        for(int i: q1) {
            while(y[id] < i && id <= m) ++ id;
            -- id;
            while(!r.empty() && r.front() <= y[id]) r.pop_front();
            ans += r.size();
            r.push_back(i);
        }
        id = 0;
        while(!r.empty()) r.pop_back();
        for(int i: q2) {
            while(x[id] < i && id <= n) ++ id;
            -- id;
            while(!r.empty() && r.front() <= x[id]) r.pop_front();
            ans += r.size();
            r.push_back(i);
        }
        cout << ans << endl;
    }
    return 0;
}