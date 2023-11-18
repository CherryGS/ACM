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
#define ifor(s, e, t) for(int i=s;i<=e;i+=t)
#define jfor(s, e, t) for(int j=s;j<=e;j+=t)

const int mod = 998244353;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int add(ll x, const int &y) { x += y; return x >= mod ? x - mod : x; }
int sub(ll x, const int &y) { x -= y; return x >= 0 ? x : x + mod; }
int mul(ll x, const int &y) { x *= y; return x >= mod ? x % mod : x; }

int n, m;
int a[200200];
int s[200200];
int d[200200];
int to[200200];
map<int, int> e;
vector<int> ans[200200];

void solve(cint T) {
    e.clear();
    cin >> n >> m;
    ifor(1, m, 1) { ans[i].clear(); }
    ifor(1, n, 1) { cin >> a[i]; }
    ifor(1, m, 1) { cin >> s[i]; }
    ifor(1, m, 1) { cin >> d[i]; }
    ifor(1, n, 1) { ++e[a[i]]; }
    priority_queue<pii> q;
    queue<pii> qt;
    for(auto &k: e) { q.push({k.second, k.first}); }
    bool flag = true;
    ifor(1, m, 1) {
        while(s[i] > 0) {
            jfor(1, min(d[i], s[i]), 1) {
                if(q.empty() || q.top().first == 0) { flag = false; break; }
                auto k = q.top(); q.pop();
                ans[i].push_back(k.second);
                qt.push({k.first-1, k.second});
            }
            while(!qt.empty()) { q.push(qt.front()); qt.pop(); }
            if(flag == false) { break; }
            s[i] -= d[i];
        }
    }
    if(!flag) { cout << -1 << '\n'; }
    else {

        ifor(1, m, 1) {
            for(auto &k: ans[i]) { cout << k << ' '; }
            cout << '\n';
        }
    }
}

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    std::cin >> T_;
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}
