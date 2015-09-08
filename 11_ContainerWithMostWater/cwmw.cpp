#include <iostream>
#include <vector>

using namespace std;
//2-level iteration is too slow!
class Solution { 
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        if( len < 2)    return 0;
        int result=0;
        for( int i=0; i<len-1; ++i) {
            for(int j=i+1; j<len; ++j) {
                int temp = (height[i]<height[j]? height[i]:height[j])*(j-i); 
                result = result>temp? result:temp;
            }
        }
        return result;
    }
};

class Soution2 {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        if(len<2) return 0;
        int l=0,r=len-1;
        int max=(len-1)*(height[l]<height[r]? height[l]:height[r]);
        while(l<r) {
            if(height[l]<=height[r]) {
                int i;
                for(i=l+1;i<=r;i++) {
                    if(height[i]>height[l]) {
                        int s;
                        s =(r-i)*( height[i]<height[r]? height[i]:height[r]);
                        max = max>s? max:s;
                        break;
                    }
                }
                l = i;
            }else {
                int i;
                for(i=r-1;i>=l;i--) {
                    if(height[i]>height[r]) {
                        int s;
                        s =(i-l)*( height[i]<height[l]? height[i]:height[l]);
                        max = max>s? max:s;
                        break;
                    }
                }
                r = i;
            return max;
            }
        }
    }
};






int main() {
    return 1;
}
