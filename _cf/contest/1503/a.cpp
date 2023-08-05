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
string s;
int ans[200200];

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        cin >> s;
        int z_num = 0;
        for(int i=0; i<n; i++)
            if(s[i] == '0') ++ z_num;
        if(z_num&1 || s[0] == '0' || s[n-1] == '0') {
            cout << "NO" << endl;
            continue;
        }
        int s1 = (n-z_num)/2, s2 = z_num/2;
        int s_one = 0;
        for(int i=0; i<n; i++) {
            if(s[i] == '1') {
                if(s1) {
                    -- s1;
                    ++ s_one;
                    ans[i] = 1;
                } else {
                    -- s_one;
                    ans[i] = 0;
                }
            } else {
                if(s_one && s2) {
                    -- s_one;
                    -- s2;
                    ans[i] = 0;
                } else {
                    ++ s_one;
                    ans[i] = 1;
                }
            }
        }
        cout << "YES" << endl;
        for(int i=0; i<n; i++) 
            if(ans[i] == 0) cout << ')';
            else cout << '(';
        cout << endl;
        for(int i=0; i<n; i++)
            if((s[i]-'0') ^ ans[i]) cout << ')';
            else cout << '(';
        cout << endl;
    }
    return 0;
}
/*
1
20
11101010101010101011
*/