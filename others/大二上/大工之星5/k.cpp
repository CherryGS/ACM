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

int n, m;
int a[200200];

struct node {
    int y, p1, p2;
    void init() {
        cin >> y >> p1 >> p2;
    }
    // bool operator < (const node&a) const {
    //     return 
    // }
};

struct que {
    int y, p, id, ans;
    bool operator < (const que& a) const {
        return y < a.y;
    }
};

bool cmp(const que& a, const que& b) {
    return a.id < b.id;
}

void solve(cint T) {
    cin >> n >> m;
    vector<node> x;
    vector<que> y;
    for(int i=1; i<=n; i++) cin >> a[i];
    int t1, t2, t3, t4;
    for(int i=1; i<=m; i++) {
        cin >> t1;
        if(t1 == 0) {
            cin >> t2 >> t3 >> t4;
            x.push_back({t2, t3, t4});
        } else {
            cin >> t2 >> t3;
            y.push_back({t2, t3, i, 0});
        }
    }
    sort(y.begin(), y.end());
    int r=0;
    for(auto &k: y) {
        while(r < x.size() && x[r].y <= k.y) {
            swap(a[x[r].p1], a[x[r].p2]);
            ++r;
        }
        k.ans = a[k.p];
    }
    sort(y.begin(), y.end(), cmp);
    for(auto k: y) {
        cout << k.ans << endl;
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