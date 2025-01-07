#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define intCeil(a,b) (ll(a)+ll(b-1))/ll(b)

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
ll a[10000]; int n;int k;

bool can(ld mid) {
    ld lost =0, gained=0;
    for (int i = 0; i < n; i++) {
        if (mid >= a[i]) {
            gained+=mid - a[i];
        }
        else {
            lost+= a[i]-mid;
        }
    }
    lost=lost-((lost*k)/100.0);
    return lost>=gained; // No problem to have excess amount so (>=) not (==)
}


void solve() {
    cin >> n>>k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a,a+n);
    ld ans = 0;ld start=0, end=a[n-1]; ld mid;
    while (fabs( start-end)>1e-7) { // Binary search on doubles
        mid = (start+end)/2;
        if (can(mid)) {
            ans = mid;
            start = mid; //  In Binary search on doubles Not make  start = mid+1;
        } else {
            end = mid; // In Binary search on doubles Not make  end= mid-1;
        }
    }
    cout << fixed<<setprecision(9)<<ans;
}

int main() {
    fastIO();
    solve();

    return 0;
}
