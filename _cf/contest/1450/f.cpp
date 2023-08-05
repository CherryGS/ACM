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
int a[100100];

int main() {
    cin >> t;
    while(t--) {
        int r;
        cin >> n;
        memset(a, 0, sizeof a);
        for(int i=1; i<=n; i++) {
            cin >> r;
            ++a[r];
        }
        int ans=0;
        for(int i=1; i<=n-1; i++) {
            if(a[i]*2-1 > n) { ans = -1; break; }
            if(a[i]-1 >= a[i+1]) { a[i+1] = 0; a[i]-=a[i+1]+1;}
            else { a[i+1]-=a[i]+1; a[i]=0; }
            ans += a[i];
        }
        ans += a[n];
        cout << ans << endl;
    }
    return 0;
}