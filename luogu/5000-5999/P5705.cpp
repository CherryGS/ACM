#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
int main() {
    string a;
    cin >> a;
    int f = a.length() - 1;
    for(int i = f; i >= 0; i--) {
        cout << a[i];
    }
    return 0;
}