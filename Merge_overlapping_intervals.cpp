#include <bits/stdc++.h>
using namespace std;

static bool cmp(pair<int,int>&a, pair<int,int>&b){
        return a.first < b.first;
    }
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<pair<int,int>>arr;
    stack<pair<int,int>>st;

    for(auto it: intervals){
        arr.push_back({it[0], it[1]});
    }

    sort(arr.begin(), arr.end(), cmp);

    int n = arr.size();

    for(int i = 0; i < n; i++){
        if(st.empty()) st.push({arr[i].first, arr[i].second});

        else if(st.top().second >= arr[i].first) st.top().second = max(st.top().second, arr[i].second);
        else st.push({arr[i].first, arr[i].second});
    }
    n = st.size();
    vector<vector<int>>ans(n, vector<int>(2));
    int i = 0;
    while(!st.empty()){
        int f = st.top().first;
        int s = st.top().second;

        st.pop();
        ans[i][0] = f;
        ans[i][1] = s;
        i++;
    }
    return ans;
}


int main(){
    vector<vector<int>>intervals = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> res = merge(intervals);

    for(auto it: res) cout << "[" << it[0] << ", " << it[1] << "] ";
    cout << endl;
    return 0;
}