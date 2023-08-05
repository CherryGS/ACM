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

struct node {
    int x, y;
    void init() { cin >> x >> y; }
};

int t, n, b;
int c[101];
int st = 1001, ed = 1002;
node sta[1010];
int dis[101][1011];

int h[1010], nx[200200], to[200200], w[200200], cnt;

void add(cint f, cint t, cint co) {
    nx[++cnt] = h[f];
    h[f] = cnt;
    to[cnt] = t;
    w[cnt] = co;
}

int cacu(const node&a, const node&b) {
    return ceil(sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2)));
}

void dij() {
    queue<pii> q;
    memset(dis, 0x3f, sizeof dis);
    dis[0][st] = 0;
    q.push( {0, st} );
    while(!q.empty()) {
        int id = q.front().second;
        int val = q.front().first;
        q.pop();
        for(int i=h[id]; i; i=nx[i]) {
            int r = cacu(sta[id], sta[to[i]]) + val;
            if(r <= b && dis[r][to[i]] > dis[val][id] + w[i]) {
                dis[r][to[i]] = dis[val][id] + w[i];
                q.push( {r, to[i]} );
            }
        }
    }
}

int main() {
    sta[st].init();
    sta[ed].init();
    cin >> b >> c[0] >> t;
    for(int i=1; i<=t; i++) cin >> c[i];
    cin >> n;
    for(int i=1; i<=n; i++) {
        sta[i].init();
        int tmp;
        cin >> tmp;
        int a, b;
        for(int j=1; j<=tmp; j++) {
            cin >> a >> b;
            ++a;
            add(i, a, c[b]);
            add(a, i, c[b]);
        }
    }
    for(int i=1; i<=n; i++) {
        for(int j=h[i]; j; j=nx[j]) {
            w[j] *= cacu(sta[i], sta[to[j]]);
        }
    }

    add(st, ed, c[0] * cacu(sta[st], sta[ed]));
    for(int i=1; i<=n; i++) {
        add(st, i, c[0] * cacu(sta[st], sta[i]));
        add(i, ed, c[0] * cacu(sta[i], sta[ed]));
    }

    // for(int i=h[st]; i; i=nx[i]) {
    //     cout << st << ' ' << to[i] << " ----- " << w[i] << endl;
    // }
    dij();
    int ans = hf_int;
    for(int i=0; i<=b; i++) { 
        ans = min(ans, dis[i][ed]);
    }
    if(ans >= hf_int) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}