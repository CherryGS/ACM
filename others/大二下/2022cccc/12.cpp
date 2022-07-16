#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

typedef pair<ll, ll> pii;
ll n;
ll mp[505][505];
bool sex[505];
char s[50050];
ll ans[505];

pii sol(char s[]) {
    ll s1 = 0;
    ll id = 0;
    ll len = strlen(s);
    for(ll i=0; i<len; i++) {
        id = i;
        if(s[i] == ':') { break; }
        s1 = s1 * 10 + s[i] - '0';
    }
    id++;
    ll s2 = 0;
    for(; id<len; id++) {
        s2 = s2 * 10 + s[id] - '0';
    }
    return { s1 , s2 }; 
}

ll dis[505];
bool vis[505];

void dij(ll s) {
    srand(time(0));
    memset(dis, 0x1f, sizeof dis);
    memset(vis, 0, sizeof vis);
    dis[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii> > q;
    q.push({0, s});
    while(!q.empty()) {
        auto k = q.top();
        q.pop();
        if(vis[k.second]) { continue; }
        vis[k.second] = 1;
        for(ll i=1; i<=n; i++) {
            if(i != k.second) {
                if(dis[i] > dis[k.second] + mp[k.second][i]) {
                    dis[i] = dis[k.second] + mp[k.second][i];
                    q.push({dis[i], i});
                }
            }
        }
    }
}

ll cmp(const ll&x, const ll&y) {
    return ans[x] == ans[y] ? x < y : ans[x] < ans[y];
}

signed main() {
    freopen("1.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin >> n;
    char ch;
    ll sum;
    memset(mp, 0x3f, sizeof mp);
    for(ll i=1; i<=n; i++) {
        cin >> ch >> sum;
        if(ch == 'F') {
            sex[i] = 1;
        }
        for(ll j=1; j<=sum; j++) {
            cin >> s;
            auto k = sol(s);
            mp[i][k.first] = k.second;
        }
    }
    for(ll i=1; i<=n; i++) {
        dij(i);
        // for(ll j=1; j<=n; j++) { cout << dis[j] << ' '; }
        // cout << endl;
        for(ll j=1; j<=n; j++) {
            if(sex[i] != sex[j]) {
                ans[j] = max(ans[j], dis[j]);
            }
        }
    }
    for(int j=1; j<=n; j++) { if(ans[j] == 0) { ans[j] = (1<<31); }}
    vector<ll> id[2];
    for(ll i=1; i<=n; i++) {
        id[sex[i]].push_back(i);
    }
    // cout << endl;
    // for(ll i=1; i<=n; i++) { cout << ans[i] << ' '; }
    // cout << endl;
    sort(id[0].begin(), id[0].end(), cmp);
    sort(id[1].begin(), id[1].end(), cmp);
    for(ll i=0; i<id[1].size(); i++) {
        if(i == 0 || ans[id[1][i-1]] == ans[id[1][i]]) {
            if(i != 0) { cout << ' '; }
            cout << id[1][i];
        }
    }
    cout << endl;
    for(ll i=0; i<id[0].size(); i++) {
        if(i == 0 || ans[id[0][i-1]] == ans[id[0][i]]) {
            if(i != 0) { cout << ' '; }
            cout << id[0][i];
        }
    }
}