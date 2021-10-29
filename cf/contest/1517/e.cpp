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

const int mod = 998244353;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n;
int a[200100];
ll ans = 0;
ll sum[200100];
ll e_sum[200100];

int main() {
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
        sum[i] += sum[i-1] + a[i];
        if(i&1) e_sum[i] += e_sum[i-1] + a[i];
        else e_sum[i] += e_sum[i-1] - a[i];
    }
    for(int i=1; i<=n; i++) {
        if(i&1) {
            int s;
            s = sum[n] - sum[i];
            int l, r, mid;
            ll pre;
            l = 1, r = i;
            while(l <= r) {
                mid = (l+r) >> 1;
                pre = e_sum[i] - e_sum[mid] - s;
                if(check(mid, 1, pre)) l = mid+1;
                else r = mid-1;
            }
            if(check(mid+1, 1, pre)) ++ mid;
            else if(!check(mid, 1)) -- mid;
            
        }
    }
    return 0;
}