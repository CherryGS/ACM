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
int s[4];

int main() {
    cin >> t;
    while(t--) {
        for(int i=0; i<4; i++) cin >> s[i];
        if(s[0] > s[2] && s[0] > s[3] && s[1] > s[2] && s[1] > s[3]) cout << "NO" << endl;
        else if(s[0] < s[2] && s[0] < s[3] && s[1] < s[2] && s[1] < s[3]) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}