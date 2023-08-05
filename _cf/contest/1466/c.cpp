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

int t;
string a;
int dp[100100][26];

int main() {
    cin >> t;
    while(t--) {
        int ans=0;
        cin >> a;
        int n = a.length();
        for(int i=0; i<n; i++) {
            if(i>0 && i<n-1)
                if(a[i-1] == a[i+1] && a[i-1] != '0') {
                    // cout << i << "---" << endl;
                    ++ans;
                    a[i+1] = '0';
                }
            if(i<n-1 && a[i] != '0')
                if(a[i] == a[i+1]) {
                    ++ans;
                    a[i+1] = '0';
                    // cout << i << "----" << endl;
                }
        }
        cout << ans << endl;
    }
    return 0;
}