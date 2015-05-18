#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	//Solution(arguments);
	//~Solution();

	int removeDuplicates(vector<int>& nums){
		if(nums.size() == 0) return 0;
		if(nums.size() == 1) return 1;
		vector<int>::iterator pre=nums.begin();
		vector<int>::iterator it=pre+1;

		while(it != nums.end()){
			if (*it != *pre)
			{
				it++;
				pre++;
				continue;
			}
			while(*it == *pre && it!=nums.end())  //Be careful about while-in-while situation
				it++;                             //Especially when using iterator.
			if(it == nums.end()){
				nums.erase(pre+1, it);            //When you change the vector, its elements change.
				break;
			}
			it = nums.erase(pre+1, it);           //Method Erase() is slow???
			pre = it;
			it++;
		}
		return nums.size();
	}
	/* data */
};

int main(){
	Solution s;
	vector<int> v;
	int temp;
	cout<<"input:"<<endl;
	while(cin>>temp)
		v.push_back(temp);
	cout<<s.removeDuplicates(v)<<endl;	
}