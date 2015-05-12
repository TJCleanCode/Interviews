#include <vector>
#include <iostream>
#include <string>
using  namespace std;
class Solution {
public:
    int compareVersion(string version1, string version2) {
    	string::size_type len1 = version1.size();
    	string::size_type len2 = version2.size();
    	string::size_type i=0;
    	string::size_type j=0;
    	while(i<len1 || j <len2){
    		int level1 = 0;
    		int level2 = 0;
            //Just make a comparation at each level
    		for(;i<len1 && version1[i]!='.';++i){
    			level1 = level1*10 + version1[i]-'0';            
    		}
    		for(;j<len2 && version2[j]!='.';++j){
    			level2 = level2*10 + version2[j]-'0';            
    		}
            
    		if (version1[i]=='.') i++;
    		if (version2[j]=='.') j++;  
    		cout<<"level:"<<level1<<"    "<<level2<<endl;  		
    		if (level1 > level2)
    			return 1;
    		else if(level1 < level2)
    			return -1;
    	}
    	return 0;
        
    }
};

int main()
{
	Solution s;
	string s1,s2;
	cout<<"input:";
	cin>>s1>>s2;
	cout<<s.compareVersion(s1,s2)<<endl;
	return 0;
}