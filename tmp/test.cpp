#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;
typedef pair<int, ll> pii;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n, m;
int bcj[505];
bool vis[505];
ll f[505][505];
ll val[505];
int sum[505];
vector<pii> to[505];
int st;
struct edge {
	int u, v;
	ll w;
	bool operator < (const edge&a) const {
		return w < a.w;
	}
	void init() {
		cin >> u >> v >> w;
	}
} a[505*505];

struct node {
	int id;
	ll w;
	bool operator < (const node&a) const {
		return w > a.w;
	}
	void init(cint x) {
		id = x;
		cin >> w;
		val[x] = w;
	}
} b[505];

int fd(cint x) {
	return bcj[x] == x ? x : bcj[x] = fd(bcj[x]);
}

void dfs(cint u, cint fa, ll mxn, ll mxe) {
	mxn = max(mxn, val[u]);
	ll r = mxn*mxe;
	if(f[u][st] == -1 || f[u][st] > r) f[u][st] = f[st][u] = r;
	for(auto v: to[u]) {
		if(v.first != fa) {
			dfs(v.first, u, mxn, max(mxe, v.second));
		}
	}
}

int main() {
	//freopen("1.in", "r", stdin);
	//cout.flags(ios::fixed); cout.precision(8);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i=1; i<=n; i++) b[i].init(i);
	for(int i=1; i<=m; i++) a[i].init();
	sort(a+1, a+1+m);
	sort(b+1, b+1+n);
	for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) if(i!=j) f[i][j] = -1;
	for(int i=1; i<=n; i++) {
		int s = b[i].id;
		for(int j=1; j<=n; j++) bcj[j] = j;
		for(int j=1; j<=n; j++) sum[j] = 1;
		for(int j=1; j<=n; j++) to[j].clear();
		for(int j=1; j<=m; j++) {
			int u = a[j].u;
			int v = a[j].v;
			if(vis[u] || vis[v]) continue;
			if(fd(u) != fd(v)) {
				if(sum[fd(u)] > sum[fd(v)]) swap(u, v);
				bcj[fd(u)] = fd(v);
				sum[fd(v)] += sum[fd(u)];
				to[u].push_back( {v, a[j].w} );
				to[v].push_back( {u, a[j].w} );
			}
		}
		for(int j=1; j<=n; j++) { st = j; dfs(j, j, 0, 0); }
		vis[s] = 1;
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++)
			cout << f[i][j] << ' ';
			cout << '\n';
	}
	return 0;
}