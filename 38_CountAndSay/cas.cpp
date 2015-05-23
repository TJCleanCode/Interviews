#include <vector>
#include <string>
#include <iostream>

using namespace std;
class Solution
{
public:
	//Solution(arguments);
	//~Solution();
	string countAndSay(int n){
		if(n==1) return "1";
		if(n==2) return "11";
		string m = countAndSay(n-1);
		string ans="";
		char count='1';
		for(int i=1; i<m.size(); ++i){
			if(m[i] == m[i-1]){
				count++;
			}
			else{
				ans = ans+count+m[i-1];
				count = '1';
			}
		}
		ans = ans+ count +m[m.size()-1];
		return ans;
	}
	/* data */
};

int main()
{
	Solution test;
	string s;
	int n;
	cout<<"input:";
	cin>>n;
	cout<<test.countAndSay(n)<<endl;
}