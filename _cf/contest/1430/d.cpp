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

int t, n;
string a;
int num[200010], cnt;

int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    while(t--) {
        cin >> n;
        cin >> a;
        if(n == 1 || n == 2) {cout << 1 << endl;continue;}
        cnt = 0;
        for(int i = 0; i < n-1; i++)
            if(a[i] != a[i+1]) {
                num[++cnt] = i; //最后没有标记
            }
        num[++cnt] = n-1;
        int k = 0, up = 0, cnt_ = 0, del = 1, ans = 0;
        while(1){
            int len = 0;
            while(len <= 1&& up != n-1) {
                k = up;
                up = num[++cnt_];
                len = up - k;
            }
            while(len > 1 && del <= cnt_) {
                len--;
                del++;
                ans++;
            }
            if(up == n-1) {
                ans += ((cnt - del + 2) >> 1);
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}