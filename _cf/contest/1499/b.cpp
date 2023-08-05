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
string s;

int main() {
    cin >> t;
    while(t--) {
        cin >> s;
        int le = s.length();
        bool ans = 0;
        bool flag = 0;
        for(int i=0; i<le; i++) {
            if(s[i] == s[i+1]) {
                if(s[i] == '1') flag = 1;
                else {
                    if(flag == 1) ans = 1;
                }
            }
        }
        if(!(ans)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}