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
int a, b, k;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> a >> b >> k;
        int aa = a;
        int bb = b;
        int sum = 0;
        for(int i=2; i<=sqrt(a); i++) {
            while(!(a%i)) {
                a /= i;
                ++sum;
            }
        }
        for(int i=2; i<=sqrt(b); i++) {
            while(!(b%i)) {
                b /= i;
                ++sum;
            }
        }
        if(a > 1) ++ sum;
        if(b > 1) ++ sum;
        if(sum < k) cout << "NO" << endl;
        else if(aa == bb) {
            if(k == 1) cout << "NO" << endl;
            else cout << "YES" << endl;
        }
        else if(!(aa%bb) || !(bb%aa)) {
            if(k == 0) cout << "NO" << endl;
            else cout << "YES" << endl;
        } else {
            if(k <= 1) cout << "NO" << endl;
            else cout << "YES" << endl;
        }
    }
    return 0;
}