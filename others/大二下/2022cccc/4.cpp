#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    ll a, b;
    cin >> a >> b;
    ll sum = 1;
    for(int i=1; i<=a+b; i++) { sum *= i; }
    cout << sum << endl;
}