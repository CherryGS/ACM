#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int t, n;
char s[20020];

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        cin >> s;
        int st = -1;
        for(int i=0; i<n; i++)
            if(s[i] == '0') {
                st = i;
                break;
            }
        if(st == -1) {
            cout << 1 << ' ' << n-1 << ' ' << 2 << ' ' << n << endl;
        } else {
            if(st > n-1-st) {
                cout << 1 << ' ' << st+1 << ' ' << 1 << ' ' << st << endl;
            }
            else {
                cout << st+1 << ' ' << n << ' ' << st+2 << ' ' << n << endl;
            }
        }
    }
    return 0;
}