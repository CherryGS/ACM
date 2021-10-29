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

int n, k;
int s[1001];

int main() {
    cin >> n >> k;
    int a, b;
    int n1 = 0;
    for(int i=1; i<=n; i++) {
        cin >> a >> b;
        if(a == 100) continue;
        if(a > b) {
            ++ s[(a-b+1)/2];
        } else ++n1;
    }
    for(int i=1; i<=101; i++) {
        while(s[i] && i <= k) {
            --s[i];
            ++n1;
            k -= i;
        }
        if(k < i) break;
    }
    if(n1*2 >= n) cout << "Make Byteland Great Again!" << endl;
    else cout << "Fake Polls!" << endl;
    return 0;
}