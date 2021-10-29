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

int t;
int n;
vector<int> q[200100];
int u[200100], s[200100];
ll ans[200100];
ll sum[200100];

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i=1; i<=n; i++) ans[i] = 0;
        for(int i=1; i<=n; i++) cin >> u[i];
        for(int i=1; i<=n; i++) cin >> s[i];
        for(int i=1; i<=n; i++) q[u[i]].push_back(-s[i]);
        for(int i=1; i<=n; i++) sort(q[i].begin(), q[i].end());

        for(int i=1; i<=n; i++) {
            int k = q[i].size();
            if(!k) continue;
            sum[1] = q[i][0];
            for(int j=2; j<=k; j++) {
                sum[j] = sum[j-1]+q[i][j-1];
            }
            for(int j=1; j<=k; j++) {
                int r = k%j;
                ans[j] += sum[k-r];
            }
            q[i].clear();
        }
        for(int i=1; i<=n; i++) cout << -ans[i] << ' ';
        cout << endl;
    }
    return 0;
}