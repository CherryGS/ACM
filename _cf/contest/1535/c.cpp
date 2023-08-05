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
char s[200200];

int main() {
    cin >> t;
    while(t--) {
        cin >> s;
        int n = strlen(s);
        int le = 0, mid = 0, st = 2;
        ll ans = 0;
        for(int i=0; i<n; i++) {
            if(st != 2) {
                st ^= 1;
                if(s[i] != '?' && st != s[i]-'0') {
                    le = mid+1;
                    st = s[i]-'0';
                }
            }
            if(s[i] != '?') { st = s[i] - '0'; mid = i; }
            ans += i-le+1;
        }
        cout << ans << endl;
    }
    return 0;
}