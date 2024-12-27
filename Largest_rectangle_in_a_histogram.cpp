#include <bits/stdc++.h>
using namespace std;
int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    stack<int>st;
    int tp;
    int curr_area;
    int max_area = 0;
        
    int i = 0;

    while(i < n){
        if(st.empty() || heights[i] >= heights[st.top()]) st.push(i++);
        else{
            tp = st.top();
            st.pop();

            curr_area = heights[tp]*(st.empty()? i: i - st.top() - 1);
            max_area = max(max_area, curr_area);
        }
    }

    while(!st.empty()){
        tp = st.top();
        st.pop();

        curr_area = heights[tp] * (st.empty() ? i : i-st.top()-1);
        max_area = max(max_area, curr_area);
    }
    return max_area;
}

int main(){
    vector<int> heights = {2,1,5,6,2,3};
    cout << largestRectangleArea(heights) << endl;
    return 0;
}
