#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class Solution{
public:
	int climbStairs(int n) {
		if (n<3) return n;
		else{
			int note[2] = { 1,2 };
			int result;
			for( int i=3; i<=n ; ++i){
				result = note[0]+ note[1];
				note[0] = note[1];
				note[1] = result;	
			}			
			
			return result;
		}	
		//return n>2? climbStairs(n-1)+climbStairs(n-2):n;
	}
};


int main(){
	cout<< "input the number of stairs:"<<endl;
	int n; 
	cin >> n;
	Solution s;
	cout<< s.climbStairs(n)<<endl;
	return 1;
}
