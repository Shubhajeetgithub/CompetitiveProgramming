#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, p;
        cin >> n >> p;
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++) {
            v[i].first = 0;
            int x;
            cin >> x;
            v[i].second = x;
        }
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            v[i].first = x;
        }
        sort(v.begin(), v.end());
        int min_cost = p;
        int taken = 1;
        for (auto it : v) {
            int can_be_inc = it.second;
            int cost = it.first;
            if (cost >= p) break;
            if (taken + can_be_inc > n) {
                min_cost += (n - taken) * cost;
                taken = n;
                break;
            }
            else {
                min_cost += can_be_inc * cost;
                taken += can_be_inc;
            }
        }
        min_cost += (n - taken) * p;
        cout << min_cost << endl;
    }
    return 0;
}