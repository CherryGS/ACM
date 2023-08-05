#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&
#define Pi acos(-1)

int n;
int f[100100][2];

int main() {
    int mx = 0, mn = 0x7ffffff, a;
    bool st = 0;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a;
        ++f[a][st];
        st ^= 1;
        mn = min(mn, a);
        mx = max(mx, a);
    }
    int t1=0, t2=0, t3=0, t4=0;
    int flag_1, flag_2;
    for(int i = mn; i <= mx; i++) {
        if(f[i][0] >= t1) {
            flag_1 = i;
            t2 = t1;
            t1 = f[i][0];
        } else if(f[i][0] >= t2) t2 = f[i][0];
        if(f[i][1] >= t3) {
            flag_2 = i;
            t4 = t3;
            t3 = f[i][1];
        } else if(f[i][1] >= t4) t4 = f[i][1];
    }
    if(flag_1 != flag_2) cout << n - t1 - t3;
    else cout << min(n-t1-t4, n-t2-t3);
    return 0;
}