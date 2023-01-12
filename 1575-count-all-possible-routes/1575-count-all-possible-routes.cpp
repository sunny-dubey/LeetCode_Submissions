class Solution {
public:
    int dp[105][205], mod = 1e9+7;
    
    int fun (vector<int> &loc, int i, int fin, int f) {
        int ret = 0;
        
        if (i == fin) {
            ret = 1;
        }
        
        if (!f) {
            return ret;
        }
        
        if (dp[i][f]!=-1) return dp[i][f];
        
        for (int j = 0; j < loc.size(); j++) {
            if (i == j) continue;
            
            if (f >= abs(loc[i]- loc[j])) {
                ret = (ret +  fun(loc, j, fin, f - abs(loc[i]-loc[j])))%mod;;
            }
            
        }
        
        return dp[i][f] = ret;
    }
    
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        memset(dp, -1, sizeof(dp));
        return fun(locations, start, finish, fuel);
    }
};