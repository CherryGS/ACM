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
#define ifor(s, e) for(int i=s;i<=e;i+=1)
#define jfor(s, e) for(int j=s;j<=e;j+=1)

const int mod = 998244353;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int add(ll x, const int &y) { x += y; return x >= mod ? x - mod : x; }
int sub(ll x, const int &y) { x -= y; return x >= 0 ? x : x + mod; }
int mul(ll x, const int &y) { x *= y; return x >= mod ? x % mod : x; }

int n, m;
char s[200200];
char t[200200];
queue<int> ch[202];

void solve(cint T) {
    ifor(0, 'z'-'a') {
        while(!ch[i].empty()) { ch[i].pop(); }
    }
    cin >> n >> m;
    cin >> s;
    cin >> t;
    int l = 0, now;
    bool flag = true;
    ifor(0, m-1) {
        if(!ch[t[i]-'a'].empty()) {
            now = ch[t[i]-'a'].front();
            ch[t[i]-'a'].pop();
        }
        else {
            while(l < n && s[l] != t[i]) {
                ch[s[l]-'a'].push(l);
                ++l;
            }
            if(l == n) { flag = false; break; }
            now = l;
            ++l;
        }
        jfor(0, t[i]-'a'-1) {
            while(!ch[j].empty() && ch[j].front() < now) { ch[j].pop(); }
        }
    }
    if(flag) { cout << "YES\n"; }
    else { cout << "NO\n"; }
}

int main() {
    //freopen("1.in", "r", stdin);
    //freopen("1.out", "w", stdout);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    std::cin >> T_;
    for(int _T=1; _T<=T_; _T++) { solve(_T); }
    return 0;
}
