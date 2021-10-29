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

int a, b, k;

int main() {
    cin >> a >> b >> k;
    if(a < k) {
        cout << "No" << endl;
    } else if((b == 1 && k != 0) || b == 0) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
        if(k == 0) {
            for(int i=1; i<=b; i++) cout << '1';
            for(int i=1; i<=a; i++) cout << '0';
            cout << endl;
            for(int i=1; i<=b; i++) cout << '1';
            for(int i=1; i<=a; i++) cout << '0';
            cout << endl;
        } else {
            cout << '1' << '1';
            for(int i=1; i<=k; i++) cout << '0';
            for(int i=1; i<=b-2; i++) cout << '1';
            for(int i=1; i<=a-k; i++) cout << '0';
            cout << endl;
            cout << '1';
            for(int i=1; i<=k; i++) cout << '0';
            for(int i=1; i<=b-1; i++) cout << '1';
            for(int i=1; i<=a-k; i++) cout << '0';
            cout << endl;
        }
    }
    return 0;
}