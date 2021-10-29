#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

const int mx_n = 10000000;
int n, q;
int vis[mx_n+1000];
int prim[mx_n+1000], cnt;
int mx_pri[mx_n+1000];

void liner_sieve(cint x) {
    for(int i=2; i<=x; i++) {
        if(!vis[i]) {
            prim[++cnt] = i;
            vis[i] = i;
        }
        for(int j=1; j<=cnt; j++) {
            if(1ll*prim[j]*i > x) break;
            if(prim[j] > vis[i]) break;
            vis[prim[j]*i] = prim[j];
        }
    }
}

void sol_max(cint x) {
    for(int i=2; i<=x; i++) {
        int ii = i;
        while(vis[ii] != ii) ii /= vis[ii];
        mx_pri[i] = ii;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    liner_sieve(n);
    sol_max(n);
    int tmp;
    for(int i=2; i<=n; i++)
        cout << mx_pri[i] << ' ';
    cout << endl;
    return 0;
}