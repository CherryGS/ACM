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

int n;
int a[500500];
int b[500500];
int l[500500];

struct node {
    int l, r, id;
    bool operator < (const node&a) const {
        return l < a.l;
    }
};

bool cmp1(const node&a, const node&b) {
    return a.r > b.r;
}

int cacu(int i, int b) {
    return ceil((double)i / (b+1) + ept);
}

void solve(cint T) {
    cin >> n;
    for(int i=1; i<=n; i++) { cin >> b[i]; }
    for(int i=1; i<=n; i++) { l[i] = cacu(i, b[i]); }
    vector<node> q;
    // for(int i=1; i<=n; i++) { cout << l[i] << ' ' << b[i] << ' ' << i << endl; }
    for(int i=1; i<=n; i++) { 
        if(b[i] != 0) {
            q.push_back({l[i], i/b[i], i}); 
        }
        else {
            q.push_back({l[i], n, i});
        }
    }
    int r = 0;
    sort(q.begin(), q.end(), cmp1);
    priority_queue<node, vector<node>> qe;
    for(int i=n; i>=1; i--) {
        while(r < n && q[r].r >= i) { qe.push(q[r]); r++; }
        auto k = qe.top();
        qe.pop();
        a[k.id] = i;
    }
    for(int i=1; i<=n; i++) { cout << a[i] << ' '; }
    cout << endl;
}

int main() {
    freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    std::cin >> T_;
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}