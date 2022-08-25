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

ll dp[505000][2];
int n;
int a[505000];

ll dfs(cint loc) {
    if(a[loc] > a[loc-1]) {
        dp[loc][]
    }
}

int main() {
    icn >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    dp[1][0] = a[1];
    dfs(n);
    return 0;
}