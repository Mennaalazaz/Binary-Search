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

void solve() {
    int t; cin>>t;
    while(t--) {
        ll n,m,q; cin>>n>>m>>q;
        vector<ll> teachers(m);
        for(int i=0;i<m;i++) cin>>teachers[i];
        sort(teachers.begin(),teachers.end());
        while(q--) {
            int st; cin>>st;
            if(st>teachers[m-1]) { // all teachers on left
                cout<<n-teachers[m-1]<<endl;
            }
            else if(st<teachers[0]){// all teachers on Right
                cout<<teachers[0]-1<<endl;
            }
            else { // some on right & others on left
                int right = upper_bound(teachers.begin(),teachers.end(),st)-teachers.begin();
                cout<<(teachers[right]-teachers[right-1]-1)/2<<endl;
            }
        }
    }
}
int main() {
    fastIO();
    solve();
    return 0;
}
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

void solve() {
    int t; cin>>t;
    while(t--) {
        ll n,m,q; cin>>n>>m>>q;
        vector<ll> teachers(m);
        for(int i=0;i<m;i++) cin>>teachers[i];
        sort(teachers.begin(),teachers.end());
        while(q--) {
            int st; cin>>st;
            if(st>teachers[m-1]) { // all teachers on left
                cout<<n-teachers[m-1]<<endl;
            }
            else if(st<teachers[0]){// all teachers on Right
                cout<<teachers[0]-1<<endl;
            }
            else { // some on right & others on left
                int right = upper_bound(teachers.begin(),teachers.end(),st)-teachers.begin();
                cout<<(teachers[right]-teachers[right-1]-1)/2<<endl;
            }
        }
    }
}
int main() {
    fastIO();
    solve();
    return 0;
}
