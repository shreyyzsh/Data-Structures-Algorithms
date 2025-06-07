
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            vector<int> indices(2, 0);
            for (int i = 0; i < nums.size(); i++)
                for (int j = i+1; j < nums.size(); j++) {
                    if ((nums[i]+nums[j]) == target) { 
                        indices[0] = i;
                        indices[1] = j;
                    }
                }
            return indices;
        }
};

int main(void) {
    Solution test1;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = test1.twoSum(nums, target);

    cout << result[0] << " " << result[1] << endl;

    return 0;
}