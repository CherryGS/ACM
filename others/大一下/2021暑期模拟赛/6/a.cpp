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

char s[200200], t[200200];

int main() {
    cin >> s >> t;
    int ans = 0;
    int l = strlen(s);
    for(int i=1; i<=l; i++)
        if(s[i-1] != t[i-1]) ++ans;
        cout << ans << endl;
    return 0;
}