#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&
#define Pi acos(-1)

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int a;
int b;

int main() {
    srand(time(0));
    for(int i=1; i<=100000; i++) {
        a = rand();
        b = rand();
        assert(a+b==(a&b)+(a|b));
    }
    return 0;
}