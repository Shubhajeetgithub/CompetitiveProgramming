/*
https://codeforces.com/problemset/problem/1869/B
Observe that for k = 0, even if there exists intermediate city, 
min cost from a to b is manh(a, b). 
This is because of the property of manhattan distance.
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k, a, b;
        cin >> n >> k >> a >> b;
        vector<pair<ll, ll>> d(n);
        for (int i = 0; i < n; i++) cin >> d[i].first >> d[i].second;
        ll dist = abs(d[a-1].first - d[b-1].first) + abs(d[a-1].second - d[b-1].second);
        if (k == 0) {
            cout << dist << endl;
            continue;
        }
        ll mina = LLONG_MAX;
        ll minb = LLONG_MAX;
        for (int i = 0; i < k; i++) {
            ll da = abs(d[i].first - d[a-1].first) + abs(d[i].second - d[a-1].second);
            ll db = abs(d[i].first - d[b-1].first) + abs(d[i].second - d[b-1].second);
            mina = min(mina, da);
            minb = min(minb, db);
        }
        dist = min(dist, mina + minb);
        cout << dist << endl;
    }
    return 0;
}