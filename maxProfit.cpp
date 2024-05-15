#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min=INT_MAX,res=0,temp=0;
        for (auto it : prices)
        {
            int t=it;
            if (res>(t-min))
            {
                min=t;
                temp+=res;
                res=0;
            }else if ((t-min)>res)
            {
                res=t-min;
            }
        }
        return temp+res;
    }
};
int main(){
    Solution a;
    vector<int> vec={1,2,3,4,5};
    cout<<a.maxProfit(vec)<<endl;
    return 0;
}