#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0,candidate=0;
        for (auto it = nums.begin(); it != nums.end(); it++)
        {
            if (count==0)
            {
                candidate=*it;
                count++;
            }else{
                if (candidate==*it)
                {
                    count++;
                }else
                {
                    count--;
                }
            }
        }
        return candidate;
    }
};

int main(){
    Solution a;
    vector<int> vec={2,2,1,1,1,2,2};
    cout<<a.majorityElement(vec)<<endl;
    return 0;
}