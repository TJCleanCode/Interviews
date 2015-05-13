#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution{
public:
	string longestCommonPrefix(vector<string>& strs){
		if(strs.size()==0) return "";
		return lcp(strs,0,strs.size()-1);
	}

	string lcp(vector<string>& strs,vector<string>::size_type start, \
			   	vector<string>::size_type end){
		if(start == end) return strs[start];
		vector<string>::size_type mid = (start+end)/2;
		string s1 = lcp(strs, start, mid);
		string s2 = lcp(strs, mid+1, end);
		return merge(s1,s2); 
	}

	string merge(string& s1, string& s2){
		int i=0;
		string s;
		for(;i!=s1.size() && i!=s2.size(); i++){
			if(s1[i] != s2[i]) return s;
			s = s + s1[i];  //string+char is totally right.
		}
		return s;
	}
};

int main(){
	Solution s;
	vector<string> str;
	string temp;
	cout<<"input:"<<endl;
	while(cin>>temp){
		str.push_back(temp);
	}
	cout<<s.longestCommonPrefix(str)<<endl;
}