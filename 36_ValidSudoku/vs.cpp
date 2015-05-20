#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
	//Solution(arguments);
	//~Solution();
	bool isValidSudoku(vector< vector<char> >& board){
		int size=9;
		//For cols and rows
		for(int i=0; i<size; i++){
			vector<char> v;
			for(int j=0; j<size; j++){
				if(board[i][j] != '.') {
					if(board[i][j] >'9' || board[i][j] <'1') return false;
					v.push_back(board[i][j]);
				}
			}
			if(!isDistinct(v))	return false;
			v.clear();
			for(int k=0; k<size; k++){
				if(board[k][i] != '.') {
					if(board[k][i]>'9' || board[k][i] <'1') return false;
					v.push_back(board[k][i]);
				}
			}			
			if(!isDistinct(v))	return false;
		}
		//For 9 squares
		for(int i=0; i<size; i++){
			vector<char> v;
			int colWeight = (i/3)*3;  //Used when computing index
			int rowWeight = (i%3)*3;
			for(int j=0; j<3; j++){
				for(int k=0; k<3; k++){
					if(board[j+colWeight][k+rowWeight] != '.')
						v.push_back(board[j+colWeight][k+rowWeight]);					
				}
			}
			if(!isDistinct(v))	return false;
		}
		return true;
	}

	bool isDistinct(vector<char>& v){
		int len = v.size();
		for(int i=0; i<len; i++)
			for(int j=i+1; j<len; j++)
				if(v[i]==v[j]) return false;
		return true;
	}
	/* data */
};

int main(){
	return 0;
}