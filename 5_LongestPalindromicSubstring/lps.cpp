#include <iostream> 
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s){
        int maxLen = 0;
        int start(0),end(0);
        int j;
        for(int i=0; i<s.size(); ) {
            j=i+1;
            for(; j<s.size(); ++j) {
               if(s[j] != s[i])  break;  
            }
            int temp;
            temp = getLength(s,i, j-1);
            if(2*temp+j-i> maxLen) {
                maxLen =2*temp+j-i;
                start = i-temp;
                end = j+temp-1; 
                //cout<<maxLen<<"  i:"<<i<<"   j:"<<j<<"  temp:"<<temp<<"   start:"<<start<<"   end:"<<end<<"   s:"<<s.substr(start,end-start+1)<<endl;
            }
            i = j;
        }
        return s.substr(start, end-start+1);
    }

    int getLength(const string& s, int i, int j) {
        int k=1;
        for(; k<=i&& k<s.size() -j ; ++k) {
            if(s[i-k] != s[j+k]) break;
        }
        return k-1;
    }
};


int main(){
    string s;
    cout<< "Input string : "<<endl;
    cin>> s;
    Solution test;
    cout<<"result:"<<test.longestPalindrome(s)<<endl;

    return 1;
}
