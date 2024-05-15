#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min=-1,res=0;
        for (auto it = prices.begin(); it != prices.end(); it++)
        {
            int t=*it;
            if (min==-1 || t<min)
            {
                min=t;
            }else if ((t-min)>res)
            {
                res=t-min;
            }
        }
        return res;
    }
};
int main(){
    Solution a;
    vector<int> vec={2,4,1};
    cout<<a.maxProfit(vec)<<endl;
    return 0;
}