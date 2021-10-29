#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
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
int ans;
int q[100010], cnt;

int main() {
    ios::sync_with_stdio(false);
    int a, b, c;
    cin >> t;
    while(t--) {
        c = cnt = b = ans = 0;
        cin >> n;
        for(int i=1; i<=n; i++) {
            cin >> a;
            if(a > 200) ++ans;
            else if(a==100) ++b;
            else q[++cnt] = a;
        }

        sort(q+1, q+1+cnt);
        int l=1;
        while(cnt >= l) {
            if(q[cnt]+q[l] <= 300 && l!=cnt) {
                --cnt; ++l; ++ans;
            } else if(b) {
                --cnt; --b; ++ans;
            } else {
                --cnt; ++ans;
            }
        }
        ans += (b+2)/3;
        cout << ans << endl;
    }
    return 0;
}