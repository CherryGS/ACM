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

struct node {
    int i, j, id, l;
    int d, cnt;
};

int n, m, k;
char c[51][51];
char s[51][51];
int len[51];
int mx[51][51][51][51][3];
vector<int> p[26];
queue<node> q;

bool solve(cint T) {
    memset(mx, 0x3f, sizeof mx);
    cin >> n >> m >> k;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cin >> c[i][j];
        }
    }
    for(int i=1; i<=k; i++) { cin >> s[i]; }
    for(int i=1; i<=k; i++) { p[s[i][0]-'A'].push_back(i); len[i] = strlen(s[i]); }
    int ans = -1;
    for(int i=1; i<=m; i++) {
        int f = c[1][i]-'A';
        if(p[f].size()) {
            for(auto &r: p[f]) {
                q.push({1, i, r, 0, 0, 1});
            }
        }
    }
    while(!q.empty()) {
        auto k = q.front(); q.pop();
        // cout << k.i << ' ' << k.j << ' ' << k.d << ' ' << k.id << ' ' << k.l << endl;
        bool is_lst = (k.l == len[k.id] - 1);
        if(k.i == n && is_lst) { ans = k.cnt; break; }
        if(k.i != n) {
            int f = c[k.i+1][k.j]-'A';
            if(is_lst && p[f].size()) {
                for(auto &r: p[f]) {
                    if(k.cnt+1 >= mx[k.i+1][k.j][r][0][0]) { continue; }
                    else { mx[k.i+1][k.j][r][0][0] = k.cnt + 1; }
                    q.push({k.i+1, k.j, r, 0, 0, k.cnt+1});
                }
            }
            else {
                if(c[k.i+1][k.j] == s[k.id][k.l+1]) {
                    if(k.cnt+1 >= mx[k.i+1][k.j][k.id][k.l+1][0]) { continue; }
                    else { mx[k.i+1][k.j][k.id][k.l+1][0] = k.cnt + 1; }
                    q.push({k.i+1, k.j, k.id, k.l+1, 0, k.cnt+1});
                }
            }
        }
        if(k.j != 1 && k.d != 1) {
            int f = c[k.i][k.j-1]-'A';
            if(is_lst && p[f].size()) {
                for(auto &r: p[f]) {
                    if(k.cnt+1 >= mx[k.i][k.j-1][r][0][2]) { continue; }
                    else { mx[k.i][k.j-1][r][0][2] = k.cnt + 1; }
                    q.push({k.i, k.j-1, r, 0, 2, k.cnt+1});
                }
            }
            else {
                if(c[k.i][k.j-1] == s[k.id][k.l+1]) {
                    if(k.cnt+1 >= mx[k.i][k.j-1][k.id][k.l+1][2]) { continue; }
                    else { mx[k.i][k.j-1][k.id][k.l+1][2] = k.cnt + 1; }
                    q.push({k.i, k.j-1, k.id, k.l+1, 2, k.cnt+1});
                }
            }
        }
        if(k.j != m && k.d != 2) {
            int f = c[k.i][k.j+1]-'A';
            if(is_lst && p[f].size()) {
                for(auto &r: p[f]) {
                    if(k.cnt+1 >= mx[k.i][k.j+1][r][0][1]) { continue; }
                    else { mx[k.i][k.j+1][r][0][1] = k.cnt + 1; }
                    q.push({k.i, k.j+1, r, 0, 1, k.cnt+1});
                }
            }
            else {
                if(c[k.i][k.j+1] == s[k.id][k.l+1]) {
                    if(k.cnt+1 >= mx[k.i][k.j+1][k.id][k.l+1][1]) { continue; }
                    else { mx[k.i][k.j+1][k.id][k.l+1][1] = k.cnt + 1; }
                    q.push({k.i, k.j+1, k.id, k.l+1, 1, k.cnt+1});
                }
            }
        }
    }
    if(ans == -1) { cout << "impossible\n"; }
    else { cout << ans << '\n'; }
    return true;
}

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    // std::cin >> T_;
    for(int _T=1; _T<=T_; _T++) { if(solve(_T) == 0) { break; } }
    return 0;
}