#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

string cacu(string a) {
    string s;
    for(int i = 1; i < a.size(); i++) {
        if (a[i] % 2 == a[i-1] % 2) {
            s += max(a[i], a[i-1]);
        }
    }
    return s;   
}

int main() {
    string a, b;
    cin >> a >> b;
    a = cacu(a);
    b = cacu(b);
    cout << a << endl;
    if(a != b) { cout << b << endl; }
}