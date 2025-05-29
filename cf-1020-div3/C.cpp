#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    long long k;
    cin >> n >> k;
    vector<long long> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    long long amax = -1, amin = LLONG_MAX;
    vector<int> id; //id where b[i] != -1
    vector<int> missing;
    for (int i = 0; i < n; i++) {
        if (a[i] > amax) amax = a[i];
        if (a[i] < amin) amin = a[i];
        if (b[i] != -1) id.push_back(i);
        else if (b[i] == -1) missing.push_back(i);
    }
    
    if (id.size() == 0) {
        if (k + amin >= amax) {
            cout << k + amin + 1 - amax << endl;
        }
        else cout << 0 << endl;
        return;
    }
    else {
        long long sum = b[id[0]] + a[id[0]];
        bool check = true;
        for (int i = 1; i < id.size(); i++) {
            if (b[id[i]] + a[id[i]] != sum) {
                check = false;
                break;
            }
        }
        if (check) {
            for (int i : missing) {
                if (a[i] > sum || a[i] < sum - k) {
                    check = false;
                    break;
                }
            }
        }
        if (check == true) cout << 1 << endl;
        else cout << 0 << endl;
        return;
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    cin.ignore();
    while (tt--) {
        solve();
        fflush(stdout);
    }
    return 0;
}