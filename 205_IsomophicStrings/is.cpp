#include <string>
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
    	string m1 = getStringMode(s);
    	string m2 = getStringMode(t);
    	cout<<m1<<"     "<<m2<<endl;
    	if(m1 == m2) return 1;
    	return 0;
        
    }
    string getStringMode(string &s){
    	string::size_type len = s.size();
    	string::size_type i = 0;
    	vector<char> v;
    	string mode;
    	for(;i<len;++i){
    		vector<char>::size_type pos = findChar(v,s[i]);
    		//if s[i] was found
    		if(pos!=v.size()){
    			string temp="a";
    			temp[0] = 'a'+pos;
    			mode = mode+temp;  //Normalized by starting from 'a'
    		}
    		else{
    			string temp="a";
    			temp[0] = 'a'+v.size();
    			mode = mode+temp;
    			v.push_back(s[i]);  
    		}

    	}
    	return mode;
    }
    vector<char>::size_type findChar(vector<char> &v, char c){
    	for (vector<char>::size_type iter = 0; iter!=v.size(); iter++ ){
    		if(v[iter] == c) return iter;
    	}
    	return v.size();

    }
};

int main()
{
	Solution s;
	string s1,s2;
	cout<<"input:";
	cin>>s1>>s2;
	cout<<s.isIsomorphic(s1,s2)<<endl;
}