// For this problem, target sum is assumed to be 0.

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> solve(int n, vector<int>& arr){
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    set<vector<int>>st;

    for(int i = 0; i < n; i++){
        int j = i + 1;
        int k = n - 1;

        while(j < k){
            int sum = arr[i] + arr[j] + arr[k];
            if (sum == 0){
                st.insert({i, j, k});
                j++;
                k--;
            }
            else if (sum < 0) j++;
            else k--;
        }
    }
    for(auto it: st) ans.push_back(it);
    return ans;
}

int main(){
    int n = 6;

    vector<int> arr = {-1,0,1,2,-1,-4};

    vector<vector<int>>ans = solve(n, arr);

    for(auto it: ans){
        for(int i: it) cout << i << " ";
        cout << endl;
    }
    return 0;
}