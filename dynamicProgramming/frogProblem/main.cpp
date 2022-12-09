#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int n;
// for each pos store the amount of paths necessary to be there.
vector<ll> ans(10000, -1);
ll recursion(int pos) {
    if(pos == 0) return 1;
    if(ans[pos] != -1) return ans[pos];
    ll cur = 0;
    if(pos-1 >= 0) cur += recursion(pos-1);
    if(pos-2 >= 0) cur += recursion(pos-2);
    ans[pos] = cur;
    return cur;
}

vector<ll> ansI(10000, 0);
void iterative() {
    ansI[0] = 1;
    for (int i = 0; i < n; i++) {
        if(i+1 <= n) ansI[i+1] += ansI[i];
        if(i+2 <= n) ansI[i+2] += ansI[i];
    }
}

int main (int argc, char *argv[])
{
    cin>>n;
    // recursive solution
    recursion(n);
    cout<<ans[n]<<"\n";

    // Iterative solution
    iterative();
    cout<<ansI[n]<<"\n";
    return 0;
}
