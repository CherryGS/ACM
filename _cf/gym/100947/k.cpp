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

int a[1001][1001];
int b[1001][1001];
int q[1001000], cnt;
int t, n;

int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    while(t--) {
        cnt = 0;
        cin >> n;
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                cin >> a[i][j];
        for(int i=2; i<=2*n; i++) {
            for(int j=max(1,i-n); j<=i-1 && j<=n; j++) {
                if(i&1) {
                    q[++cnt] = a[j][i-j];
                } else {
                    q[++cnt] = a[i-j][j];
                }
            }
        }
        for(int i=0; i<n; i++) {
            for(int j=1; j<=n; j++) {
                cout << q[i*n+j] << ' ';
            }
            cout << endl;
        }

    }
    return 0;
}