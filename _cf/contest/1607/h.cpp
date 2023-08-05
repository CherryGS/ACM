#include <bits/stdc++.h>
using namespace std;

std::mt19937 rng(std::random_device{}());
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;
typedef const ll& cll;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;

#define ls (loc<<1)
#define rs ((loc<<1)|1)

const int mod1 = 1e9+7;
const int mod2 = 998244353;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int t;
int n;
ll a[200100], b[200200], m[200200];
map<ll, int> e;
vector<int> r[200200];
vector<int> id;
int cnt;

bool cmp(cint x, cint y) {
    return a[x] - m[x] < a[y] - m[y];
}

int main() {
    freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        e.clear();
        for(int i=1; i<=cnt; i++) r[i].clear();
        cnt = 0;
        for(int i=1; i<=n; i++) cin >> a[i] >> b[i] >> m[i];
        for(int i=1; i<=n; i++) {
            ll x = a[i]+b[i]-m[i];
            if(e.find(x) == e.end()) e[x] = ++cnt;
            r[e[x]].push_back(i);
        }
        ll ans = 0;
        for(int i=1; i<=cnt; i++) sort(r[i].begin(), r[i].end(), cmp);
        for(int i=1; i<=cnt; i++) {
            priority_queue<int, vector<int>, greater<int>> q;
            int le = r[i].size();
            ll pre = 0;
            for(int j=0; j<le; j++) {
                int id = r[i][j];
                pre = max(pre, ll(q.size()));
                while(!q.empty() && q.top() <= a[id]-m[id]) q.pop();
                q.push(a[id]);
            }
            ans += le-pre;
        }
        cout << ans << endl;
    }
    return 0;
}