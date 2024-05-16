#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void rotate_1(vector<int>& nums, int k) {
        int size=nums.size();                       
        k=k%size;
        int n=-1,j=-1,temp,tt;
        for (int i = 0; i < size; i++)
        {
            if (j==n)
            {
                n=n+1;
                j=n;
                temp=nums[j];
            }
            j=(j+k)%size;
            tt=nums[j];
            nums[j]=temp;
            temp=tt;
        }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
    }
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=0,temp;
        do
        {
            for (int i = 0; i < n-2*m-1; i++)
            {
                temp=matrix[m][m+i];
                swap(matrix[m+i][n-m-1],temp);
                swap(matrix[n-m-1][n-m-1-i],temp);
                swap(matrix[n-m-1-i][m],temp);
                swap(matrix[m][m+i],temp);
            }
            m++;
        } while (2*(m+1)<=n);
    }
};

int main(){
    Solution a;
    vector<vector<int>> vec={{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    a.rotate(vec);
    for (auto it :vec)
    {
        for (auto i :it)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}