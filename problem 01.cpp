#include<bits/stdc++.h>
using namespace std;
int main(){
int n;
cin>>n;
set<int>dist;
for(int i=0; i<n; i++){
int x;
cin>>x;
dist.insert(x);
}
cout<<dist.size();
return 0;
}