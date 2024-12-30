#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int catchThieves(vector<char> &arr, int n, int k) {
    int ans = 0;
    vector<int> police, thieves;

    // Separate indices of police and thieves
    for (int i = 0; i < n; i++) {
        if (arr[i] == 'P') {
            police.push_back(i);
        } else if (arr[i] == 'T') {
            thieves.push_back(i);
        }
    }

    int i = 0, j = 0;

    // Match police and thieves within the distance k
    while (i < police.size() && j < thieves.size()) {
        if (abs(police[i] - thieves[j]) <= k) {
            ans++;
            i++;
            j++;
        } else if (police[i] > thieves[j]) {
            j++; // Move to the next thief
        } else {
            i++; // Move to the next police
        }
    }
    return ans;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<char> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << catchThieves(arr, n, k) << endl;
    return 0;
}
