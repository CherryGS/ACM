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

int t, n;
int a[200200];

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i=1; i<=n; i++) cin >> a[i];
        sort(a+1, a+1+n);
        int mx = 0, num = 1;
        for(int i=2; i<=n; i++) {
            if(a[i] != a[i-1]) num = 0;
            ++num;
            mx = max(mx, num);
        }
        cout << max(n&1, mx*2-n) << endl;
    }
    return 0;
}
/*
1
5
1 2 2 3 1
*/