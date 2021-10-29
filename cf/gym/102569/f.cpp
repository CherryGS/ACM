#include <iostream>
#include <cstdio>
#include <algorithm>

int n;

using namespace std;
int main() {
    cin >> n;
    cout << (n >> 1) + 1 << endl;
    for(int i = 1; i <= n; i+=2) cout << i << ' ';
    if(!(n%2)) cout << n;
    return 0;
}