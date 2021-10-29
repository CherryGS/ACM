#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&
#define Pi acos(-1)

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n, m, k;
int a[50050];
int num[50050];
ll ans = 0;

int block_size;
struct query {
    int l, r, id, block_id, ans;

    void init(cint x) {
        id = x;
        cin >> l >> r;
        block_id = l / block_size;
    }

    bool operator < (const query&a) const {
        return block_id == a.block_id ? (r == a.r? 0: (block_id&1)^(r>a.r) ) : block_id < a.block_id;
    }
} s[50050];

void add(cint y) {
    int x = a[y];
    ans -= num[x]*num[x];
    ++num[x];
    ans += num[x]*num[x];
}

void del(cint y) {
    int x = a[y];
    ans -= num[x]*num[x];
    --num[x];
    ans += num[x]*num[x];
}

bool cmp(const query&a, const query&b) {
    return a.id < b.id;
}

int main() {
    cin >> n >> m >> k;
    block_size = n/sqrt(m);
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=m; i++) s[i].init(i);
    sort(s+1, s+1+m);

    int curL = 1, curR = 0;
    for(int i=1; i<=m; i++) {
        int L = s[i].l, R = s[i].r;
        while(curR < R) add(++curR);
        while(curL > L) add(--curL);
        while(curL < L) del(curL++);
        while(curR > R) del(curR--);
        s[i].ans = ans;
    }

    sort(s+1, s+1+m, cmp);

    for(int i=1; i<=m; i++) {
        cout << s[i].ans << endl;
    }

    return 0;
}