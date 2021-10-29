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

ll n, m, sum_q;
ll r;
ll dp[300300];
ll id[300300], cnt;
ll d[505], k[505], c[505];

void debug() {
    cout << endl;
    cout << cnt << endl;
    for(int i=1; i<=10; i++)
        cout << id[i] << ' ';
        cout << endl;
    for(int i=1; i<=10; i++)
        cout << dp[i] << ' ';
    cout << endl;
}

int main() {
    scanf("%lld%lld%lld", &n, &m, &r);
    for(int i=1; i<=n; i++) scanf("%lld%lld%lld", &d[i], &k[i], &c[i]);
    int p, q;
    for(int i=1; i<=m; i++) {
        scanf("%d%d", &p, &q);
        sum_q += q;
        for(int j=1; j<=q; j++) id[++cnt] = p;
    }
    sort(id+1, id+1+cnt);
    for(int i=1; i<=sum_q; i++) dp[i] = inf_ll;
    dp[0] = 0;
    int pt = 1;
    for(int i=0; i<sum_q; i++) {
        dp[i+1] = min(dp[i+1], dp[i] + r);
        for(int j=1; j<=n; j++) {
            // int s1 = upper_bound(id+1, id+1+cnt, min(id[i], id[i+1]-1)+d[j]) - id-1;
            while(id[i+1]+d[j] > id[pt] && pt <= sum_q) ++ pt;
            int s2 = i+k[j];
            // if(i == 7)
            //     cout << pt << "+++" << s2 << endl;
            dp[min(pt-1, s2)] = min(dp[min(pt-1,s2)], dp[i]+c[j]);
        }
    }
    // debug();
    printf("%lld\n", dp[sum_q]);
    return 0;
}
/*
1 1 11
1 1 111
1 2
*/