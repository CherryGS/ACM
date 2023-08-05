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

int t;
int a, b;

int main() {
    cin >> t;
    string s;
    while(t--) {
        cin >> a >> b >> s;
        int ls = -10000;
        int ans = 0;
        for(int i=0; i<s.length(); i++)
            if(s[i] == '1') {
                ans += min((i-ls-1)*b, a);
                ls = i;
            }
        cout << ans << endl;
    }
    return 0;
}