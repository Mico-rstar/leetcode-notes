#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
using namespace std;



class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> path;
        auto dfs = [&](this auto&& dfs, int i, std::set<int> &x) -> void {
            if(i == n) {
                ans.emplace_back(path);
                return;
            }

            for(const auto& s: x) {
                path.push_back(s);
                x.erase(x.find(s));
                dfs(i + 1, x);
                x.insert(s);
                path.pop_back();
            }
        };
        std::set<int> x;
        for(const auto &num: nums) {
            x.emplace(num);
        }
        dfs(0, x);
        return ans;
    }
};

int main() {
    Solution sl;
    vector<int> nums = {1, 2, 3};
    sl.permute(nums);
    return 0;
}
