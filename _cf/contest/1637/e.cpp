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

int n, m;
int to[300300];
ll a[300300];
set<pii> e;

struct node {
    ll val, cnt;
    bool operator < (const node&x) const {
        return cnt == x.cnt ? val < x.val : cnt < x.cnt;
    } 
};

void solve(cint T) {
    cin >> n >> m;
    int ta, tb;
    for(int i=1; i<=n; i++) cin >> a[i];
    e.clear();
    for(int i=1; i<=m; i++) {
        cin >> ta >> tb;
        if(ta > tb) { swap(ta, tb); }
        e.insert({ta, tb});
    }
    vector<node> q;
    sort(a+1, a+1+n);
    int lst = 0;
    for(int i=2; i<=n; i++) {
        if(a[i] != a[i-1]) {
            q.push_back({a[i-1], i-lst-1});
            lst = i-1;
        }
    }
    if(lst != n) { q.push_back({a[n], n-lst}); }
    sort(q.begin(), q.end());
    int le = q.size();
    int l = 0;
    for(int i=0; i<le; i++) {
        if(i != 0 && q[i].cnt == q[i-1].cnt) { to[i] = l-1; }
        else { l = i; to[i] = i-1; }
    }
    ll ans = 0;
    for(int i=1; i<le; i++) {
        for(int j=i-1; j>=0; j--) {
            int ta = q[i].val;
            int tb = q[j].val;
            if(ta > tb) { swap(ta, tb); }
            if(e.find({ta, tb}) != e.end()) { continue; }
            ans = max(ans, (q[i].cnt + q[j].cnt) * (q[i].val + q[j].val));
            j = to[j]+1;
        }
    }
    cout << ans << endl;
}

int main() {
    freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    std::cin >> T_;
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}