#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&

int n;
int a[100100];

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a+1, a+1+n);
    while(a[1] != a[n]) {
        for(int i = n; i > 1; i--) {
            a[i] %= a[1];
            if(!a[i]) a[i] = a[1]; 
        }
        sort(a+1, a+1+n);
    }
    cout << a[1];
    return 0;
}