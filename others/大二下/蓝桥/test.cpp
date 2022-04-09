#include <bits/stdc++.h> 
using namespace std;

struct node {
    int x;
};

bool cmp(const int&a, const int&b) {
    // if(a > b) return true;
    return true;
}

int main() {
    int a[3] = {0, 1, 2};
    sort(a, a+3, cmp);
    for(auto k: a) { cout << k << ' '; }
    cout << endl;
}