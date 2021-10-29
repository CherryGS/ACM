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
char s[500500];

map<pair<int,int>, int> e;

int gcd(cint x, cint y) {
    return y == 0 ? x : gcd(y, x%y);
}

int main() {
    cin >> t;
    while(t--) {
        e.clear();
        cin >> n;
        cin >> s;
        int s1 = 0, s2 = 0;
        for(int i=0; i<n; i++) {
            if(s[i] == 'D') ++ s1;
            else ++ s2;
            int g = gcd(s1, s2);
            if(!g) g = s2;
            auto k = e.find({s1/g, s2/g});
            int ans = 1;
            if(k != e.end()) {ans += k -> second; k -> second = ans;}
            else e.insert({{s1/g, s2/g}, ans});
            cout << ans << ' ';
        }
        cout << endl;
    }
    return 0;
}