#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    int x, sum = 0, ans = -1;

    for(int i = 0; i < n; i++){
        cin >> x;
        sum = max(x, sum + x);
        ans = max(ans, sum);
    }

    cout << ans;
}