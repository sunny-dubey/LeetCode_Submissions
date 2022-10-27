class Solution {
public:
    int ans=0;
    vector<int> placed;
    
    bool safe(int row, int col)
    {
        bool safe = true;
        for(int i=0;i<row;i++)
        {
            int pCol = placed[i];
            
            if(col==pCol || abs(col-pCol)==abs(i-row)){
                safe = false;
                break;
            }
            
        }
        return safe;
    }
    
    void rec(int row, int n)
    {
        if(row==n)
        {
            ans++;
        }
        for(int col=0;col<n;col++)
        {
            if(safe(row,col))
            {
                placed.push_back(col);
                rec(row+1,n);
                placed.pop_back();
            }
        }
    }
    
    int totalNQueens(int n) {
        rec(0,n);
        return ans;
    }
};