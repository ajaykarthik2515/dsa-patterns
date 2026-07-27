class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return -1;
        if(n==1) return 0;
        vector<int> prefix(n);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i];
        }
        int totalSum = prefix[n-1];
           int leftSum, rightSum;
        for(int i=0;i<n;i++){
            
            leftSum = i==0? 0: prefix[i-1];
            rightSum = totalSum-prefix[i];
            if(leftSum==rightSum) return i;
        }
       return -1;
        
    }
};

