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
ll a[100];
ll ans[101];

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        n *= 2;
        for(int i=1; i<=n; i++) cin >> a[i];
        sort(a+1, a+1+n);
        int l = 1, r = n, cnt = 0;
        while(l<r) {
            ans[++cnt] = a[l++];
            ans[++cnt] = a[r--];
        }
        for(int i=1; i<=n; i++)
            cout << ans[i] << ' ';
        cout << endl;
    }
    return 0;
}