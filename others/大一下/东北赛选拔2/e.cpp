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

int n, m;
int mx[1010][1010];

int main() {
    ios::sync_with_stdio(false);
    memset(mx, 0x3f, sizeof mx);
    int a, b;
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cin >> a >> b;
            mx[i][a] = min(mx[i][a], b);
        }
        for(int j=1000; j>=1; j--)
            mx[i][j] = min(mx[i][j], mx[i][j+1]); 
    }
    double ans = 9999999.999;
    int ans2;
    for(int i=1; i<=1000; i++) {
        double sum = 0;
        for(int j=1; j<=n; j++) {
            sum += mx[j][i];
        }
        if(ans > double(sum/i)) {
            ans = double(sum/i);
            ans2 = sum;
        }
    }
    cout << ans2 << endl;
    return 0;
}