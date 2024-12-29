#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define intCeil(a,b) (ll(a)+ll(b-1))/ll(b)

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool can(int mid, vector<ll>&a, ll size, int k) {
    ll sum = 0;
    for (int i = size/2; i < size; i++) {
        if(a[i]<mid) sum += mid - a[i];
    }
    return sum <= k;
}


void solve() {
    int n; cin>>n;
    int k; cin>>k;
    vector<ll> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    sort(a.begin(), a.end());

    // Binary search on median
    ll l=a[n/2], r=a[n/2] + k;  ll mid ; ll ans=0;
    while(l<=r) {
        mid = (l+r)/2;
        if(can(mid,a,n,k)) {
            ans = mid;
            l=mid+1; // need maximum possible median .. try something greater
        }
        else {
            r = mid-1;
        }
    }
    cout<<ans<<"\n";



}



int main() {
    fastIO();
    solve();

    return 0;
}
