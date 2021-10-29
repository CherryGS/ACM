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

int n;
int a[200200];
int m;
map<int, int> e;
int cnt;
int loc[200200];
int loc1[200200];
int loc2[200200];
int re2[200200], ed2;
int re1[200200], ed1;
int re[200200], ed;

int ans;
int block_siz;
struct query {
    int l, r;
    int bl, br;
    int id;
    int ans;
    void init(cint x) {
        id = x;
        cin >> l >> r;
        bl = l / block_siz;
        br = r / block_siz;
    }
} q[200200];

bool cmp1(const query&a, const query&b) {
    return a.bl == b.bl ? a.r < b.r : a.bl < b.bl;
}

bool cmp2(const query&a, const query&b) {
    return a.id < b.id;
}

void add1(cint x) {
    if(x < 1 || x > n) return;
    if(loc[a[x]]) ans = max(ans, x - loc[a[x]]);
    else {
        loc[a[x]] = x;
        re[++ed] = a[x];
    }
    if(!loc1[a[x]]) re1[++ed1] = a[x];
    loc1[a[x]] = x;
}

void add2(cint x) {
    if(x < 1 || x > n) return;
    if(loc2[a[x]]) ans = max(ans, loc2[a[x]] - x);
    else {
        loc2[a[x]] = x;
        re2[++ed2] = a[x];
    }
    if(loc1[a[x]]) ans = max(ans, loc1[a[x]] - x);
}

void sol() {
    for(int i=1; i<=n; i++) {
        if(e.find(a[i]) == e.end()) e[a[i]] = ++cnt;
        a[i] = e[a[i]];
    }
    int l = 0, r = 0;
    int las_ans = 0;
    for(int i=1; i<=m; i++) {
        ans = 0;
        if(i == 1 || q[i].bl != q[i-1].bl) {
            l = min(n+1, (q[i].bl+1)*block_siz);
            r = l-1;
            las_ans = 0;
            while(!ed) { loc[re[ed--]] = 0; }
            while(!ed1) { loc1[re1[ed1--]] = 0; }
        }
        if(q[i].bl == q[i].br) {
            for(int j=q[i].l; j<=q[i].r; j++) {
                if(loc[a[j]]) ans = max(ans, j-loc[a[j]]);
                else {
                    loc[a[j]] = j;
                    re[++ed] = a[j];
                }
            }
            while(!ed) { loc[re[ed--]] = 0; }
        }
        else {
            ans = las_ans;
            while(r < q[i].r) ++r, add1(r);
            las_ans = ans;
            while(l > q[i].l) --l, add2(l);
            while(!ed2) { loc2[re2[ed2--]] = 0; }
            l = min(n+1, (q[i].bl+1)*block_siz);
        }
        q[i].ans = ans;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    cin >> m;
    block_siz = ceil(n / sqrt(m));
    for(int i=1; i<=m; i++) q[i].init(i);
    sort(q+1, q+1+m, cmp1);
    sol();
    sort(q+1, q+1+m, cmp2);
    for(int i=1; i<=m; i++)
        cout << q[i].ans << '\n';
    return 0;
}
/*
5
2 3 2 3 2 
4
1 3
2 4
3 5
1 5
*/