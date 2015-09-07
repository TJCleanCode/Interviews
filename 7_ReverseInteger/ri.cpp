#include <iostream>
#include "limits.h"

using namespace std;

class Solution {
public:
    int reverse(int x) {
        long long  result =0 ;
        while(x != 0) {
            result = result*10 + x%10;
            x = x/10;
        }
        if(result >INT_MAX || result < INT_MIN)
            result=0;
        return result;
    }
};

int main() {
    int x;
    cout<<"Input an integer: " <<endl;
    cin >>x;
    Solution test;
    cout<< test.reverse(x)<<endl;
}
