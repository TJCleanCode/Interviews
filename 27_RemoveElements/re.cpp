#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
	//Solution(arguments);
	//~Solution();
	int removeElements(vector<int>& nums, int val){
		int len = nums.size();
		if(len<1) return len;
		vector<int>::size_type p = 0;
		vector<int>::size_type q = len-1;
		for(;p<=q;p++){
			while(nums[q]==val && q>p){
				nums.pop_back();
				q--;
			}  //Make the last one not equal to val
			if(q==p && nums[p]==val){nums.pop_back();break;} 
			if(nums[p] == val){
				nums[p] = nums[q];
				nums.pop_back();
				q--;
			}
		}
		return nums.size();
	}

	void printVector(vector<int> &v){
		for(int i=0;i<v.size();i++)
			cout<<v[i]<<"  ";
		cout<<endl;
	}
	/* data */
};

int main(){
	Solution s;
	vector<int> v;
	int temp;
	cout<<"input:"<<endl;
	while(cin>>temp){
		v.push_back(temp);
	}
	cout<<s.removeElements(v,1)<<endl;

}