//problem#4
#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e3 + 10;
int a[maxn];
int remove_occurrence(int l, int r) {
    if(l > r) return 0;
    else if (l == r) {
        if(a[l] == 0) return 0;
        else return 1;
    }
    int cnt1 = 1e9 + 10, mid;
    for(int i = l; i <= r; ++ i) {
        if(a[i] < cnt1) {
            cnt1 = a[i];
            mid = i;
        }
    }
    for(int i = l; i <= r; ++ i) a[i] -= cnt1;
    return min(cnt1 + remove_occurrence(l, mid - 1) + remove_occurrence(mid + 1, r), r - l + 1);
}

int main() {
    int n;
    cout<<"Enter ArraySize of multiset:"<<endl;
    cin>>n;
    cout<<"Enter array of multiset"<<endl;
    for(int i = 1; i <= n; i++)
    {
        cin>>a[i];
    }
    int ans = remove_occurrence(1, n);
    cout<<ans<<endl;
    return 0;
}