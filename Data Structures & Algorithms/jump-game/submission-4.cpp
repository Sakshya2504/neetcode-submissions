class Solution {
public:
    bool canJump(vector<int>& nums) {
        int sum = 0;

        if(nums.size() == 1) return true;

        for(int i = 0; i < nums.size(); i++) {

            if(i > sum)
                return false;

            sum = max(sum, i + nums[i]);

            if(sum >= nums.size() - 1)
                return true;
        }

        return false;
    }
};