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

struct stu {
    ll num, id;
    bool operator < (const stu&a) const {
        return num < a.num; 
    }
    void init(ll x) {
        id = x;
        cin >> num;
    }
} a[100100];

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i=1; i<=n; i++) a[i].init(i);
        sort(a+1, a+1+n);
        int ans = 0;
        for(int i=1; i<=n; i++) {
            for(int j=i+1; j<=n; j++) {
                if(a[i].num * a[j].num > 2*n) break;
                if(a[i].num*a[j].num == a[i].id+a[j].id) ++ans;
            }
        }
        cout << ans << endl;
    }
    return 0;
}