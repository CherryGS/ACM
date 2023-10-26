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
bool vis[3003];
int arr[3003];
int q[3003], c;
int q1[3003], c1;
vector<int> s[4];

void solve(cint T) {
    cin >> n;
    int t1, t2;
    for(int i=1; i<=n; i++) {
        cin >> t1 >> t2;
        s[t1].push_back(t2);
    }
    for(int i=1; i<=3; i++) { sort(s[i].begin(), s[i].end(), [](const int&a, const int&b) { return a > b; }); }
    bool flag = true;
    for(auto k: s[2]) {
        while(k > 0 && vis[k]) { --k; }
        if(k <= 0) { flag = false; break; }
        vis[k] = 1;
    }
    for(auto k: s[3]) {
        while(k > 0 && vis[k]) { --k; }
        if(k <= 0) { flag = false; break; }
        vis[k] = 1;
    }
    memset(vis, 0, sizeof vis);
    for(auto k: s[1]) {
        while(k > 0 && vis[k]) { --k; }
        if(k <= 0) { flag = false; break; }
        vis[k] = 1;
    }
    if(flag == false) {
        cout << -1 << '\n';
        // cout << "checker1---" << endl;
        return;
    }
    int ans = s[1].size() + s[2].size() + s[3].size() * 2;
    for(int i=0; i<=s[2].size(); i++) {
        c1 = c = 0;
        for(int j=0; j<i; j++) { q[++c] = s[2][j]; }
        for(auto k: s[3]) { q[++c] = k; }
        sort(q+1, q+1+c);
        bool ok = true;
        int p = 1;
        for(int j=1; j<=n*2 && p <= c; j++) {
            if(!vis[j]) {
                if(j > q[p]) { ok = false; break; }
                q1[++c1] = q[p] - j;
                if(i == 1)
                cout << q[p] << " --- " << j << endl;
                ++p;
            }
        }
        if(ok == false || p <= c) { break; }
        // cout << i << " - " << endl;
        sort(q1+1, q1+1+c1);
        int siz = s[2].size() - i;
        // if(i == 1)
        // cout << siz << endl;
        for(int j=1; j<=c1; j++) {
            // if(i == 1)
            // cout << q1[j] << ' ' << siz << endl;
            if(q1[j] <= siz) { ++siz; }
        }
        ans = min(ans, int(s[1].size() + s[3].size() + i + siz));
    }
    cout << ans+2 << '\n';
}

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    //std::cin >> T_;
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}
