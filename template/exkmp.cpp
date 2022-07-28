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

struct EXKMP {
    int z[40004000]; // 这里大小开到 n+m+1 就可以
    int mx_n;
    void init(char *s, int n) {
        mx_n = n;
        int l = 0, r = 0;
        z[0] = n;
        for(int i=1; i<n; i++) {
            if(i <= r && z[i-l] < r-i+1) {
                z[i] = z[i-l];
            }
            else {
                z[i] = max(0, r-i+1);
                while(i+z[i]<n && s[z[i]] == s[i+z[i]]) { ++z[i]; }
            }
            if(i+z[i]-1 > r) { r = i + z[i] - 1; l = i; }
        }
    }
    /*
        pattern + '#' + target
    */
    void init_kmp(char target[], char pattern[], char data[]) {
        int n1 = strlen(target), n2 = strlen(pattern);
        strcpy(data, pattern);
        strcpy(data+n2+1, target);
        data[n2] = '#';
        init(data, n1+n2+1);
    }
    int fd_nx(int i, int le) {
        while(i < mx_n) { if(z[i] == le) { return i; } ++i; }
        return -1;
    }
    vector<int> fd_all(int s, int le) {
        static vector<int> q;
        while(true) { s = fd_nx(s, le); if(s == -1) { break; } q.push_back(s); ++s;}
        return q;
    }
} A, B;

char a[20002000];
char b[20002000];
char c[40002000];

void solve(cint T) {
    cin >> a >> b;
    int n1 = strlen(a), n2 = strlen(b);
    A.init(b, n2);
    B.init_kmp(a, b, c);
    ll ans = 0;
    for(int i=0; i<n2; i++) { ans ^= 1ll * (i+1) * (A.z[i]+1); }
    cout << ans << '\n';
    ans = 0;
    for(int i=0; i<n1; i++) { ans ^= 1ll * (i+1) * (B.z[n2+1+i]+1); }
    cout << ans << '\n';
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