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

int q;
char s[100100], t[100100];

int main() {
    cin >> q;
    while(q--) {
        cin >> s;
        cin >> t;
        int le1 = strlen(s), le2 = strlen(t);
        int r = le1-1;
        bool flag = 0;
        for(int i=le2-1; i>=0; i--) {
            while(r >= 0 && t[i] != s[r]) {
                r -= 2;
            }
            if(!i && r >= 0) flag = 1;
            r--;
            if(r < 0) break;
        }
        if(flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
/*
1
abcde
abc
*/