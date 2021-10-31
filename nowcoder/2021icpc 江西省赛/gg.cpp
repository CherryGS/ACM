#include <bits/stdc++.h>
using namespace std;
vector<int> r[1001000];
int vis[1001000];
int sum[1001000];
int mx;

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
            if(s == 0) { {if(rr != 1) r[i].push_back(rr);} break; }
            r[i].push_back(s);
            while(!(rr%s) && rr) rr /= s;
        }
    }
    // for(int i: r[10000]) cout << i << " --- " << endl;
}

template <typename Tp>
void read(Tp &x) {
    x = 0;
    bool f = true; char ch = getchar();
    for ( ; ch < '0' || ch > '9'; ch = getchar()) f ^= ch == '-';
    for ( ; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + (ch ^ 48);
    x = f ? x : -x;
}

const int N = 1e5;

int a[N + 5], b[N + 5], cnt[N + 5], bel[N + 5];
int ans[N + 5], anss;
int to[N+5];

struct Query {
    int l, r, id;
    bool operator < (const Query &s) const {
        return bel[l] == bel[s.l] ? r < s.r : l < s.l;
    }
};
Query que[N + 5];
set<int> ss;

void add(int x) {
    for(int v: r[to[a[x]]]) {
        sum[v]++;
        if(sum[v] == 1) ss.insert(v);
        anss = max(anss, sum[v]);
    }
}

void del(int x) {
    for(int v: r[to[a[x]]]) {
        sum[v]--;
        if(!sum[v]) ss.erase(sum[v]);
    }
}

int main() {
    int T;
    read(T);
    init();
    while(T--) {
        anss = 0;
        int n, q;
        read(n), read(q);
        int m = sqrt(n);
        for (int i = 1; i <= n; ++i) {
            read(a[i]);
            b[i] = a[i];
            bel[i] = (i - 1) / m + 1;
        }
        std::sort(b + 1, b + n + 1);
        int k = std::unique(b + 1, b + n + 1) - (b + 1);
        for (int i = 1; i <= n; ++i) {
            int r = std::lower_bound(b + 1, b + k + 1, a[i]) - b;
            to[r] = a[i];
            a[i] = r;
        }
        for (int i = 1; i <= q; ++i) {
            read(que[i].l), read(que[i].r);
            que[i].id = i;
        }
        std::sort(que + 1, que + q + 1);
        int l, r, L;
        for (int i = 1; i <= q; ++i) {
            if (bel[que[i].l] != bel[que[i - 1].l]) {
                for(auto k: ss) { sum[k] = 0; }
                ss.clear();
                anss = 0;
                L = bel[que[i].l] * m;
                l = L + 1, r = L;
            }
            if (bel[que[i].l] == bel[que[i].r]) {
                for (int j = que[i].l; j <= que[i].r; ++j) add(j);
                ans[que[i].id] = anss;
                for (int j = que[i].l; j <= que[i].r; ++j) del(j);
                anss = 0;
            }
            else {
                for ( ; r < que[i].r; ++r, add(r));
                long long cur = anss;
                for ( ; l > que[i].l; --l, add(l));
                ans[que[i].id] = anss;
                for ( ; l <= L; del(l), ++l);
                anss = cur;
            }
        }
        while(l <= r) {del(l); ++l;}
        for (int i = 1; i <= q; ++i)
            printf("%d\n", ans[i]);
    }
    return 0;
}
/*
1
10 1
20 15 6 1 21 12 2 3 17 9
4 7

*/