#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

const ld eps = 1e-9;

bool equals(ld a, ld b) {
    return abs(a - b) <= eps;
}

struct point {
    ld x, y;
    point() {}
    point(ld a, ld b) {
        x = a, y = b;
    }
    int ccw(point a, point b) {
        ld c = x * (a.y - b.y) + a.x * (b.y - y) + b.x * (y - a.y);
        if (equals(c, 0)) {
            return 0;
        }
        if (c > 0) {
            return 1;
        }
        return - 1;
    }
};

struct line {
    point M, N;
    line(point a, point b) {
        M = a, N = b;
    }
    point Intersect(line other) {
        ld A1 = N.y - M.y;
        ld B1 = M.x - N.x;
        ld C1 = A1 * M.x + B1 * M.y;
        ld A2 = other.N.y - other.M.y;
        ld B2 = other.M.x - other.N.x;
        ld C2 = A2 * other.M.x + B2 * other.M.y;
        ld D = A1 * B2 - A2 * B1;
        ld xx = (B2 * C1 - B1 * C2) / D;
        ld yy = (A1 * C2 - A2 * C1) / D;
        return point(xx, yy);
    }
};

int n;
vector <point> p;

ld Area(vector <point> &p) {
    ld area = 0;
    for (int i = 0; i < p.size(); ++i) {
        int nxt = (i + 1) % p.size();
        area += p[i].x * p[nxt].y - p[i].y * p[nxt].x;
    }
    return area;
}

bool Cut(point a, point b, vector <point> &p, vector <point> &pts) {
	for (int i = 0; i < p.size(); ++i) {
		if (p[i].ccw(a, b) >= 0) {
            pts.push_back(p[i]);
		}
        int nxt = (i + 1) % p.size();
        if (p[i].ccw(a, b) * p[nxt].ccw(a, b) < 0) {
            pts.push_back(line(p[i], p[nxt]).Intersect(line(a, b)));
        }
    }
    if (equals(Area(pts), 0) == true) {
        return false;
    }
    return true;
}

double Check(ld x0) {
    vector <vector <point>> polygon(2);
    Cut(point(x0, 1), point(x0, 2), p, polygon[0]);
    Cut(point(x0, 2), point(x0, 1), p, polygon[1]);
    return Area(polygon[1]) - Area(polygon[0]);
}

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
    if (fopen("test.inp", "r")) {
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
    }

    cin >> n;
    p.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i].x >> p[i].y;
    }

    if (Area(p) < 0) {
        reverse(p.begin(), p.end());
    }

    ld l = 1e18, r = 0;
    for (int i = 0; i < n; ++i) {
        l = min(l, p[i].x);
        r = max(r, p[i].x);
    }
    int loop = 0;
    while (++loop <= 100) {
        ld m = (l + r) / 2;
        ld curr = Check(m);
        if (equals(curr, 0)) {
            return cout << fixed << setprecision(4) << m, 0;
        }
        else if (curr > 0) {
            l = m;
        }
        else {
            r = m;
        }
    }

    cout << fixed << setprecision(4) << r;
}
