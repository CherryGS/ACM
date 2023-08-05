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
int num[2];

int main() {
    cin >> t;
    string s;
    while(t--) {
        int ans=0;
        memset(num, 0, sizeof num);
        cin >> s;
        for(int i=0; i<s.length(); i++) {
            if(s[i] == '(') ++num[0];
            else if(s[i] == '[') ++num[1];
            else if(s[i] == ')' && num[0]) ++ans, --num[0];
            else if(s[i] == ']' && num[1]) ++ans, --num[1];
        }
        cout << ans << endl;
    }
    return 0;
}