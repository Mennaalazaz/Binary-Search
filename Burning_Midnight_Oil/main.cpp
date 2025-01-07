#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define intCeil(a,b) (ll(a)+ll(b-1))/ll(b)

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
bool can(ll v, ll n , ll k) {
    ll sum=v;
    while(v>0)  {
        v/=k;
        sum+=v;
    }
    return sum>=n;
}

void solve() {
    ll n,k; cin>>n>>k;

    int start=0, end=n; int v; // Binary search on V
    int ans=0;
    while (start<=end) {
        v=(start+end)/2;
        if (can(v,n,k)) {
            ans=v;
            end=v-1;
        }
        else {
            start=v+1;
        }
    }
    cout<<ans<<"\n";
}

int main() {
    fastIO();
    solve();

    return 0;
}
