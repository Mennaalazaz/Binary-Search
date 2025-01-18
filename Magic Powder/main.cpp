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
int n,k; vector<ll> neededgrams; vector<ll> gramsOwned;

bool can(ll cookies) {
     __int128 excess=0;
    for(int i = 0; i <n; i++) {
        __int128 neededAmount= (__int128)neededgrams[i]*cookies ; // as ll*ll may cause overflow

        if(neededAmount> gramsOwned[i]) {
            excess+=neededAmount-gramsOwned[i];

            if (excess > k) { // Early exit if redundant exceeds k
                return false;
            }
        }
    }
    return excess<=k;
}
void solve() {
    cin>>n>>k;
    neededgrams.resize(n);
    gramsOwned.resize(n);
    for(int i=0;i<n;i++) {
        cin>>neededgrams[i];
    }
    for(int i=0;i<n;i++) {
        cin>>gramsOwned[i];
    }
    ll start=0, end=1e18, mid, ans=0;
    while(start<=end) {
        mid=(start+end)/2;
        if(can(mid)) {
            ans=mid;
            start=mid+1;
        }
        else {
            end=mid-1;
        }
    }
    cout<<ans<<"\n";

}
int main() {
    fastIO();
    solve();
    return 0;
}
