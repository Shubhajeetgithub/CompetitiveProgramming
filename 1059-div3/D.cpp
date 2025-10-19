#include<bits/stdc++.h>
using namespace std;
// Debug macro: only prlong longs in LOCAL mode
#ifdef LOCAL
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif
using ll = long long;

void solve() {
    int n;
    cin >> n;
    cout << "2 1 " << n << endl;
    cout << flush;
    ll y; cin >> y;
    cout << "1 1 " << n << endl;
    cout << flush;
    ll x; cin >> x;
    // r - l + 1 = y - x
    int start = 1, end = n;
    int r = -1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        cout << "2 1 " << mid << endl;
        cout << flush;
        ll yt; cin >> yt;
        cout << "1 1 " << mid << endl;
        cout << flush;
        ll xt; cin >> xt;
        if (yt - xt == y - x) {
            r = mid;
            end = mid - 1;
        }
        else start = mid + 1;
    }
    int len = static_cast<int>(y - x);
    int l = r + 1 - len;
    cout << "! " << l << " " << r << endl;
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