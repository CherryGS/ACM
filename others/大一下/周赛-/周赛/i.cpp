#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&
#define Pi acos(-1)

const int mod = 998244353;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n;
int dp[100100][2];
ll a[100100];
int num[100100];

int h[100100], nx[100100], to[100100], cnt;

void add(cint f, cint t) {
    nx[++cnt] = h[f];
    h[f] = cnt;
    to[cnt] = t;
}

int dfs(cint loc, cint fa) {
    if(!num[loc]) {
        dp[loc][0] = 0;
        if(a[loc] > a[fa]) dp[loc][1] = 1;
        else dp[loc][1]=0;
    }
    for(int i=h[loc]; i; i=nx[i]) {

    }
}

int main() {
    cin >> n;
    memset(dp, 0x3f, sizeof dp);
    int a;
    for(int i=2; i<=n; i++) {
        cin >> a;
        add(a, i);
        ++num[a];
    }
    dfs(1)
    return 0;
}