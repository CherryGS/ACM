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

int n, k;
int a[100100];
map<int, int> r;
int tim[100100];

struct node {
    int id;
    bool operator < (const node&a) const {
        return tim[id] < tim[a.id];
    }
};

bool check(cint x) {
    memset(tim, 0, sizeof tim);
    int siz = 0;
    int sum = 0;
    set<node> e;
    for(int i=1; i<=n; i++) {
        int s = r[a[i]];
        if(e.find({s}) != e.end()) {
            ++sum;
            e.erase({s});
            tim[s] = i;
            e.insert({s});
        }
        else {
            if(siz < x) {
                ++siz;
                tim[s] = i;
                e.insert({s});
            }
            else {
                e.erase(e.begin());
                tim[s] = i;
                e.insert({s});
            }
        }
    }
    // cout << " --- " << sum << endl;
    return sum >= k;
}

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for(int i=1; i<=n; i++) cin >> a[i];
    int tmp = 0;
    for(int i=1; i<=n; i++) if(r.find(a[i]) == r.end()) r[a[i]] = ++tmp;
    int l=1, r=n+1, mid;
    while(l < r) {
        // cout << l << ' ' << r << endl;
        mid = l + ((r-l) >> 1);
        if(check(mid)) r = mid;
        else l = mid+1;
    }
    if(l > n) cout << "cbddl" << endl;
    else  cout << l << endl;
    return 0;
}
/*
*/