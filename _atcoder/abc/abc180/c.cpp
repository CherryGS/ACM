#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&
#define Pi acos(-1)

ll n;
ll arr[10010000], cnt;

int main() {
    cin >> n;
    for(ll i = 1; i * i <= n; i++) 
        if(!(n%i)) {
            cout << i << ' ';
            if(n/i != i)arr[++cnt] = n/i;
        }
    while(cnt) {cout << arr[cnt--] << ' ';}
    return 0;
}