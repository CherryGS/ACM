#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&

char a[3] = {'A','C','L'};

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 0; j < 3; j++)
            cout << a[j];
    return 0;
}