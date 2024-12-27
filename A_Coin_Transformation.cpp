#include <bits/stdc++.h>
using namespace std;

long int solve(long long int a){
   long int ans = 1;
   
   while(a > 3){
    a = a/4;
    ans*= 2;
   }
   return ans;
}
int main(){
    int t;
    cin >> t;
    
    while(t--){
        long long int a;
        cin >> a;

        cout << solve(a) << endl;
    }
}