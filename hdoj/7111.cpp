#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;
typedef __int128_t in8;

const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

const int mx_n = 2000000;
int n, q;
int vis[mx_n+1000];
int prim[100010], cnt;
int mx_pri[mx_n+1000];
ull ans[mx_n+10];
ull to[mx_n];

void sol_max() {
    for(int i=1; i<=cnt; i++)
        for(int j=0; j<=n; j+=prim[i])
            mx_pri[j] = max(mx_pri[j], prim[i]);
}

void init() {
    to[0] = 1;
    for(int i=1; i<=mx_n; i++) {
        to[i] = to[i-1] * (ull)23333;
    }
}

void debug() {
    for(int i=1; i<=n; i++)
        cout << ans[i] << ' ';
        cout << endl;
}

void debug1() {
    for(int i=1; i<=n; i++)
        cout << mx_pri[i] << ' ';
        cout << endl;
}

int main() {
    init();
    int t;
    scanf("%d",&t);
    while(t--) {
        cnt = 0;
        for(int i=0; i<=n; i++) ans[i] = mx_pri[i] = 0;
        scanf("%d%d", &n, &q);
        int tmp;
        bool flag = 0;
        int mx = 0;
        for(int i=1; i<=q; i++) {
            scanf("%d", &tmp);
            prim[++cnt] = tmp;
            if(tmp <= n) { vis[tmp] = tmp; mx = max(mx, tmp);}
            else flag = 1;
        }
        // sort(prim+1, prim+1+cnt);
        sol_max();
        // debug1();
        mx_pri[0] = mx;
        int r = 1, rr = 0;
        int pre = 0;
        if(!flag)
        for(int i=0; i<=n; i++) {
            if(rr < i) { rr = r; ++pre; }
            if(i <= rr) {
                ans[i] = pre;
                r = max(r, i+mx_pri[i]-1);
            }
        }
        ull as = 0;
        if(flag)
        for(int i=1; i<=n; i++) {
            as = (as + to[n-i]);
        }
        if(!flag)
        for(int i=1; i<=n; i++) {
            as = (as + ans[i]*to[n-i]);
        }
        // debug();
        printf("%llu\n", as);
    }
    return 0;
}
/*
3
6 2
2
3
6 2
2
3
6 2
2
3
*/