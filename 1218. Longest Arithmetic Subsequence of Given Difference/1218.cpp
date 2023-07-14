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