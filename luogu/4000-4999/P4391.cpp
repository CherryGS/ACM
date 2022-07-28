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
    int pi[2000100]; // 这里大小开到 n+m+1 就可以
    int mx_n;
    void init(char *s, int n) {
        fill(pi, pi+n+1, 0);
        mx_n = n;
        for(int i=1; i<n; i++) {
            int r = pi[i-1];
            while(r && s[r] != s[i]) { r = pi[r-1]; }
            if(s[r] == s[i]) { pi[i] = r + 1; }
        }
    }
    /*
        pattern + '#' + target
    */
    void kmp(char target[], char pattern[], char data[]) {
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
};

void solve(cint T) {

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