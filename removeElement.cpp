#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int l=0;
        for(int j=0;j<nums.size();j++)
        {
            if(nums[j]!=val)

            {
            nums[l]=nums[j];
            l++;
            
            }
        }
        return l;
    }
};

int main(){
    Solution a;
    vector<int> vec={1};
    int val=1;
    cout<<a.removeElement(vec,val)<<endl;
    for(auto it=vec.begin();it!=vec.end();it++){
        cout<<*it<<" ";
    }
    return 0;
}