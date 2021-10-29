#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef const ll& cint;
typedef pair<ll, ll> pii;

const double ept = 1e-9;

ll n, m, x;
ll t;
ll s[100100];
map<ll, ll> e;
map<ll, ll> ee;
ll cnt;
vector<pii> to[100100];

bool cmp(pii&a, pii&b) { return a.first == b.first ? a.second < b.second : a.first < b.first; }
bool cmp2(pii&a, pii&b) { return a.first < b.first; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--) {
        e.clear();
        ee.clear();
        while(cnt) { to[cnt].clear(); --cnt; }
        cin >> n >> m;
        bool flag = 0;
        for(ll i=1; i<=n; i++) { cin >> s[i]; }
        for(ll i=1; i<=n; i++) { s[i] += s[i-1]; }
        if(s[n] == 0) {
            for(ll i=1; i<=n; i++) { if(e.find(s[i]) == e.end()) e[s[i]] = i; }
            ll x;
            for(ll i=1; i<=m; i++) {
                cin >> x;
                if(x == 0) cout << 0 << '\n';
                else if(e.find(x) == e.end()) cout << -1 << '\n';
                else cout << e[x] << '\n';
            }
        }
        else {
            if(s[n] < 0) { for(ll i=1; i<=n; i++) s[i] = -s[i]; flag = 1; }
            for(ll i=1; i<=n; i++) {
                ll k = s[i] / s[n];
                ll c = s[i] - k * s[n];
                if(c < 0) { ++k; c += s[n]; }
                if(e.find(c) == e.end()) e[c] = ++cnt;
                to[e[c]].push_back( {k, i} );
                // cout << i << ' ' << s[i] << ' ' << k << ' ' << c << '\n';
            }
            for(ll i=1; i<=cnt; i++) { sort(to[i].begin(), to[i].end(), cmp); }
            for(ll i=1; i<=m; i++) {
                cin >> x;
                if(x == 0) { cout << 0 << '\n'; continue; }
                if(flag) x = -x;
                ll k = x / s[n];
                ll c = x - k * s[n];
                if(c < 0) { ++k; c += s[n]; }
                // cout << i << ' ' << x << ' ' << k << ' ' << c << '\n';
                if(e.find(c) == e.end()) { cout << -1 << '\n'; continue; }
                ll rr = e[c];
                ll l = 0, r = to[rr].size()-1, mid;
                pii st = {k, 0};
                while(l < r) {
                    // cout << l << " ---- " << r << '\n';
                    mid = l + (r-l+1)/2;
                    if(cmp2(st, to[rr][mid])) r = mid-1;
                    else l = mid;
                    // cout << st.first << ' ' << to[rr][mid].first << " --- " << cmp2(st, to[rr][mid]) << endl;
                }
                // cout << rr << ' ' << to[rr].size() << ' ' << l << ' ' << to[rr][mid].first << ' ' << to[rr][mid].second << '\n';
                if(l >= to[rr].size() || to[rr][l].first > k) cout << -1 << '\n';
                else cout << (k-to[rr][l].first)*n + to[rr][l].second << '\n';
            }
        }
    }
    return 0;
}
/*
1
3 1
1 -3 4
2
*/