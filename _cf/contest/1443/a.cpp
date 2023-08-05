#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&
#define Pi acos(-1)

int t;
int n;

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i=2*n; i>n; i--)
            cout << i*2 << ' ';
        cout << endl;
    }
    return 0;
}