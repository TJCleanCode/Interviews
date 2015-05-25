#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
	//Solution(arguments);
	//~Solution();
	string addBinary(string a, string b){
		int len;
		if(a.size() < b.size()){
			len = b.size();
			a = string(b.size()-a.size(),'0')+a;
		}else{
			len = a.size();
			b = string(a.size()-b.size(),'0')+b;
		}
		char carryFlag='0';
		for(int i=len-1; i>=0; --i){
			int sum = a[i]-'0'+b[i]-'0'+carryFlag-'0';
			a[i] = sum%2 + '0';
			carryFlag = (sum>1? '1':'0');
		}
		if(carryFlag == '1') a = "1"+a;
		return a;
	}
	/* data */
};

int main(){
	Solution test;
	string a,b;
	cout<<"a:";
	cin>>a;
	cout<<"b:";
	cin>>b;
	cout<<test.addBinary(a,b)<<endl;
	return 0;
}