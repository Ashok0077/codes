#include <iostream>
#include <vector>

using namespace std;
class Solution {
private:
    void solve(vector<int> &nums , vector<vector<int>> &ans,vector<int> output,int index){
        if(index>=nums.size()){
            ans.push_back(output);
            return;
        }

        solve(nums,ans,output,index+1);
        output.push_back(nums[index]);
        solve(nums,ans,output,index+1);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        solve(nums,ans,output,0);
        return ans;
    }
};

int main()
{
    Solution obj;
    vector<int> nums={1,2,3};
    vector<vector<int>> a;
    a=obj.subsets(nums);
    int n=a.size();
    
    for(int i=0;i<n;i++){
        int m=a[i].size();
        
        for(int j=0;j<m;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
