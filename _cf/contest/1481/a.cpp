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
int px, py;
string s;

int main() {
    cin >> t;
    while(t--) {
        cin >> px >> py;
        cin >> s;
        int mxx = 0, mxy = 0;
        int mnx = 0, mny = 0;
        for(int i=0; i<s.length(); i++) {
            if(s[i] == 'U') ++mxy;
            else if(s[i] == 'D') --mny;
            else if(s[i] == 'R') ++mxx;
            else --mnx;
        }
        if(mnx <= px && px <= mxx && mny <= py && py <= mxy) cout << "YES" << endl;
        else cout << "NO" << endl; 
    }
    return 0;
}