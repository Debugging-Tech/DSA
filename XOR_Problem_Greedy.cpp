#include <bits/stdc++.h>
using namespace std;

bool solve(int n, vector<int>& arr) {
    int total_xor = 0;
    for (int i = 0; i < n; i++) total_xor ^= arr[i];

    if (total_xor == 0) return true;

    int curr_xor = 0;
    int cnt = 0;

    
    for (int i = 0; i < n; i++) {
        curr_xor ^= arr[i];
        if (curr_xor == total_xor) {
            cnt++;
            curr_xor = 0;
        }
    }

    
    return cnt >= 2;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    string result = solve(n, arr) ? "Yes" : "No";
    cout << result << endl;

    return 0;
}
