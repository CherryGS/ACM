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

int n;
char a[300300];
int sum[300300][2];

int main() {
    cin >> n >> a;
    for(int i=1; i<=n; i++) sum[i][0] = sum[i-1][0] + (a[i-1]=='W');
    for(int i=n; i>=1; i--) sum[i][1] = sum[i+1][1] + (a[i-1]=='E');
    int ans = 0x7fffffff;
    for(int i=1; i<=n; i++) ans = min(ans, sum[i-1][0]+sum[i+1][1]);
    cout << ans;
    return 0;
}