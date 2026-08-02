class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans= -DBL_MAX;
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(i >=k){
                sum-=nums[i-k];
            }
            if(i>=k-1){
                ans=max(ans,(double)sum/k);
            }
        }
       return ans;
        
    }
};