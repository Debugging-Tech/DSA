#include <bits/stdc++.h>
using namespace std;

int lcs(string s1, string s2){
    int m = s2.length();
    int n = s1.length();
    vector<int>prev(m+1, 0);
    vector<int>curr(m+1, 0);

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s1[i-1] == s2[j-1])
                curr[j] = prev[j-1] + 1;
            else
                curr[j] = max(prev[j], curr[j-1]);
        }
        prev = curr;
        fill(curr.begin(), curr.end(), 0);
    }
    return prev[m];
}

int longest_palindroomic_subseq(string s){
    string s1 = s;
    reverse(s1.begin(), s1.end());
    return lcs(s, s1);
}

int main(){
    string s;
    cin >> s;

    cout << longest_palindroomic_subseq(s) << endl;


}