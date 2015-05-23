#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
	//Solution(arguments);
	//~Solution();
	int lengthOfLastWord(string s){
		int len = s.size();
		if(len == 0) return 0;
		int count=0;
		bool notNull=0;
		for(int i=len-1; i>=0; i--){
			if(s[i] != ' '){
				count++;
				notNull =1;
			}
			if(notNull ==1 && s[i]==' ') break;			
		}
		return count;
	}
	/* data */
};

int main()
{
	Solution test;
	string s = "a   ";
	cout<<test.lengthOfLastWord(s)<<endl;
}