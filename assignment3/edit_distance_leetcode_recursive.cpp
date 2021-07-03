class Solution {
public:
    int minDistance(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return dist(n, m, s, t, dp);
    }
    
    int dist(int i, int j, string& s, string& t, vector<vector<int>>& dp) {
        if(i == 0) return j;
        if(j == 0) return i;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i - 1] == t[j - 1]) return dp[i][j] = dist(i - 1, j - 1, s, t, dp);
        else return dp[i][j] = 1 + min(dist(i - 1, j - 1, s, t, dp), min(dist(i - 1, j, s, t, dp), dist(i, j - 1, s, t, dp)));
    }
};