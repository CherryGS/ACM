#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&
#define Pi acos(-1)

const int mod = 998244353;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int t, n;
queue<pair<int, int>> ans;

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        if(n > 8) {
            for(int i=9; i<n; i++) {
                ans.push(make_pair(i, i+1));
            }
            for(int i=1; i<n; i*=8) {
                ans.push(make_pair(n, 8));
            }
        }
        for(int i=3; i<min(8, n); i++) {
            ans.push(make_pair(i, i+1));
        }
        for(int i=1; i<min(8, n); i*=2) {
            ans.push(make_pair(min(8,n), 2));
        }

        cout << ans.size() << endl;
        while(!ans.empty()) {
            auto k = ans.front();
            cout << k.first << ' ' << k.second << endl;
            ans.pop();
        }
    }    
    return 0;
}
/*

*/