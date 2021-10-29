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

ll n;

int main() {
    ll s1 = ceil(n/2);
    ll s2 = n/2;
    string ans;
    for(int i=1; i<=n; i++) {
        if(i <= s1) ans += 'b';
        else ans += 'r';
    }
    int num = 1;
    cout << s1*s2 << endl;
    cout << ans << endl;
    for(int i=s1-1; i; i--) {
        int r = i;
        while(r < n-1) {
            swap(ans[r], ans[r+1]);
            ++r;
            ++sum;
            cout << ans << endl;
            if(sum > 100) return 0;
        }
    }
    if(sum < 100) {
        cout 
    }
    return 0;
}