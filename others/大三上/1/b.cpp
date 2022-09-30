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

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

const int mx_n = 100000000;
bool vis[mx_n+1000];
int prim[mx_n+1000], cnt;
int to[mx_n+1000];

void liner_sieve() {
    int rt = 0, x = mx_n;
    vis[1] = 1;
    for(int i=2; i<=x; i++) {
        if(!vis[i]) {
            prim[++cnt] = i;
            to[i] = cnt;
        }
        for(int j=1; j<=cnt; j++) {
            if(1ll*prim[j]*i > x) break;
            vis[prim[j]*i] = 1;
            if(!(i%prim[j])) break;
        }
    }
}

bool solve(cint T) {
    int n = 100000000; 
    for(int i=1; i<=n; i+=2) {
        ll t = 1ll+i;
        while(t % 2 == 0) { t /= 2; }
        if(!vis[t]) {
            ll sum = 1;
            for(int j=to[t]-1; j>1; j--) {
                sum *= prim[j];
                if(sum+1 >= i) { break; }
            }
            if(sum == i) { cout << i << '\n'; }
        }
    }
    return true;
}

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    // std::cin >> T_;
    liner_sieve();
    for(int _T=1; _T<=T_; _T++) { if(solve(_T) == 0) { break; } }
    return 0;
}