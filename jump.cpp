#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
        int size=nums.size(),step=0,max_hoop=0,end=0;
        for (int i = 0; i < size-1; i++)
        {
            end=max(end,i+nums[i]);
            if (i==max_hoop)
            {
                max_hoop=max(end,i+nums[i]);
                step++;
            }
        }
        return step;
    }
};

int main(){
    Solution a;
    vector<int> vec={2,3,1,1,4};
    cout<<a.jump(vec)<<endl;
    return 0;
}
