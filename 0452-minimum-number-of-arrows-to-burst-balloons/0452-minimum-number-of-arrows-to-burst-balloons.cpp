class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int lastpoint = points[0][1];
        int ans = 1;
        for(auto x: points)
        {
            if(x[0]>lastpoint){
                ans++;
                lastpoint = x[1];
            }
                
            
                lastpoint = min(lastpoint, x[1]);
        }
            return ans;
    }
};