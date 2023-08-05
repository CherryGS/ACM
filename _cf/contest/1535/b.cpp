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
int a;
int q[2002], cnt;

int gcd(cint x, cint y) {
    if(y == 0) return x;
    return gcd(y, x%y);
}
vector<int> e;

int main() {
    cin >> t;
    while(t--) {
        e.clear();
        cin >> n;
        for(int i=1; i<=n; i++) {
            cin >> a;
            if(a&1) q[++cnt] = a;
            else e.push_back(a);
        }
        while(cnt) { e.push_back(q[cnt--]); }
        int ans = 0;
        for(int i=1; i<e.size(); i++)
            for(int j=i-1; j>=0; j--) {
                if(gcd(2*e[i], e[j]) > 1) ++ ans;
            }
        cout << ans << endl;
    }
    return 0;
}