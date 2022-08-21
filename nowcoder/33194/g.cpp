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

int k;
int to[3000300];
char s[3000001];
int val[3000300];
set<int> e[3000300];

void init() {
    to[0] = 1;
    for(int i=1; i<=3000000; i++) { to[i] = 1ll * to[i-1] * 10 % mod;}
}

int get_h(int l, int r) {
    return (val[r] - 1ll * val[l] * to[r-l] % mod + mod) % mod;
}

void solve(cint T) {
    cin >> k;
    string p, tmp;
    for(int i=1; i<=k; i++) { 
        cin >> tmp;
        p += tmp;
        if(i < k) { for(int j=1; j<=i; j++) { p += 'A'+j-1; } }
    }
    for(int i=0; i<int(p.size()); i++) {
        s[i*2] = '#';
        s[i*2+1] = p[i];
    }
    s[p.size()*2] = '#';
    int n = strlen(s);
    vector<int> d(n);
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 1 : min(d[l + r - i], r - i + 1);
        while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
            k++;
        }
        d[i] = k--;
        if (i + k > r) {
            l = i - k;
            r = i + k;
        }
    }
    for(int i=0; i<n; i++) {
        val[i] = s[i];
        if(i != 0) { val[i] = 10ll*val[i-1] + val[i] % mod; }
    }
    int ans = 0;
    for(int i=0; i<n; i++) {
        if(s[i] < 'A' || s[i] > 'Z') {
            for(int j=d[i]-1; j > 0; j-=2) {
                int h = get_h(i, i+j-1);
                if(e[j].find(h) == e[j].end()) {
                    ++ans;
                    e[j].insert(h);
                    // cout << i << ' ' << j << endl;
                }
                else { break; }
                // cout << " --- " << endl;
            }
        }
    }
    cout << s << endl;
    for(int i=0; i<n; i++) { cout << d[i] << ' '; }
    cout << endl;
    cout << ans << '\n';
}

int main() {
    freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    //std::cin >> T_;
    init();
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}