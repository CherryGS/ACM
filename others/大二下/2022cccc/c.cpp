#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    if(c >= d) {
        if(d >= a) {
            cout << c << "-Y" << ' ' << d << "-Y" << endl;
            cout << "huan ying ru guan" << endl;
        }
        else if(c >= b){
            cout << c << "-Y" << ' ' << d << "-Y" << endl;
            cout << "qing 1 zhao gu hao 2" << endl;
        }
        else if(c >= a) {
            cout << c << "-Y" << ' ' << d << "-N" << endl;
            cout << "1: huan ying ru guan" << endl;
        }
        else {
            cout << c << "-N" << ' ' << d << "-N" << endl;
            cout << "zhang da zai lai ba" << endl;
        }
    }
    else {
        swap(c, d);
        if(d >= a) {
            cout << d << "-Y" << ' ' << c << "-Y" << endl;
            cout << "huan ying ru guan" << endl;
        }
        else if(c >= b){
            cout << d << "-Y" << ' ' << c << "-Y" << endl;
            cout << "qing 2 zhao gu hao 1" << endl;
        }
        else if(c >= a) {
            cout << d << "-N" << ' ' << c << "-Y" << endl;
            cout << "2: huan ying ru guan" << endl;
        }
        else {
            cout << c << "-N" << ' ' << d << "-N" << endl;
            cout << "zhang da zai lai ba" << endl;
        }
    }
}