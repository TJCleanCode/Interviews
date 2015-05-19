#include <iostream>
#include <vector>
#include <map>

using namespace std;
class Solution{
public:
	vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> t;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
        	t.insert(make_pair(nums[i],i));
        }
        for(int i=0;i<nums.size();i++){
        	map<int,int>::iterator it = t.find(target-nums[i]);
        	if(it == t.end() || it->second==i) continue;
        	ans.push_back(min(i,it->second)+1);
        	ans.push_back(max(i,it->second)+1);
        	/*
        	 int j=it->second;
            if(i<j){
                ans.push_back(i);
                ans.push_back(j);
            }else{
                ans.push_back(j);
                ans.push_back(i);
            }
            */
        	break;
        }
        return ans;
    }
};

int main(){
	Solution s;
	vector<int> v,ans;
	int temp;
	cout<<"input:"<<endl;
	while(cin>>temp) v.push_back(temp);
	cin.clear();
	cout<<"target:";
	int t;
	cin>>t;
	ans = s.twoSum(v,t);
	cout<<ans[0]<<"   "<<ans[1]<<endl;

}