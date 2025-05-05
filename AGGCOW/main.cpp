#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int n,c; vector<int> a;
bool can(int dist) {
    int Last_pos=a[0]; int cnt=1; // we already added 1 cow at start
    for(int i=1;i<n;i++) {
        if(a[i]-Last_pos>=dist) {
            Last_pos=a[i];
            cnt++;
        }
    }
    if(cnt>=c)  return true;
    return false;
}


void solve() {
    int t; cin>>t;
    while(t--) {
        cin>>n>>c; a.clear(); a.resize(n);
        for(int i=0;i<n;i++) cin>>a[i];
        sort(a.begin(),a.end());

        int l=0,r = a[n-1] - a[0];  // l & r are min-max acceptable distance
        int ans=0;

        while(l<=r) {
            int mid=(l+r)/2; // distance
            if(can(mid)) {
                ans=mid;
                l=mid+1;
            }
            else {
                r=mid-1;
            }
        }
        cout<<ans<<"\n";
    }
}


int main(){
    fastIO();
    solve();
    return 0;
}