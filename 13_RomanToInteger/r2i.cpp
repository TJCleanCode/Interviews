#include <iostream>
#include <string>
#include "map"
using namespace std;

class Solution {
public:
	int romanToInteger(string s){
		map<char, int> value;
		value.insert(pair<char, int>('M', 1000));
		value.insert(pair<char, int>('D', 500));
		value.insert(pair<char, int>('C', 100));
		value.insert(pair<char, int>('L', 50));
		value.insert(pair<char, int>('X', 10));
		value.insert(pair<char, int>('V', 5));
		value.insert(pair<char, int>('I', 1));
		int sum=value[s[0]];
		for(string::size_type i=1;i!=s.size();i++){
			if(value[s[i]] > value[s[i-1]])
				sum = sum + value[s[i]] - 2*value[s[i-1]];
			else
				sum = sum + value[s[i]];			
		}
		return sum;
	}
};

int main(){
	Solution s;
	string r;
	cout<<"input:";
	cin>>r;
	cout<< s.romanToInteger(r)<<endl;	
}