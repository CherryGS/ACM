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
char s[200200];
int st[200200], cnt;

void solve(cint T) {
    cnt = 0;
    cin >> n;
    cin >> s;
    int one_num = 0;
    for(auto &r : s) { one_num += (r == '1'); }
    if(one_num & 1 || one_num < 2) {
        cout << "NO" << '\n';
        return;
    }
    vector<pii> ans;
    vector<int> id;
    int tmp[2] = {0, 0};
    for(int i=1; i<=n; i++) {
        if(s[i-1] == '1') {
            if(tmp[0]) { tmp[1] = i; break; }
            else { tmp[0] = i; }
        }
    }
    for(int i=tmp[1]; i<=n; i++) { id.push_back(i); }
    for(int i=1; i<tmp[1]; i++) { id.push_back(i); }
    if(s[id[0]-1] == '1') { st[++cnt] = id[0]; }
    for(int i=1; i<n; i++) {
        if(cnt) {
            ans.push_back({id[i], st[cnt]});
            --cnt;
        }
        else {
            ans.push_back({id[i], id[i-1]});
            st[++cnt] = id[i-1];
        }
        if(s[id[i]-1] == '0') { st[++cnt] = id[i]; }
    }
    cout << "YES" << '\n';
    for(auto &k : ans) {
        cout << k.first << ' ' << k.second << '\n';
    }
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