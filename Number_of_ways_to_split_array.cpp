#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& nums){
    int n = nums.size();

    long long int sum = 0;
    for(long long int i: nums)sum += i;

    int ans = 0;
    vector<long long int>prefix(n);
    prefix[0] = nums[0];

    for(int i = 1; i < n; i++){
        prefix[i] = prefix[i-1] + nums[i];
    }

    for(int i = 0; i < n-1; i++){
        if(prefix[i] >= (sum - prefix[i]))ans++;
    }
    return ans;
}
int main() {
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i = 0; i < n; i++)cin >> arr[i];
    cout << solve(arr) << endl;
}
