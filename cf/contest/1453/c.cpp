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

int t, n;
int a[2020][2020];
int loc[5][10];
int ans[10];
// 1,3 row 2,4 column

int main() {
    char tmp;
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++) {
                cin >> tmp; a[i][j] = tmp-'0';
            }
        memset(loc, -1, sizeof loc);
        memset(ans, 0, sizeof ans);
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                for(int k=1; k<=4; k++) {
                    int r = a[i][j];
                    if(loc[k][r]<0) {
                        if(k&1) loc[k][r] = i;
                        else loc[k][r] = j;
                    } else {
                        if(k==2) loc[k][r] = min(loc[k][r],j);
                        if(k==3) loc[k][r] = max(loc[k][r],i);
                        if(k==4) loc[k][r] = max(loc[k][r],j);
                    }
                }
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++) {
                int r = a[i][j];
                ans[r] = max(ans[r], max(j-1,n-j)*max(i-loc[1][r],loc[3][r]-i));
                ans[r] = max(ans[r], max(i-1,n-i)*max(j-loc[2][r],loc[4][r]-j));
            }
        for(int i=0; i<=9; i++) cout << ans[i] << ' ';
        cout << endl;
    }
    return 0;
}