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
char s[11];

int main() {
    cin >> t;
    while(t--) {
        cin >> s;
        int a[2][3];
        memset(a, 0, sizeof a);
        for(int i=0; i<10; i++) {
            if(s[i] == '0') a[i&1][0]++;
            else if(s[i] == '1') a[i&1][1]++;
            else a[i&1][2]++;
            if(a[0][1]+a[0][2]-a[1][1] > (9-i+!(i&1))/2) {
                cout << i+1 << endl;
                break;
            }
            else if(a[1][1]+a[1][2]-a[0][1] > (9-i)/2) {
                cout << i+1 << endl;
                break;
            }
            if(i == 9) cout << 10 << endl;
        }
    }
    return 0;
}