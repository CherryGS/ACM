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

int n;
int h[200200];
int deg[200200];
vector<int> e[200200];
ll ans;

void solve(cint T) {
    cin >> n;
    for(int i=1; i<=n; i++) cin >> h[i];
    int u, v;
    for(int i=1; i<n; i++) {
        cin >> u >> v;
        deg[u]++;
        deg[v]++;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    priority_queue<pii, vector<pii>, greater<pii>> q;
    for(int i=1; i<=n; i++) {
        if(deg[i] == 1) {
            q.push({h[i], i});
        }
    }
    int now = 0;
    int siz = n;
    while(true) {
        while(!q.empty() && q.top().first <= now) {
            int u = q.top().second;
            // cout << u << endl;
            --siz;
            q.pop();
            for(int v: e[u]) {
                deg[v]--;
                if(deg[v] == 1) {
                    q.push({h[v], v});
                }
            }
        }
        // cout << q.top().first << ' ' << q.size() << ' ' << siz << ' ' << ans << endl;
        if(siz == 1) {
            ans += 2*(q.top().first-now);
            break;
        }
        else if(siz == 0) {
            break;
        }

        ans += (q.top().first-now)*q.size();
        now = q.top().first;
    }
    cout << ans << endl;
}

int main() {
    // freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    //std::cin >> T_;
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}