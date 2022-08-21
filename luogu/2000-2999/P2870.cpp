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

struct SA {
    #define mx_n 1000001*2
    /* 数组开到上限两倍 */
    int sa[mx_n], rk[mx_n], cnt[mx_n], id[mx_n], px[mx_n], od[mx_n];
    /* 注意字符串下标需要从 0 开始 , 但是 sa 和 rk 下标从 1 开始 */
    void init_sa(char *s, int n) {
        int m = 'z', i, w, p;
        auto cmp = [&](int &x, int &y, int &w) -> bool { return od[x] == od[y] && od[x+w] == od[y+w]; };
        for(i=1; i<=n; ++i) { ++cnt[rk[i] = s[i-1]]; }
        for(i=1; i<=m; ++i) { cnt[i] += cnt[i-1]; }
        for(i=n; i>=1; --i) { sa[cnt[rk[i]]--] = i; }
        for(w=1; w<=n; w<<=1, m=p) {
            for(p=0, i=n; i>n-w; --i) { id[++p] = i; }
            for(i=1; i<=n; ++i) { if(sa[i] > w) { id[++p] = sa[i] - w; } }
            memset(cnt, 0, sizeof cnt);
            for(i=1; i<=n; ++i) { ++cnt[px[i] = rk[id[i]]]; }
            for(i=1; i<=m; ++i) { cnt[i] += cnt[i-1]; }
            for(i=n; i>=1; --i) { sa[cnt[px[i]]--] = id[i]; }
            memcpy(od, rk, sizeof od);
            for(p=0, i=1; i<=n; ++i) { rk[sa[i]] = cmp(sa[i], sa[i-1], w) ? p : ++p; }
            if(p == n) { for(i=1; i<=n; ++i) { sa[rk[i]] = i; } break; }
        }
    }
};

int n;
char s[1000100];
SA A;

void solve(cint T) {
    cin >> n;
    for(int i=0; i<n; i++) { cin >> s[i]; }
    for(int i=0; i<n; i++) { s[n*2-1-i] = s[i]; }
    A.init_sa(s, n*2);
    auto rk = A.rk;
    int l=0, r=n, i=0;
    // for(int i=0; i<n*2; i++) { cout << rk[i] << ' '; }
    // cout << endl;
    // for(int i=0; i<n*2; i++) { cout << s[i] << ' '; }
    // cout << endl;
    while(l+r-n < n) {
        if(r < n*2 && rk[r+1] <= rk[l+1]) { cout << s[r++]; }
        else { cout << s[l++]; }
        ++i;
        if(i % 80 == 0) { cout << '\n';}
    }
    // cout << '\n';
}

int main() {
    freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    //std::cin >> T_;
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}