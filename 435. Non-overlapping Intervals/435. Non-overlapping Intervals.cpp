class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        int end = intervals[0][1];
        int ans=0;
        for(int i = 1;i<n;i++){
            if(end>intervals[i][0]){
                ans++;
                end = min(intervals[i][1],end);
            }else{
                end = intervals[i][1];
                
            }
        }
        for(auto x:intervals){
            cout<<x[0]<<","<<x[1]<<endl;
        }
        return ans;
    }
};