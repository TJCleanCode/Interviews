#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	//Solution(arguments);
	//~Solution();
	vector<int> plusOne(vector<int>& digits) {
		int len = digits.size();
		for(int i=len-1; i>=0; --i){
			if(digits[i]!=9) {
				digits[i] = digits[i]+1;
				break;
			}
			if(i==0){
				digits[0]=1;
				digits.push_back(0);
				return digits;
			}
			digits[i]=0;
		}
		return digits;
	}
	/* data */
};

void printVector(vector<int> v){    //Error when using '&'  ????
	for(int i=0;i<v.size();i++)
		cout<<v[i]<<" ";
	cout<<endl;
}

int main(){
	Solution s;
	vector<int> v;
	int temp;
	cout<<"input:"<<endl;
	while(cin>>temp){
		v.push_back(temp);
	}
	printVector(s.plusOne(v));
}