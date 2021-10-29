#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&

int a[5];

int main() {
    for(int i = 1; i <= 4; i++) cin >> a[i];
    sort(a+1, a+5);
    if(a[1] + a[4] == a[2] + a[3]) cout << "Yes";
    else if(a[1] + a[2] + a[3] == a[4]) cout << "Yes";
    else cout << "No";
    return 0;
}