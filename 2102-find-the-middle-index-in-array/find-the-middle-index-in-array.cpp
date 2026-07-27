class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        //same question as pivot index
        int n=nums.size();
        if(n==0) return -1;
        if(n==1) return 0;
        int totalSum=0;
        for(int i=0;i<n;i++){
            totalSum+=nums[i];
        }
        int rightSum, leftSum=0;
        for(int i=0;i<n;i++){
            rightSum = totalSum-leftSum-nums[i];
            if(leftSum==rightSum) return i;
            leftSum+=nums[i];
        }
        return -1;
    }
};