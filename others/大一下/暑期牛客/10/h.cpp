#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n;
bool ans[1000100];
bool vis[1000100];
int pre;

void dfs(cint x, bool st) {
    ans[x] = st;
    vis[x] = 1;
    pre += st;
    for(int i=0; i<n; i++)
        if(x&(1<<i) && !vis[x^(1<<i)]) dfs(x^(1<<i), st^1);
}

int main() {
    cin >> n;
    dfs((1<<n)-1, 0);
    if((pre<<1) == (1<<n)) ans[0] ^= 1;
    for(int i=0; i<(1<<n); i++)
        cout << ans[i];
    cout << endl;
    return 0;
}