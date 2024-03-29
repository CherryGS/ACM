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

struct KMP {
    int pi[2000100]; // 这里大小开到 n+m+1 就可以
    void init(char *s, int n, int st) {
        for(int i=st; i<n; i++) {
            int r = pi[i-1];
            while(r && s[r] != s[i]) { r = pi[r-1]; }
            if(s[r] == s[i]) { pi[i] = r + 1; }
        }
    }
} A;

int q;
char s[1000100];
char t[101];

bool solve(cint T) {
    cin >> s;
    int n = strlen(s);
    cin >> q;
    A.init(s, n, 1);
    for(int i=1; i<=q; i++) {
        cin >> t;
        int nn = strlen(t);
        strcpy(s+n, t);
        A.init(s, n+nn, n);
        auto pre = A.pi;
        for(int j=n; j<n+nn; j++) {
            cout << pre[j] << ' ';
        }
        fill(pre+n, pre+n+nn, 0);
        cout << '\n';
    }
    return true;
}

int main() {
    freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    // std::cin >> T_;
    for(int _T=1; _T<=T_; _T++) { if(solve(_T) == 0) { break; } }
    return 0;
}