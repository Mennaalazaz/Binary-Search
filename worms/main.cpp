#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void solve() {
    int n; cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Create prefix sum array
    vector<ll> prefix(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + a[i - 1];
    }

    int m; cin >> m;
    vector<ll> queries(m);
    for (int i = 0; i < m; i++) {
        cin >> queries[i];
    }

    // For each query, find the pile using binary search on the prefix sum array
    for (int i = 0; i < m; i++) {
        ll q = queries[i];
        int left = 1, right = n, pile = 0;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (prefix[mid] >= q) {
                pile = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        cout << pile << "\n";
    }
}

int main() {
    fastIO();
    solve();
    return 0;
}