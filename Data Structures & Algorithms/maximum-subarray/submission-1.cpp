class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = INT_MIN;
        int temp = 0;
        int count = 0;
        int min = INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i] < 0){
                count++;
            }
            min = max(min,nums[i]);
        }
        if(count == nums.size()){
            return min;
        }
        else{
            for(int i=0;i<nums.size();i++){
            temp += nums[i];
            if(temp < 0){
                temp = 0;
            }
            sum = max(sum,temp);
        }
        }
        return sum;
    }
};
