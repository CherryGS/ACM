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
int a[2020];

int main() {
    cin >> t;
    while(t--) {
        int pre = 0, tmp = 0;
        bool flag = 0;
        cin >> n;
        for(int i=1; i<=n; i++) { cin >> a[i]; pre ^= a[i]; }
        for(int i=1; i<n; i++) {
            tmp ^= a[i];
            if(tmp == pre) {
                int tmp1 = 0;
                for(int j=i+1; j<=n; j++) {
                    tmp1 ^= a[j];
                    if(tmp1 == pre) { flag = 1; break; }
                }
                break;
            }
        }
        if(!pre || flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}