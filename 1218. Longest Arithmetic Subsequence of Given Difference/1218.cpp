class Solution {
private:
    int find(int index,int last,int d,int n,vector<int>& nums,vector<vector<int>>&dp){
        if(index >= n) return 0;
        int take = 0;
        int notTake = 0;
        // if(dp[index][last] != -1) return dp[index][last];
        if(last == 1e9){
            notTake = find(index+1,last,d,n,nums,dp);
            take = 1+ find(index+1,nums[index],d,n,nums,dp);
        }else{
            notTake = find(index+1,last,d,n,nums,dp);
            if(nums[index] - last == d){
                take = 1+ find(index+1,nums[index],d,n,nums,dp);
            }
        }
        return max(take,notTake);
    }
public:
    int longestSubsequence(vector<int>& arr, int d) {
        int n = arr.size();
        unordered_map<int,int>dp;
        int ans = 1;
        for(int i = 0;i<n;i++){
            int num = arr[i];
            if(dp.find(num-d) != dp.end()){
                dp[num] = dp[num-d]+1;
            }else{
                dp[num] = 1;
            }
            ans = max(dp[num],ans);
        }
        return ans;
    }
};



// hello it is verified