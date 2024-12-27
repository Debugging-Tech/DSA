#include <bits/stdc++.h>
using namespace std;

int trapping_rain_water(vector<int>& height){
    int n = height.size();
    vector<int>left(n), right(n);

    left[0] = height[0];
    for(int i = 1; i < n; i++) left[i] = max(left[i-1], height[i]);

    right[n-1] = height[n-1];
    for(int i = n-2; i >= 0; i--) right[i] = max(right[i+1], height[i]);

    int water = 0;
    for(int i = 0; i < n; i++) water += min(left[i], right[i]) - height[i];
    return water;
}
int main(){
    vector<int>height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << trapping_rain_water(height) << endl;

}