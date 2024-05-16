#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
        int size=nums.size(),t;
        vector<int> res(size,INT_MAX);
        res[0]=0;
        for (int i = 0; i < size; i++)
        {
            t=nums[i];
            for (int j = i+1; j < min(size,i+t+1); j++)
            {
                res[j]=min(res[j],res[i]+1);
            }
        }
        return res[size-1];
    }
};

int main(){
    Solution a;
    vector<int> vec={2,3,1,1,4};
    cout<<a.jump(vec)<<endl;
    return 0;
}
