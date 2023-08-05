#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <string>
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

int t, n;
int a[1010];
int son[1010][2];

void sol() {
    for(int i=2; i<=n; i++) {
        if(a[i] == 1) {
            son[i-1][0] = i;
        } else if(a[i] == a[i-1]+1) {
            son[i-1][1] = i;
        } else {
            for(int j=i-1; j>=1; j--)
                if(a[i] == a[j]+1 && !son[j][1]) {
                    son[j][1] = i;
                    break;
                }
        }
    }
}

void dfs(cint loc, string ans) {
    if(!loc) return;
    cout << ans << a[loc] << endl;
    dfs(son[loc][0], ans + to_string(a[loc]) + '.');
    dfs(son[loc][1], ans);
}

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i=1; i<=n; i++) cin >> a[i];
        for(int i=1; i<=n; i++) son[i][0] = son[i][1] = 0;
        sol();
        dfs(1, "");
    }
    return 0;
}
/*
1
4
1
1
2
2
*/