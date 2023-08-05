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

int t, n, m;
int a[101][101];

int main() {
    cin >> t;
    while(t--) {
        cin >> n >> m;
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
                cin >> a[i][j];
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
                if(a[i][j] == a[i][j-1] || a[i][j] == a[i-1][j]) ++a[i][j];
    }
    return 0;
}