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

const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n, k;
ll mod;
int a[40001];
int to[80080];
int pr_to[80080];
int prime[80080], cnt;
int phi[80080];
ll ans = 0;
ll C[40001][31];
vector<int> q[8000];

void init() {
    phi[1] = 1;
    for(int i=2; i<=80000; i++) {
        if(!to[i])  {
            phi[i] = i-1;
            pri[++cnt] = i;
        }
        
        for(int j=1; j<=cnt; j++) {
            if(1ll*i*pri[j] > 80000) break;
            to[i*pri[j]] = pri[j];
            if (i % pri[j]) {
                phi[i * pri[j]] = phi[i] * (pri[j] - 1);
            } else {
                phi[i * pri[j]] = phi[i] * pri[j];
                break;
            }
    }
}

void ins_init() {
    for(int i=0; i<=n; i++) C[i][0] = 1;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=k && j<=i; j++) {
            C[i][j] = (C[i-1][j]+C[i-1][j-1]) % phi[p];
        }
    }
}

ll ksm(ll bs, int x) {
    ll ans = 1;
    while(x) {
        if(x&1) ans = (ans*bs) % mod;
        bs = (bs*bs) % mod;
        x >>= 1;
    }
    return ans;
}

void deal(cint x) {
    int r = a[x];
    int num = 0;
    int lr = 0;
    while(r) {
        if(num && lr != to[r]) {
            q[pr_to[lr]].push_back(num);
            num = 0;
        }
        ++num;
        lr = to[r];
        if(r == 1) break;
        r /= to[r];
    }
}

void debug() {
    cout << endl;
    cout << n << ' ' << k << ' ' << mod << endl;
}

int main() {
    freopen("f.in", "r", stdin);
    int t;
    init();
    // cout << cnt << endl;
    scanf("%d", &t);
    while(t--) {
        ans = 1;
        scanf("%d%d%lld", &n, &k, &mod);
        ins_init();
        for(int i=1; i<=n; i++) scanf("%d", &a[i]);
        for(int i=1; i<=cnt; i++) q[i].clear();
        for(int i=1; i<=n; i++) deal(i);
        for(int i=1; i<=n; i++) if(q[i].size()) sort(q[i].begin(), q[i].end());
        for(int i=1; i<=cnt; i++) if(q[i].size() >= k){
            int siz = q[i].size();
            for(int l=1; l<=siz-k+1; l++) {
                    ans *= ksm(ksm(prime[i], q[i][l-1]), C[siz-l][k-1]);
                    ans %= mod;
                } 
        }
        // debug();
        printf("%lld\n", ans);
    }   
    return 0;
}
/*
1
5 1 200000000
4 4 4 4 4
*/