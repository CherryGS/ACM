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

struct p {
    int l, r, c;
    bool operator < (const p&a) const {
        return l == a.l ? r < a.r : l < a.l;
    }
};

int n, q;
int a[1000100];
ll col[1000100];
ll node[1000100];
set<p> e;

int lowbit(cint x) { return x & -x; }

void doing(const p& x, int c) {

}

void solve(cint T) {
    cin >> n >> q;
    char s[10];
    int x, y, z;
    for(int i=1; i<=q; i++) {
        cin >> s;
        if(s[0] == 'C') {
            cin >> x >> y >> z;
            // split
            auto k = e.lower_bound({x, 0});
            if(k != e.begin() && k != e.end() && k->l > x) { 
                --k;
                int l = k->l, r = k->r, c = k->c;
                doing({x, r, c}, z);
                e.erase(k);
                e.insert({l, r-1, c});
                k = e.insert({x, r, z}).first;
            }

            // merge
            int l = -1, r = -1;
            if(k != e.end() && k->r <= y) { l = k->l; }
            while(k != e.end() && k->r <= y) {
                doing(*k, z);
                r = k->r;
                k = e.erase(k);
            }
            if(l != -1) { e.insert({l, r, z}); }

            // split
            if(k != e.end() && k->l <= y) {
                int l = k->l, r = k->r, c = k->c;
                doing({l, y, c}, z);
                e.erase(k);
                e.insert({l, y, z});
                e.insert({y+1, r, c});
            }
        }
        else if(s[0] == 'A') {

        }
        else {

        }
    }
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