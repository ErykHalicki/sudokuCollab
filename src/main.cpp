#include <iostream>
#include <vector>
using namespace std;
//declaring constants
int N = 9;
vector<vector<int> > nums {{1,0,0,0,0,0,0,0,0},
			   {1,8,1,0,0,0,0,0,0},
			   {0,4,0,0,0,0,0,0,0},
			   {0,0,0,0,0,0,0,0,0},
			   {0,0,0,0,0,0,0,0,0},
			   {0,0,0,4,0,0,0,0,0},
			   {0,0,0,0,0,0,0,0,0},
			   {0,0,0,0,0,0,0,0,0},
			   {0,0,0,0,0,0,0,0,0}};
bool touchable[9][9];
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
bool checkRowValid(int row) {
	bool* squares=(bool*)malloc(sizeof(bool)*10);
	for (int i = 0; i < 9; i++){
		if(squares[nums[row][i]]&&nums[row][i]>0){
			free(squares);
			return false;
		}
		else squares[nums[row][i]]=true;
	}
	free(squares);
	return true;
}

//function for checking number presence in col (vertical)
bool checkColumnValid (int col) {
	bool* squares=(bool*)malloc(sizeof(bool)*10);
	for (int i = 0; i < 9;i++){
		if (squares[nums[i][col]]&&nums[i][col]>0){
			free(squares);
			return false;
		}
		else squares[nums[i][col]]=true;
	}
	free(squares);
	return true;
}

//checks if the square is valid (only contains one of each number)
bool checkSquareValid (int squareRow, int squareCol){
	bool* squares=(bool*)malloc(sizeof(bool)*10);
       	for (int i = squareRow; i < squareRow + 3; i++) {
		for (int j = squareCol; j < squareCol + 3; j++){
			if(i<9 && j<9){
				if (squares[nums[i][j]]&&nums[i][j]>0) {
					free(squares);
			       		return false;
				}
				else squares[nums[i][j]]=true;
		       }
		}
	}
       free(squares);
       return true;	
}      
bool checkBoard(){//returns true is board is valid
	for(int h=0;h<9;h++){
		for(int v=0;v<9;v++){
			if(!checkColumnValid(v))return false;	
		}
		if(!checkRowValid(h))return false;
	}
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(!checkSquareValid(i*3,j*3))return false;
		}
	}
	return true;	
}
void printBoard(){
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

}
bool solved(){
	for(int h=0;h<9;h++){
		for(int v=0;v<9;v++){
			if(nums[v][h]==0)return false;
		}
	}
	return true;
}
void createTouchable(){
	for(int v=0;v<9;v++){
		for(int h=0;h<9;h++){
			if(nums[v][h]==0)touchable[v][h]=true;
		}
	}
}
void solve(){
	for(int h=0;h<9;h++){
		for(int v=0;v<9;v++){
				while(!checkBoard()&&touchable[v][h]){
					nums[v][h]++;
					if(nums[v][h]>=10){//if all numbers have been tried and still failed, go back to the previous square
						nums[v][h]=0;
						v--;
					}
					if(v<0){//if the entire column failed, go back to the bottom of previous
						h--;
						v=8;
					}
					if(h<0){
						cout<<"unsolvable";
						return;
					}
				}
			printBoard();
			cout<<'\n';
		}	
	}
}


int main(int argc, char* argv[]){
	createTouchable();
	solve();	
}
//git add.
//git commit
//git push
