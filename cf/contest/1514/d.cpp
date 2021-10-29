#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&
#define Pi acos(-1)

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n, q;
int a[300010];
int block_size;
int isAP[300100];
int val_sum[300100], max_sum;

struct query {
    int l, r, id, ans;
    int block_id;
    bool operator < (const query&a) const {
        if(block_id == a.block_id) return r < a.r;
        return block_id < a.block_id;
    }
    void init(cint x) {
        scanf("%d%d", &l, &r);
        id = x;
        block_id = l / block_size;
    }
} s[300100];

void add(cint x) {
    // int &r = isAP[a[x]];
    --val_sum[isAP[a[x]]];
    ++isAP[a[x]];
    ++val_sum[isAP[a[x]]];
    if(isAP[a[x]] > max_sum) max_sum = isAP[a[x]];
}

void del(cint x) {
    --val_sum[isAP[a[x]]];
    --isAP[a[x]];
    ++val_sum[isAP[a[x]]];
    if(!val_sum[max_sum]) --max_sum;
}

bool cmp(const query&a, const query&b) {
    return a.id < b.id;
}

int main() {
    scanf("%d%d", &n, &q);
    val_sum[0] = 1;
    block_size = 450;
    for(int i=1; i<=n; i++) { scanf("%d", &a[i]); }
    for(int i=1; i<=q; i++) { s[i].init(i); }
    sort(s+1, s+1+q);

    int curL = 1, curR = 0;
    for(int i=1; i<=q; i++) {
        int L = s[i].l, R = s[i].r;
        while(curR < R) add(++curR);
        while(curL > L) add(--curL);
        while(curR > R) del(curR--);
        while(curL < L) del(curL++);
        s[i].ans = max(1, max_sum*2-(R-L+1));
    }

    sort(s+1, s+1+q, cmp);

    for(int i=1; i<=q; i++) {
        printf("%d\n", s[i].ans);
    }

    return 0;
}