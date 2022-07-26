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

struct KMP {
    int pi[2000100];
    int mx_n;
    void init(char *s, int n) {
        mx_n = n;
        for(int i=1; i<n; i++) {
            int r = pi[i-1];
            while(r && s[r] != s[i]) { r = pi[r-1]; }
            if(s[r] == s[i]) { pi[i] = r + 1; }
        }
    }
    void init_kmp(char target[], char pattern[], char data[]) {
        int n1 = strlen(target), n2 = strlen(pattern);
        strcpy(data, pattern);
        strcpy(data+n2+1, target);
        data[n2] = '#';
        init(data, n1+n2+1);
    }
    int fd_nx(int i, int le) {
        while(i < mx_n) { if(pi[i] == le) { return i; } ++i; }
        return -1;
    }
    vector<int> fd_all(int s, int le) {
        static vector<int> q;
        while(true) { s = fd_nx(s, le); if(s == -1) { break; } q.push_back(s); ++s;}
        return q;
    }
} A, B;

char s1[1000100];
char s2[1000100];
char s[2000100];

void solve(cint T) {
    cin >> s1;
    cin >> s2;
    int n1 = strlen(s1), n2 = strlen(s2);
    A.init_kmp(s1, s2, s);
    B.init(s2, n2);
    for(auto &k: A.fd_all(n2*2, n2)) { cout << k-n2*2+1 << '\n'; }
    for(int i=0; i<n2; i++) { cout << B.pi[i] << ' '; }
    cout << '\n';
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