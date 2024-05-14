#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
    }
};

int main(){
    Solution a;
    vector<int> vec={1,2,3,4,5,6};
    a.rotate(vec,4);
    for (auto it = vec.begin(); it != vec.end(); it++)
    {
        cout<<*it<<" ";
    }
    return 0;
}