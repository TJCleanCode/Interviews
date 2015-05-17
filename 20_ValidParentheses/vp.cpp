#include <stack>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	bool isValid(string s){
		if(s.size()%2 == 1) return false;  //The special one is always the easiest one to deal with
		stack<char> list;
		string::size_type i=0;
		for(;i<s.size();i++){
			if(s[i]=='(' || s[i]=='[' || s[i]=='{') 
				list.push(s[i]);
			else if(list.empty() || (list.top()!=s[i]-1 && list.top()!=s[i]-2))  
			//Pay attention to the empty situation
				return false;
			else
				list.pop();
		}
		if(list.empty())
			return true;
		return false;
	}
};

int main()
{
	Solution s;
	string test;
	cout<<"input:";
	cin>>test;
	cout<< s.isValid(test)<<endl;	
}
