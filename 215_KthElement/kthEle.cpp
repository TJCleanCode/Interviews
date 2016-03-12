#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
      int findKthLargest( vector<int>& nums, int k) {
          return find(nums, 0, nums.size()-1, nums.size()-k);
      }

      int find( vector< int > & nums, int s, int t, int k) {
          if( s==t ) return nums[s];
          else {
              int pivot = nums[t];
              int i = s-1;
              int j = s;
              for( ; j<t; j++) {
                  if(nums[j] <= pivot) {
                      i++;
                      int temp;
                      temp = nums[i];
                      nums[i] = nums[j];
                      nums[j] = temp;
                  }
              }
              
              int temp;
              temp = nums[t];
              nums[t] = nums[++i];
              nums[i] = temp;
              int rank = i-s;
              if(rank==k) return nums[i];
              else if( rank>k ) find(nums, s, i-1, k);
              else find(nums, i+1, t, k-rank-1); 
          }
      }
};


int main() {
    vector< int > nums;
    int num;
    while(cin >> num) {
        nums.push_back(num);
    }
    cin.clear();
    
    int k;
    cout << "What is k:"<<endl;
    cin >> k;

    Solution s;
    cout << s.findKthLargest(nums, k)<<endl;
    return 1;
}
