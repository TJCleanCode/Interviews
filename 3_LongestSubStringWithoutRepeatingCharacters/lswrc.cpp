#include <iostream>
#include <map>
#include <string>

using namespace std;

class Solution{
public:
    int lengthOfLongestSubstring(string s) {
        int minPos=0 ;
        int maxCount =0;
        map<char, int> hs;
        for(int i=0; i<s.size(); ++i){
            map<char, int>::iterator f = hs.find(s[i]);
            if(f != hs.end()) {
                if(minPos < f->second+1) minPos = f->second + 1;
                hs.erase(f);
            } 
            hs.insert(pair<char, int> (s[i],i));
            if(i-minPos +1> maxCount) maxCount = i-minPos + 1;
        }
        return maxCount;
    }
};

int main() {
    string s;
    cout<< "Input the string: "<<endl;
    cin>>s;
    Solution t;
    cout<< t.lengthOfLongestSubstring(s)<<endl;    
    return 1;
}
