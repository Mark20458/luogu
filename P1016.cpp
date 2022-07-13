#include <iostream>
#include <queue>

using namespace std;

typedef double ll;

void swap(ll *a, ll *b) {
    ll t = a[0];
    a[0] = b[0];
    b[0] = t;
    t = a[1];
    a[1] = b[1];
    b[1] = t;
}

struct less_then_greater {
    template <typename T, typename U>
    bool operator()(T const &lhs, U const &rhs) const {
        if (lhs.first > rhs.first)
            return true;
        else
            return false;
    }
};

int main() {
    double D1, C, D2, P;
    int N;
    double a[10][2];
    scanf("%lf%lf%lf%lf%d", &D1, &C, &D2, &P, &N);
    for (int i = 0; i < N; i++)
        cin >> a[i][0] >> a[i][1];
    for (int i = 0; i < N; i++)
        for (int j = 1; j < N - i; j++)
            if (a[j][0] < a[j - 1][0]) {
                swap(a[j], a[i]);
            }
    priority_queue<pair<double, double>, vector<std::pair<double, double>>, less_then_greater> pq;
    pq.push(make_pair(P, C));
    double ans = P * C;
    double d = 0;
    double L = C;
    for (int i = 0; i < N; i++) {
        double dd = a[i][0] - d;
        double m = dd / D2;
        if (m > C) {
            cout << "No Solution" << endl;
            return 0;
        } else {
            L -= m;
            while (m != 0) {
                auto cc = pq.top();
                pq.pop();
                if (cc.second < m) {
                    m -= cc.second;
                } else {
                    cc.second -= m;
                    m = 0;
                    if (cc.second != 0) {
                        pq.push(cc);
                    }
                }
            }
        }
        queue<pair<double, double>> que;
        while (pq.top().first < a[i][1] && !pq.empty()) {
            que.push(pq.top());
            pq.pop();
        }
        while (!pq.empty()) {
            auto x = pq.top();
            L -= x.second;
            pq.pop();
            ans -= (x.first * x.second);
        }
        while (!que.empty()) {
            pq.push(que.front());
            que.pop();
        }
        auto r = make_pair(a[i][1], C - L);
        ans += (r.first * r.second);
        L = C;
        if (r.second != 0)
            pq.push(r);
        d = a[i][0];
    }
    double dd = D1 - d;
    double m = dd / D2;
    if (m > C) {
        cout << "No Solution" << endl;
        return 0;
    } else {
        L -= m;
        while (m != 0) {
            auto cc = pq.top();
            pq.pop();
            if (cc.second < m) {
                m -= cc.second;
            } else {
                cc.second -= m;
                m = 0;
                if (cc.second != 0) {
                    pq.push(cc);
                }
            }
        }
    }
    while (!pq.empty()) {
        auto r = pq.top();
        pq.pop();
        ans -= (r.first * r.second);
    }
    printf("%.2lf", ans);
}