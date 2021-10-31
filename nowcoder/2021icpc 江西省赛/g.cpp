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

int t, n, q;
int a[50050];
vector<int> r[1001000];
int vis[1001000];
int mx;
int sum[1001000];
map<int, int> e;

void init() {
    for(int i=2; i<=1000000; i++) {
        if(!vis[i])
        for(int j=2; i*j<=1000000; j++) {
            vis[i*j] = i;
        }
    }
    for(int i=2; i<=1000000; i++) {
        int rr = i;
        while(rr) {
            int s = vis[rr];
            r[i].push_back(s);
            while(!(rr%s) && rr) rr /= s;
        }
    }
}

int block_siz;

struct query {
    int l, r;
    int bl, br;
    int id, ans;
    void init(cint x) {
        id = x;
        cin >> l >> r;
        bl = l / block_siz;
        br = r / block_siz;
    }
} b[200200];

bool cmp1(const query&a, const query&b) {
    return a.bl == b.bl ? ( a.bl&1 ? a.r < b.r : a.r > b.r) : a.bl < b.bl;
}

void add(cint x) {
    for(int v: r[x]) e[v]++;
}

void del(cint x) {

}

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> t;
    init();
    while(t--) {
        mx = 0;
        e.clear();
        cin >> n >> q;
        block_siz = n / sqrt(q);
        for(int i=1; i<=n; i++) cin >> a[i];
        for(int i=1; i<=q; i++) b[i].init(i);
        sort(b+1, b+1+q, cmp1);
        int l = 1, r = 0;
        for(int i=1; i<=q; i++) {
            while(r < b[i].r) ++r, add(r);
            while(l > b[i].l) --l, add(l);
            while(r > b[i].r) --r, del(r+1);
            while(l < b[i].l) ++l, del(l-1);
        }
    }
    return 0;
}