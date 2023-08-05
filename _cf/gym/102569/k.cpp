#include <iostream>
#include <cstdio>
#include <algorithm>

#define ll long long

using namespace std;
int main() {
    ll a[5];
    cin >> a[1] >> a[2] >> a[3] >> a[4];
    sort(a+1, a+5);
    if(a[4] - a[3] == a[2] - a[1]) cout << "YES";
    else cout << "NO";
    return 0;
}