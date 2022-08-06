#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>

using namespace std;

typedef long long ll;

struct P {
    double x, y;
    int k;
};

double dist[450][450];
int n, s, t, A, B;
P p[450];
double f[105];

double distance(int i, int j) {
    return sqrt(pow(p[i].x - p[j].x, 2) + pow(p[i].y - p[j].y, 2));
}

double Floyd() {
    memset(dist, 999999999.999999, sizeof(dist));
    double cost = 99999999999;
    for (int k = 1; k <= 4 * s; k++) {
        for (int i = 1; i <= 4 * s; i++) {
            if (p[k].k == p[i].k)
                cost = min(distance(i, k) * f[p[i].k], dist[i][k]);
            else
                cost = min(distance(i, k) * t, dist[i][k]);
            for (int j = 1; j <= 4 * s; j++) {
                if (p[k].k == p[j].k)
                    dist[i][j] = min(min(distance(k, j) * f[p[j].k], dist[k][j]) + cost, dist[i][j]);
                else
                    dist[i][j] = min(min(distance(k, j) * t, dist[k][j]) + cost, dist[i][j]);
            }
        }
    }
    double m = 554654654;
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++)
            m = min(m, dist[4 * (A - 1) + i][4 * (B - 1) + j]);
    }
    return m;
}

void solve() {
    cin >> s >> t >> A >> B;
    int j = 0;
    for (int i = 0; i < s; i++) {
        cin >> p[4 * i + 1].x >> p[4 * i + 1].y;
        cin >> p[4 * i + 2].x >> p[4 * i + 2].y;
        cin >> p[4 * i + 3].x >> p[4 * i + 3].y;
        cin >> f[i + 1];
        p[4 * i + 1].k = p[4 * i + 2].k = p[4 * i + 3].k = p[4 * i + 4].k = i + 1;

        p[4 * i + 4].x = p[4 * i + 1].x + p[4 * i + 2].x - p[4 * i + 3].x;
        p[4 * i + 4].y = p[4 * i + 1].y + p[4 * i + 2].y - p[4 * i + 3].y;
        if (((p[4 * i + 1].x - p[4 * i + 3].x) * (p[4 * i + 2].x - p[4 * i + 3].x) + (p[4 * i + 1].y - p[4 * i + 3].y) * (p[4 * i + 2].y - p[4 * i + 3].y)) == 0)
            continue;

        p[4 * i + 4].x = p[4 * i + 1].x + p[4 * i + 3].x - p[4 * i + 2].x;
        p[4 * i + 4].y = p[4 * i + 1].y + p[4 * i + 3].y - p[4 * i + 2].y;
        if (((p[4 * i + 1].x - p[4 * i + 2].x) * (p[4 * i + 3].x - p[4 * i + 2].x) + (p[4 * i + 1].y - p[4 * i + 2].y) * (p[4 * i + 3].y - p[4 * i + 2].y)) == 0)
            continue;

        p[4 * i + 4].x = p[4 * i + 3].x + p[4 * i + 2].x - p[4 * i + 1].x;
        p[4 * i + 4].y = p[4 * i + 3].y + p[4 * i + 2].y - p[4 * i + 1].y;
        if (((p[4 * i + 3].x - p[4 * i + 1].x) * (p[4 * i + 2].x - p[4 * i + 1].x) + (p[4 * i + 3].y - p[4 * i + 1].y) * (p[4 * i + 2].y - p[4 * i + 1].y)) == 0)
            continue;
    }
    printf("%.1lf\n", Floyd());
}

int main() {
    cin >> n;
    while (n--)
        solve();
}