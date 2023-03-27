#include <iostream>
#include <vector>
using namespace std;
//declaring constants
int N = 9;
vector<vector<int> > nums {{0,0,0,0,0,0,0,0,0},
			   {0,8,1,0,0,0,0,0,0},
			   {0,4,0,0,0,0,0,0,0},
			   {0,0,0,0,0,0,0,0,0},
			   {0,0,0,0,0,0,0,0,0},
			   {0,0,0,4,0,0,0,0,0},
			   {0,0,0,0,0,0,0,0,0},
			   {0,0,0,0,0,0,0,0,0},
			   {0,0,0,0,0,0,0,0,0}};
//SubGrid Counter
//
// 1 | 2 | 3
// 4 | 5 | 6
// 7 | 8 | 9
//
//Grid1: 0,0
//Grid2: 0,3
//Grid3; 0,6
//Grid4: 3,0
//Grid5: 3,3
//Grid6; 3,6
//Grid7: 6,0
//Grid8: 6,3
//Grid9: 6,6

//function for checking if number is present in row (horizontal)
bool checkNumberRow (int row, int search) {
	int searchRow = row - 1;

	for (int i = 0; i < nums[searchRow].size(); i++){
		if (nums[searchRow][i] == search){
			return true;
		}
	}
	return false;
}

//function for checking number presence in col (vertical)
bool checkNumberCol (int col, int search) {
	int searchCol = col - 1;
	
	for (int i = 0; i < nums.size();i++){
		if (nums[i][searchCol] == search){
			return true;
		}
	}
	return false;
}

//function for checking number presence in subgrid (1-9)
bool checkSquare (int squareRow, int squareCol, int search){
       for (int i = squareRow; i < squareRow + 3; i++) {
	       for (int j = squareCol; j < squareCol + 3; j++){
		       if (nums[i][j] == search) {
			       return true;
			}
		}
	}
       return false;
		
}       


int main(int argc, char* argv[]){

	//loop for printing out grid layout 
	for (int row = 0; row < nums.size(); row++) {
		//using a while loop for horizontal line
		int counter = 11;
		if (row == 3 || row == 6){
			while (counter > 0){
				cout << "- ";
				counter--;
			}
			cout<<endl;
		}
		
		for (int col = 0; col < nums[row].size();col++){
			cout << nums[row][col] << " ";
			//printing out veritical lines
			if (col == 2 || col == 5) //remember that col starts at 0;
				cout << "| ";
		}
	cout<<endl;
	}
	
	bool testing = checkSquare(0, 0, 8);
	
	if (testing == true){
		cout << "True!";
	} else {
		cout << "False!";
	}
}
