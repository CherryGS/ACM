#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cstdlib>
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


int main() {
    int t = 10;
    int r = t;
    while(t--) {
        printf("-------- Test: %d --------\n", r-t+1);
        system("make.exe > 1.in");
        system("ac.exe < 1.in > 1.ac");
        system("wa.exe < 1.in > 1.wa");
        if(system("fc 1.ac 1.wa")) {
            cout << "ERR" << endl;
            break;
        } else cout << "AC" << endl;
        printf("-------------------------\n");
    }

    return 0;
}