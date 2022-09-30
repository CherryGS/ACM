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

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n;
int dis[101][101];

bool solve(cint T) {
    cin >> n;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> dis[i][j];
        }
    }
    vector<pii> ans;
    for(int i=1; i<=n; i++) {
        for(int j=i+1; j<=n; j++) {
            bool ok = true;
            for(int k=1; k<=n; k++) {
                if(k == i || k == j) { continue; }
                if(dis[j][k] + dis[k][i] == dis[i][j]) { ok = false; }
            }
            if(ok) { ans.push_back({i, j}); }
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for(auto &k: ans) {
        cout << k.first << ' ' << k.second << '\n';
    }

    return true;
}

int main() {
    freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    std::cin >> T_;
    for(int _T=1; _T<=T_; _T++) { if(solve(_T) == 0) { break; } }
    return 0;
}