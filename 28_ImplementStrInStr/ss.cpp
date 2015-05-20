#include <string>
#include <iostream>
using namespace std;

class Solution
{
public:
	//Solution(arguments);
	//~Solution();
	int strStr(string haystack, string needle){
		int hLen = haystack.size();
		int nLen = needle.size();
		if(hLen < nLen) return -1;
		if(!nLen) return 0;
		int i=0;
		for(;i<=hLen-nLen;i++){
			if(haystack[i]==needle[0]){
				int j=1;
				while(haystack[i+j]==needle[j] && j<nLen) j++;
				if(j==nLen) return i;
				continue;
			}
		}
		return -1;
	}
	/* data */
};

int main(){
	Solution s;
	string h,n;
	cout<<"input haystack:";
	cin>>h;
	cin.clear();
	cout<<"input needle:";
	cin>>n;
	cout<<s.strStr(h,n)<<endl;
}