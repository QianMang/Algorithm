//746. Min Cost Climbing Stairs
/*class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1);
        if(n == 0 || n == 1)return 0;
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i = 2 ; i < n ; ++i){
            dp[i] = min(dp[i-1],dp[i-2]) + cost[i];
        }
        return min(dp[n-1],dp[n-2]);
    }
};
*/
//不使用dp数组
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
       // vector<int> dp(n+1);
        if(n == 0 || n == 1)return 0;
        int dp1 = cost[0];
        int dp2 = cost[1];
        for(int i = 2 ; i < n ; ++i){
           int dp3 = min(dp1,dp2) + cost[i];
            dp1 = dp2;
            dp2 = dp3;
        }
        return min(dp1,dp2);
    }
};
