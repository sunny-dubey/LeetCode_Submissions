class Solution {
public:

int check(int i, int j, vector<int> &cuts, vector<vector<int>>& dp){

		if(i >= j - 1) return 0;

		if(dp[i][j] != -1) return dp[i][j];

		int mini = INT_MAX;
		for(int k = i+1; k < j; k++) {
			int ans = check(i, k, cuts, dp) + check(k, j, cuts, dp) + cuts[j] - cuts[i];
			mini = min(mini, ans);
		}

		return dp[i][j] = mini;

	}
    int minCost(int n, vector<int>& cuts) {
        
     
        int c = cuts.size();
		cuts.push_back(n);
		cuts.insert(cuts.begin(), 0);
		sort(cuts.begin(), cuts.end());

		vector<vector<int>> dp(c+2, vector<int> (c+2, -1));

		return check(0, c+1, cuts, dp);
    }
};