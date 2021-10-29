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

int t, n;

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        if(n == 1) { cout << 'a' << endl; continue;}
        int i=1;
        for( ; i<=n/2; i++)
            cout << 'b';
        if(n&1) i+=2, cout << "ac";
        else i++, cout << "c";
        for(; i<=n; i++) cout << 'b';
        cout << endl;
    }
    return 0;
}