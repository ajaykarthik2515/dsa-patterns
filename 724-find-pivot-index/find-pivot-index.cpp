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

/*
Can we optimize it?

Yes. You don't actually need the entire prefix array.

Notice that:

leftSum = sum of elements before i
rightSum = totalSum - leftSum - nums[i]

So instead of storing all prefix sums, you can maintain a running leftSum.

Optimized Solution (O(1) Space)
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalSum = 0;

        for (int num : nums)
            totalSum += num;

        int leftSum = 0;

        for (int i = 0; i < nums.size(); i++) {
            int rightSum = totalSum - leftSum - nums[i];

            if (leftSum == rightSum)
                return i;

            leftSum += nums[i];
        }

        return -1;
    }
};
*/

