#include <vector>
#include <iostream>
using namespace std;

/*It's a simple idea to check the input table 
  following the given rule. That means you should
  check the numbers of every row, col, square.
  This is clear and easy to do. But if you put a little 
  more notice into it, you will find that each number is 
  visited 3 times.
  So what matters is not a valid solution, but a good solution
  you should definitly do more ANALISIS to your answer*/
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

/*Thinking it from the DATA VIEW, you will find that
  when a number is visited, its validness can be checked
  according the three rules.*/
class OneTimeSolution{
public:
	bool isValidSudoku(vector< vector<char> >& board){
		int used1[9][9] = {0}, used2[9][9] = {0}, used3[9][9] = {0};

        for(int i = 0; i < board.size(); ++ i)
            for(int j = 0; j < board[i].size(); ++ j)
                if(board[i][j] != '.')
                {
                    int num = board[i][j] - '0' - 1, k = i / 3 * 3 + j / 3;
                    if(used1[i][num] || used2[j][num] || used3[k][num])
                        return false;
                    used1[i][num] = used2[j][num] = used3[k][num] = 1;
                }

        return true;
	}
};

int main(){
	return 0;
}