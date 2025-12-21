#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long mergeAndCount(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp;
    int i = left, j = mid + 1;
    long long count = 0;

    while (i <= mid && j <= right) {
        if (arr[i] < arr[j]) {
            // arr[i] is smaller than all remaining arr[j..right]
            count += (right - j + 1);
            temp.push_back(arr[i++]);
        } else {
            temp.push_back(arr[j++]);
        }
    }
    while (i <= mid) temp.push_back(arr[i++]);
    while (j <= right) temp.push_back(arr[j++]);

    for (int k = left; k <= right; k++) {
        arr[k] = temp[k - left];
    }
    return count;
}

long long mergeSortAndCount(vector<int>& arr, int left, int right) {
    if (left >= right) return 0;
    int mid = left + (right - left) / 2;
    long long count = 0;
    count += mergeSortAndCount(arr, left, mid);
    count += mergeSortAndCount(arr, mid + 1, right);
    count += mergeAndCount(arr, left, mid, right);
    return count;
}

long long countIncreasingPairs(vector<int>& arr) {
    return mergeSortAndCount(arr, 0, arr.size() - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<pair<int, int>> p(n);
        for (int i = 0; i < n; i++) cin >> p[i].first >> p[i].second;
        sort(p.begin(), p.end(), [](const auto& a, const auto& b) {
            return a.first > b.first;
        });
        vector<int> b(n);
        for (int i = 0; i < n; i++) b[i] = p[i].second;
        long long cnt = countIncreasingPairs(b);
        cout << cnt << endl;
    }
    return 0;
}