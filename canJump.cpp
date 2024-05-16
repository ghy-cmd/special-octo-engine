#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int s=nums.size(),t=nums[0];
        if (s==1)
        {
            return true;
        }
        
        for (int i = 0; i < min(t,s); i++)
        {
            if ((i+nums[i]>=s-1))
            {
                return true;
            }
            t=max(t,i+nums[i]+1);
        }
        return false;
    }
};

int main(){
    Solution a;
    vector<int> vec={1,2,3};
    cout<<a.canJump(vec)<<endl;
    return 0;
}