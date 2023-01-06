class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int ans = 0;
        while(target>0)
        {
            if(target%2==0 and maxDoubles)
            {
                target-=target/2;
                ans++;
                maxDoubles--;
            }
            else if(target%2 and maxDoubles){
                target-=1;
                ans++;
             }
            else if(maxDoubles==0){
              ans+=target;
              break;
            }
        }
            
        return ans-1;
    }
};