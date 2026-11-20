#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                if(i ==j) {
                    continue;
                }
                if(nums[i] + nums[j] == target) {
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }

        return ans;
    }
};

int main() {
  Solution s;

  vector<int> nums = {2, 7, 11, 15};
  vector<int> ans = s.twoSum(nums, 9);

  cout << "ans: ";

  for(int i : ans) {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}
