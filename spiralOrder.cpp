#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int a=matrix.size(),b=matrix[0].size(),m=a,n=b,k=0;
        vector<int> res;
        do
        {
            if (m==1)
            {
                for (int i = k; i < b-k; i++)
                {
                    res.push_back(matrix[k][i]);
                }
                break;
            }else if (n==1)
            {
                for (int i = k; i < a-k; i++)
                {
                    res.push_back(matrix[i][k]);
                }
                break;
            }
            for (int j = k; j < b - k; j++) {
                res.push_back(matrix[k][j]);
            }
            for (int j = k + 1; j < a - k - 1; j++) {
                res.push_back(matrix[j][b - k - 1]);
            }
            for (int j = b - k - 1; j >= k; j--) {
                res.push_back(matrix[a - k - 1][j]);
            }
            for (int j = a - k - 2; j >= k + 1; j--) {
                res.push_back(matrix[j][k]);
            }
            k++;
            m=m-2;
            n=n-2;
        } while (m>0 && n>0);
        
        return res;
    }
};

int main(){
    vector<vector<int>> a={{1,2,3},{4,5,6}};
    Solution b;
    vector<int> c=b.spiralOrder(a);
    for (auto it = c.begin(); it != c.end(); it++)
    {
        cout<<*it<<" ";
    }
    return 0;
}