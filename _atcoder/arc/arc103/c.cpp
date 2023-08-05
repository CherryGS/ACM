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

int n;
char a[100100];
int lin[100100];

bool check() {
    for(int i = 0; i <= n/2; i++)
        if(a[i] != a[n-1-i-1]) return 1;
    return 0;
}

void solve() {
    for(int i = 1; i <= n; i++) lin[i] = i;
    for(int i = 1; i < n; i++) 
        if(a[i-1] == '1') lin[lin[i]] = i+1;
        else lin[i+1] = lin[lin[i]];
    for(int i = 1; i <= n-1; i++)
        if(i != lin[i]) cout << i << ' ' << lin[i] << endl;
}

int main() {
    cin >> a;
    n = strlen(a);
    if(a[0]=='0' || a[n-1]=='1' || a[n-2]=='0' || check()) cout << -1;
    else solve();
    return 0;
}