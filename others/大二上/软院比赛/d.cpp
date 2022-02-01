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

int a, b, c;
int p[3] = {0, 1, 2};

struct node{
    int l[3];
};

void solve(cint T) {
    cin >> a >> b >> c ;
    if(b < c) { swap(b, c); swap(p[1], p[2]); }
    if(a < c) { swap(a, c); swap(p[0], p[2]); }
    if(a < b) { swap(a, b); swap(p[0], p[1]); }
    if(b*c < a) cout << -1 << endl;
    else {
        set<pii> e;
        vector<node> ans;
        cout << a << endl;
        for(int i=1; i<=b; i++)
            for(int j=1; j<=c; j++)
                e.insert({i, j});
        int x = 1, y = 1;
        for(int i=1; i<=a; i++) {
            if(y <= b) {
                ans.push_back({y, x ,1});
                e.erase({y, x});
                if(x < c) ++ x;
                ++y;
            } else {
                auto k = e.begin();
                ans.push_back({k->first, k->second, 1});
                e.erase(k);
            }
        }
        int s[3];
        if(p[0] == 0) {
            if(p[1] == 1) s[0] = 0, s[1] = 1, s[2] = 2;
            else s[0] = 1, s[1] = 0, s[2] = 2;
        }
        else if(p[0] == 1) {
            if(p[1] == 0) s[0] = 0, s[1] = 2, s[2] = 1;
            else s[0] = 1, s[1] = 2, s[2] = 0;
        }
        else {
            if(p[1] == 0) s[0] = 2, s[1] = 0, s[2] = 1;
            else s[0] = 2, s[1] = 1, s[2] = 0;
        }
        for(auto r: ans) {
            cout << r.l[s[0]] << ' ' << r.l[s[1]] << ' ' << r.l[s[2]] << endl;
        }
    }
}

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    // std::cin >> T_;
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}