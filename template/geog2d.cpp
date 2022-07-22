#include <bits/stdc++.h>
using namespace std;

struct Point;

typedef double db;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef Point Vector;

const double eps = 1e-9;

struct Point {
    db x, y;
    Point(db x, db y): x(x), y(y) {}  
};

bool operator == (const Point &s, const Point &t) { return abs(t.x-s.x) < eps && abs(t.y-s.y) < eps; }
Point operator + (const Point &s, const db&t) { return Point(s.x+t, s.y+t); }
Point operator - (const Point &s, const db&t) { return Point(s.x-t, s.y-t); }
Point operator * (const Point &s, const db&t) { return Point(s.x*t, s.y*t); }
Point operator / (const Point &s, const db&t) { return Point(s.x/t, s.y/t); }

int main() {
    return 0;
}