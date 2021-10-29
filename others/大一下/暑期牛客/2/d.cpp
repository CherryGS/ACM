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
int a1, b1, a2, b2;

int main() {
    cin >> t;
    while(t--) {
        cin >> a1 >> b1 >> a2 >> b2;
        if(a1 > b1) swap(a1, b1);
        if(a2 > b2) swap(a2, b2);
        if(a1 == 2 && b1 == 8) {
            if(a2 == 2 && b2 == 8) cout << "tie" << endl;
            else cout << "first" << endl;
        }
        else if(a2 == 2 && b2 == 8) {
            cout << "second" << endl;
        }
        else if(a1 == b1) {
            if(a2 == b2) {
                if(a1 == a2) cout << "tie" << endl;
                else if(a1 > a2) cout << "first" << endl;
                else cout << "second" << endl;
            } else cout << "first" << endl;
        }
        else if(a2 == b2) {
            cout << "second" << endl;
        }
        else if((a1+b1)%10 != (a2+b2)%10) {
            if((a1+b1)%10 > (a2+b2)%10) cout << "first" << endl;
            else cout << "second" << endl;
        } else {
            if(b1 > b2) cout << "first" << endl;
            else if(b1 == b2) cout << "tie" << endl;
            else cout << "second" << endl;
        }
    }
    return 0;
}