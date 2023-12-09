#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>

using namespace std;

class Solution {
private:
    void solve(vector<int> &nums, int index, vector<vector<int>> &ans, unordered_set<int> &s, vector<int> &output) {
        if (index >= nums.size()) {
            ans.push_back(output);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (s.find(nums[i]) != s.end()) {
                continue;
            }

            output.push_back(nums[i]);
            s.insert(nums[i]);
            solve(nums, index + 1, ans, s, output);  // Use i + 1 to move to the next element
            s.erase(nums[i]);
            output.pop_back();
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> ans;
        int index = 0;
        unordered_set<int> s;
        vector<int> output;

        solve(nums, index, ans, s, output);

        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = solution.permute(nums);

    for (const auto &perm : result) {
        for (int num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
