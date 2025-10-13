#include<bits/stdc++.h>
using namespace std;
// Debug macro: only prlong longs in LOCAL mode
#ifdef LOCAL
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif
using ll = long long;
ll V = 1000000000LL;
void solve() {
    int n;
    cin >> n;
    debug(n);
    vector<pair<ll, ll>> pos(n);
    ll min_sum = LLONG_MAX;
    ll min_diff = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        cin >> pos[i].first >> pos[i].second;
        if (pos[i].first + pos[i].second < min_sum) min_sum = pos[i].first + pos[i].second;
        if (pos[i].first - pos[i].second < min_diff) min_diff = pos[i].first - pos[i].second;
        debug(min_diff);
        debug(min_sum);
    }
    ll response;
    // d finally would be min(x + y) - X - Y + 4V
    // (L, V), (L, V), (D, V), (D, V)
    cout << "? L " << V << endl;
    cout << flush;
    cin >> response;
    cout << "? L " << V << endl;
    cout << flush;
    cin >> response;
    cout << "? D " << V << endl;
    cout << flush;
    cin >> response;
    cout << "? D " << V << endl;
    cout << flush;
    cin >> response;
    debug(response);
    // X+Y = min_sum - response + 4V
    ll sum = min_sum - response + 4 * V;
    for (int i = 0; i < 4; i++) {
        // (U, V), (U, V), (U, V), (U, V)
        cout << "? U " << V << endl;
        cout << flush;
        cin >> response;
    }
    debug(response);
    // Y - X
    ll diff = response - min_diff - 4 * V;
    ll Y = (sum + diff)/2;
    ll X = (sum - diff)/2;
    cout << "! " << X << " " << Y << endl;
    cout << flush;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    debug(t);
    while (t--) {
        solve();
    }
    return 0;
}