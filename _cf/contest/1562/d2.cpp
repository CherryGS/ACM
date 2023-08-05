#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int t, n, q;
char s[300300];
int sum[300300];

const int bs = 300000;
vector<int> e[600001];

void debug(cint l, cint r) {
    int sum = 0;
    for(int i=l-1; i<r; i++) {
        int r = (s[i] == '+' ? 1 : -1 ) * (i&1 ? 1 : -1);
        sum += r;
    }
    cout << "----" <<  sum << endl;
}

void sol(cint l, cint r) {
    // cout << l << "---" << r << endl;
    int rr = sum[r] - sum[l-1];
    int rs = rr/2+ (rr < 0 ? -1 : 1) + sum[l-1] ;
    // cout << rs << "----" << sum[l-1] << ' ' << rr << endl;
    // if(l > 1) {
    //     rs = sum[l-2] + (l&1 ? rs : -rs);
    // }
    int id = lower_bound(e[rs+bs].begin(), e[rs+bs].end(), l) - e[rs+bs].begin();
    // cout << id << ' ' << e[rs+bs].size() << ' ' << rs+bs << endl;
    // cout << e[rs+bs][id] << ' ';
    printf("%d ", e[rs+bs][id]);
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &q);
        scanf("%s", &s);
        int l, r;
        for(int i=0; i<=n; i++) sum[i] = 0;
        for(int i=0; i<=n; i++) {
            e[bs+i].clear();
            e[bs-i].clear();
        }
        for(int i=1; i<=n; i++) {
            int r = (s[i-1] == '+' ? 1 : -1 ) * (i&1 ? 1 : -1);
            sum[i] += r;
            if(i) sum[i] += sum[i-1];
            e[bs+sum[i]].push_back(i);
            // cout << sum[i] << ' ';
        }
        // cout << endl;
        for(int i=1; i<=q; i++) {
            scanf("%d%d", &l, &r);
            // debug(l, r);
            int rr = sum[r]-sum[l-1];
            rr = abs(rr);
            if(rr == 0) putchar('0');
            else if(rr & 1) {
                putchar('1');
                putchar('\n');
                sol(l, r);
            }
            else {
                putchar('2');
                putchar('\n');
                sol(l, r-1);
                printf("%d", r);
            }
            putchar('\n');
        }
    }
    return 0;
}
/*
1
14 3
+--++---+++---
1 14
6 12
*/