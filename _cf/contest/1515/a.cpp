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
int n, x;
int w[101];

int main() {
    cin >> t;
    while(t--) {
        bool flag = 0;
        cin >> n >> x;
        for(int i=1; i<=n; i++) cin >> w[i];
        int sum = 0;
        for(int i=1; i<=n; i++) {
            sum += w[i];
            if(sum == x) {
                if(i == n) flag = 1;
                else swap(w[i], w[i+1]);
            }
        }
        if(flag) cout << "NO" << endl;
        else {
            cout << "YES" << endl;
            for(int i=1; i<=n; i++) cout << w[i] << ' ';
            cout << endl;
        }
    }
    return 0;
}