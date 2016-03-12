#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int i(m-1),j(n-1),k(m+n-1);
		while(j>=0) {
		    nums1[k--] = i>=0&&nums1[i]>nums2[j]? nums1[i--]:nums2[j--];
		}
	}
};

int main() {
	Solution s;
	vector<int> nums1,nums2;
	cout<< "input nums1:"<<endl;
	int temp;
	while(cin>>temp) {
		nums1.push_back(temp);
	}
	cin.clear();
	cin.ignore();
	cout<<"temp "<<endl;
	cin>>temp;
	cout<< "input nums2:"<<endl;
	while(cin>>temp) {
		nums2.push_back(temp);
	}

	s.merge(nums1,nums1.size(),nums2,nums2.size());
	
	for(int i=0; i<nums1.size(); i++) {
		cout<< nums1[i] <<endl;
	}	
	return 1;
}