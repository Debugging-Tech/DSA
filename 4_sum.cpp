#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> solve(int n, int target, vector<int>& arr){
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    set<vector<int>> st;

    for(int i = 0; i < n-3; i++){
        for(int j = i+1; j < n-2; j++){
            int left = j + 1;
            int right = n - 1;

            while(left < right){
                int sum = arr[i] + arr[j] + arr[left] + arr[right];
                if (sum == target){
                    st.insert({i, j, left, right});
                    left++;
                    right--;
                }
                else if (sum < 0) left++;
                else right--;
            }
        }
    }

    for(auto it: st) ans.push_back(it);
    return ans;
}

int main(){
    int n, target;
    cin >> n >> target;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    vector<vector<int>>ans = solve(n, target, arr);

    for(auto it: ans){
        for(int i: it) cout << i << " ";
        cout << endl;
    }
}