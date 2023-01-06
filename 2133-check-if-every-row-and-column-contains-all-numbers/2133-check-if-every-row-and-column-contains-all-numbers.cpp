class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        for(int i=0;i<n;i++)
        {
            unordered_map<int,int> mp;
            
            for(int j=0;j<n;j++)
            {
                mp[matrix[i][j]]++;
            }
            for(int i=1;i<=n;i++)
            {
                if(mp.find(i)==mp.end())
                  return false;
            }
        }
        
        for(int j=0;j<n;j++)
        {
            unordered_map<int,int> mp;
            
            for(int i=0;i<n;i++)
            {
                mp[matrix[i][j]]++;
            }
            
            for(int i=1;i<=n;i++)
            {
                if(mp.find(i)==mp.end())
                    return false;
            }
        }
        return true;
      
        
        
    }
};