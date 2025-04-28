#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

ll sum(ll n) {
    return (n*(n+1))/2; // formula of summation from 1 to n
}

ll sumRange(ll from , ll to) {
    return sum(to)-sum(from-1);
    // summation in range of 7 to 10 is sum(10)-sum(7-1)
}

ll binarySearch(ll n,ll k) {
    ll start = 1, end = k; ll answer=-1;
    while (start <= end) {
        ll mid =(start+end)/2;
        ll s = sumRange(mid,k);

        if (s== n) { // found the suitable number of splitters
            return k-mid+1;
        }

        if (s > n) {
            answer = mid;
            start = mid + 1; // Try to use fewer splitters
        }
        else if(s < n) {
            end = mid-1;
        }
    }
    if (answer == -1) return -1;
    return k-answer+1;
}

void solve() {
    ll n,k; cin>>n>>k;
    if(n==1) {
        cout<<"0"<<endl; // connect to water source itself
        return;
    }
    // Adjust for net gain: splitters are 2..k (net gain 1..k-1)
    k--;
    n--;

    if(n<=k) {
        cout<<"1"<<endl;
        return;
    }

    if(n>sum(k)) {
        cout<<"-1"<<endl;
        return;
    }
    ll ans=binarySearch(n,k);
    cout<<ans<<endl;
}


int main(){
    fastIO();
    solve();
    return 0;
}