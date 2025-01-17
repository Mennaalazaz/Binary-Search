#include <bits/stdc++.h>
using namespace std;
using ld = long double;
using ll = long long;
#define intCeil(a,b) (ll(a)+ll(b-1))/ll(b)

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
ll n,t;  vector<ll> a;
bool can(ll time) {
    ll total = 0;
    for (int i = 0; i < n; i++) {
        total += time / a[i]; // Number of products produced by the i-th machine
        if (total >= t) {
            return true; // Early exit if total products >= t
        }
    }
    return total >= t;
}

void solve() {
    cin>>n>>t;
    a.resize(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());

    ll start=1, end=1e18,mid,ans=-1;
    while(start<=end) {
        mid=(start+end)/2;
        if(can(mid)) {
            ans=mid;
            end=mid-1;
        }
        else {
            start=mid+1;
        }
    }
    cout<<ans<<"\n";
}
int main() {
    fastIO();
    solve();
    return 0;
}
