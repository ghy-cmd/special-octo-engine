#include<iostream>
#include<vector>
#include<map>
#include<ctime>
#include<cstdlib>
#include<time.h>
using namespace std;

class RandomizedSet {
public:
    RandomizedSet() {
        srand((unsigned int) time(NULL));
    }
    
    bool insert(int val) {
        if (hash.find(val)!=hash.end())
        {
            return false;
        }else{
            int n=vec.size();
            vec.push_back(val);
            hash[val]=n;
            return true;
        }
    }
    
    bool remove(int val) {
        if (hash.find(val)!=hash.end())
        {
            int temp=*(vec.end()-1);
            vec[hash[val]]=temp;
            hash[temp]=hash[val];
            vec.pop_back();
            hash.erase(val);
            return true;
        }else{
            return false;
        }
    }
    
    int getRandom() {
        int n=vec.size();
        if (n==1)
        {
            return vec[0];
        }else
        {
            int randomNum=rand()%n;
            return vec[randomNum];
        }
    }

private:
    vector<int> vec;
    map<int,int> hash;
};

int main(){
    RandomizedSet* obj = new RandomizedSet();
    cout<<obj->insert(0)<<endl;
    cout<<obj->insert(1)<<endl;
    cout<<obj->remove(0)<<endl;
    cout<<obj->insert(2)<<endl;
    cout<<obj->remove(1)<<endl;
    cout<<obj->getRandom()<<endl;
    return 0;
}
/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */