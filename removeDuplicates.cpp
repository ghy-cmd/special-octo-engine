#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0,p=1,q=2;
        int s=nums.size();
        if (s<=2)
        {
            return s;
        }
        
        while (q<s)
        {
            if (nums[q]==nums[p] && nums[q]==nums[i])
            {
                q++;
            }else{
                nums[++p]=nums[q++];
                i++;
            }
        }
        return p+1;
    }
};

int main(){
    Solution a;
    vector<int> vec={1};
    int p=a.removeDuplicates(vec);
    cout<<p<<endl;
    for (int i = 0; i < p; i++)
    {
        cout<<vec[i]<<" ";
    }
    
    return 0;
}