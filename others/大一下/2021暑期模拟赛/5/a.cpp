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

int n;
int num[202];

int main() {
    char s;
    cin >> n;
    bool flag = 0;
    for(int i=1; i<=n; i++) {
        cin >> s;
        num[s-'a']++;
        if(num[s-'a'] >= 2) flag = 1;
    }
    if(flag || n == 1) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}