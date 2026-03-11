#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n,m;
    cin>>n>>m;

    int mid=(m+1)/2;

    vector<int> a(m+1,0);

    for(int i=1;i<=n;i++){
        int best=1;

        for(int j=1;j<=m;j++){
            if(a[j]<a[best] ||
              (a[j]==a[best] && abs(j-mid)<abs(best-mid)) ||
              (a[j]==a[best] && abs(j-mid)==abs(best-mid) && j<best))
            {
                best=j;
            }
        }

        cout<<best<<endl;
        a[best]++;
    }

    return 0;
}