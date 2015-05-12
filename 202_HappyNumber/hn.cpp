#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	//Solution(arguments);
	//~Solution();

	bool isHappy(int n){
		vector<int> v;
		v.push_back(n);
		vector<int>::size_type i=0;
		while(1){
			int temp;
			temp = squareSum(v[i]);
			if(temp == 1) return true;
			else if(isfind(v,temp)) return false;
			v.push_back(temp);
			i++;
		}
	}
	int squareSum(int n){
		int sum=0;
		while(n){
			int m=n%10;
			sum = sum+m*m;
			n = n/10;
		}
		cout<<sum<<endl;
		return sum;
	}
	bool isfind(vector<int> &v, int n){
		vector<int>::size_type iter;
		for(iter =0; iter!=v.size(); iter++){
			if(v[iter]==n)
				return true;
		}
		return false;
	}
};

int main(){
	Solution s;
	int n;
	cout<<"input:";
	cin>>n;
	cout<<s.isHappy(n)<<endl;
	return 1;
}