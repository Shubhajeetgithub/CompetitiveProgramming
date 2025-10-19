/*
https://codeforces.com/problemset/problem/1793/C
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define READ_VEC(a, n) vector<ll> a(n); for (int i = 0; i < (n); i++) cin >> a[i];

void solve() {
    int n; cin >> n;
    READ_VEC(a, n);
    if (n <= 2) {
        cout << -1 << endl;
        return;
    }
    int mini = 1, maxi = n;
    int i = 0, j = n-1;
    while (i < j) {
        if (a[i] > mini && a[i] < maxi && a[j] > mini && a[j] < maxi) break;
        if (a[i] == mini) {
            mini++;
            i++;
        }
        else if (a[i] == maxi) {
            maxi--;
            i++;
        }
        if (a[j] == mini) {
            mini++;
            j--;
        }
        else if (a[j] == maxi) {
            maxi--;
            j--;
        }
    }
    if (i < j) {
        cout << i + 1 << " " << j + 1 << endl;
    }
    else {
        cout << "-1\n";
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;
    cin >> tt;
    cin.ignore();
    while (tt--) {
        solve();
    }
    return 0;
}