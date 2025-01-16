#include <bits/stdc++.h>
using namespace std;
void dfs(int open, int close, string s, int n, vector<string>&res){
        if(open == close && open + close == n * 2){
            res.push_back(s);
        }
        if(open < n){
            dfs(open + 1, close, s + "(", n, res);
        }
        if(close < open){
            dfs(open, close + 1, s + ")", n, res);
        }
    }
vector<string> generateParenthesis(int n) {
        vector<string>ans;
        dfs(0, 0, "", n, ans);
        return ans;
    }

int main() {
    int n;
    cin >> n;

    vector<string>s = generateParenthesis(n);

    for(auto &p : s) cout << p << endl;
    return 0;   
}