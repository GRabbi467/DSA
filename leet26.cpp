#include<bits/stdc++.h>
using namespace std;
  int removeDuplicates(vector<int>& nums) {
        vector<int>::iterator itr ;
        itr = nums.begin();
         for(int i = 0 ; i < nums.size()-1; i++){
            if(nums[i] == nums[i+1])
               {
                    nums.erase(itr +i);
                    i--;
               }
         }
         return nums.size();
  }

int main(){
    vector<int>v{0,0,1,1,1,2,2,3,3,4};
    cout<<removeDuplicates(v);




}
