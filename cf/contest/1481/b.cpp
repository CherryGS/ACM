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

int t, n, k;
int h[101];

int main() {
    cin >> t;
    while(t--) {
        cin >> n >> k;
        for(int i=1; i<=n; i++) cin >> h[i];
        int mx = 0, sum = 0;
        for(int i=n; i>=1; i--)
            if(h[i] >= mx) mx = h[i];
            else sum += mx - h[i];
        if(k > sum) {
            cout << "-1" << endl;
            continue;
        }
        int flag = 0;
        for(int i=1; i<=k && !flag; i++) {
            for(int j=1; j<=n; j++) {
                if(j == n) {
                    flag = -1;
                    break;
                }
                if(i == k) flag = j;
                if(h[j] < h[j+1]) {
                    ++h[j];
                    break;
                }
            }
        }
        cout << flag << endl;
    }
    return 0;
}