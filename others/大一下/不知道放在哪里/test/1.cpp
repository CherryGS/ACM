#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n, x;
int ans;
int cnt;

void dfs(cint loc) {
    ++cnt;
    if(loc == n) {
        ++ans;
        return;
    }
    for(int i=1; i<=x; i++) {
        if(loc+i <= n) dfs(loc+i);
    }
}

int main() {
    cin >> n >> x;
    dfs(0);
    cout << cnt << endl;
    // cout << ans << endl;
    return 0;
}