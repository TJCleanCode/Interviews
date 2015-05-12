#include <iostream>
using namespace std;

class Solution{
public:
	bool isPalindrome(int x){
		int temp = divisor(x);
		while(x != 0){
			if(x%10 != x/temp || x<0)
				return false;
			x = (x%temp)/10;
			//cout<<"x: "<<x<<endl;
			temp = temp/100;
		}
		return true;
	}
	int divisor(int &x){
		int temp=1;
		while(x/temp>=10){
			temp = temp*10;
		}
		//cout<<"temp: "<<temp<<endl;
		return temp;

	}
};

int main(int argc, char const *argv[])
{
	Solution s;
	int x;
	cout<<"input:";
	cin>>x;
	cout<<s.isPalindrome(x)<<endl;
	return 0;
}