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

int n;
int a[200200];
int mp[2500010];
int q[2500001][2], cnt;
int ans[4];

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=n && !ans[0]; i++)
        for(int j=n; j>i && !ans[0]; j--) {
            int r = a[j] - a[i];
            if(mp[abs(r)]) {
                int e = mp[abs(r)];
                if(q[e][0] != i && q[e][1] != j && q[e][1] != i) {
                    ans[0] = q[e][0];
                    ans[1] = q[e][1];
                    ans[2] = i;
                    ans[3] = j;
                    break;
                }
            } else {
                q[++cnt][0] = i, q[cnt][1] = j;
                mp[abs(r)] = cnt;
            }
        }
    if(!ans[0]) cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        if((a[ans[0]] - a[ans[1]]) != (a[ans[2]] - a[ans[3]])) swap(ans[0], ans[1]);
        cout << ans[0] << ' ' << ans[3] << ' ' << ans[1] << ' ' << ans[2] << endl;
        cout << endl;
    }
    return 0;
}