#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;
typedef pair<int, int> pii;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n, m;
ll a[100100];
unordered_map<int, int> e1, e2;
ll ans;

int block_siz;
struct query {
    int l, r;
    int bl, br;
    int id;
    ll ans;
    void init(cint x) {
        id = x;
        cin >> l >> r;
        bl = l / block_siz;
        br = r / block_siz;
    }
} q[100100];

bool cmp1(const query&a, const query&b) {
    return a.bl == b.bl ? a.r < b.r : a.bl < b.bl;
}

bool cmp2(const query&a, const query&b) {
    return a.id < b.id;
}

void add(cint x) {
    if(x < 1 || x > n) return;
    ++e2[a[x]];
    ans = max(ans, a[x] * (e1[a[x]] + e2[a[x]]));
}

void add1(cint x) {
    if(x < 1 || x > n) return;
    ++e1[a[x]];
    ans = max(ans, a[x] * (e1[a[x]] + e2[a[x]]));
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    block_siz = n / sqrt(m);
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=m; i++) q[i].init(i);
    
    sort(q+1, q+1+m, cmp1);
    int l = 0, r = 0;
    ll las_ans = 0;
    for(int i=1; i<=m; i++) {
        ans = 0;
        if(i == 1 || q[i].bl != q[i-1].bl) {
            l = (q[i].bl+1)*block_siz;
            r = l-1;
            las_ans = 0;
            e1.clear();
        }
        if(q[i].bl == q[i].br) {
            for(int j=q[i].l; j<=q[i].r; j++)
                ++e1[a[j]], ans = max(ans, a[j]*e1[a[j]]);
            e1.clear();
        }
        else {
            ans = las_ans;
            while(r < q[i].r) ++r, add1(r);
            las_ans = ans;
            while(l > q[i].l) --l, add(l);
            l = (q[i].bl+1)*block_siz;
            e2.clear();
        }
        q[i].ans = ans;
    }
    sort(q+1, q+1+m, cmp2);
    for(int i=1; i<=m; i++)
        cout << q[i].ans << endl;

    return 0;
}