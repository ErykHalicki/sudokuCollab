#include <iostream>
#include <vector>
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
using namespace std;
//declaring constants
bool showProcess=false;
vector<vector<int> > nums {{5,3,0,0,7,0,0,0,0},
			   {6,0,0,1,9,5,0,0,0},
			   {0,9,8,0,0,0,0,6,0},
			   {8,0,0,0,6,0,0,0,3},
			   {4,0,0,8,0,3,0,0,1},
			   {7,0,0,0,2,0,0,0,6},
			   {0,6,0,0,0,0,2,8,0},
			   {0,0,0,4,1,9,0,0,5},
			   {0,0,0,0,8,0,0,7,9}};
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
	bool* squares=(bool*)malloc(sizeof(bool)*10);//allocating memory for boolean array to which stores if each number has been seen before
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
       free(squares);//freeing memory used for boolean array to prevent memory leaks
       return true;	
}      
bool checkBoard(){//returns true is board is valid (all rows, columns and squares dont duplicate numbers except 0)
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
void printBoard(){//function for printing the entire board
	for (int row = 0; row < 9 ;row++) {
		//using a while loop for horizontal line
		int counter = 11;
		if (row == 3 || row == 6){
			while (counter > 0){
				cout << "- ";
				counter--;
			}
			cout<<endl;
		}
		
		for (int col = 0; col < 9;col++){
			cout << nums[row][col] << " ";
			//printing out veritical lines
			if (col == 2 || col == 5) //remember that col starts at 0;
				cout << "| ";
		}
	cout<<endl;
	}
	cout<<'\n';
}

void createTouchable(){
	for(int v=0;v<9;v++){
		for(int h=0;h<9;h++){
			if(nums[v][h]==0)touchable[v][h]=true;
		}
	}
}
void solve(int v, int h, int direction){
	if(showProcess){//if you want to see each iteration of the board  (debugging purposes)
		this_thread::sleep_for (std::chrono::milliseconds(10));
		system("clear");
		cout<<"currently solving square: "<<h+1<<","<<v+1;	
		cout<<'\n';
		printBoard();
	}

	if(v>=9){v=0;h++;}//if the entire column is solved, move onto the next row
	if(v<0){h--;v=8;}//if the entire column failed, go back to the bottom of previous
	if(h<0){cout<<"unsolvable";return;}//if backtracking fails to find any possible solution, break
	if(h==9){cout<<"solved\n";return;}//if the entire puzzle is solved

	if(touchable[v][h]){//if the current square is an editable square (not originally assigned a value)
		nums[v][h]++;//increment the current square up by one
		if(nums[v][h]>=10){/*
			if increment goes past 10, no value of the current square 
			creates a valid board, so set its value to zero 
			and backtrack to the last square 
			*/
			nums[v][h]=0;
			return solve(v-1,h,-1);/*
			set direction value to -1 in case the previous square is non-editable,
		       	so squares will continue being skipped 
			until an editable square is found
			*/
		}
	}
	else return solve(v+direction,h,direction);//if not an editable square, continue the direction the search was
						   //going in before, forward is the last square was a success,
						   //backwards if the previous square was a failure
	if(!checkBoard())solve(v,h,0);//if the board is not valid, rerun the current sqaure, no direction value becasue there is no search happening 
	else return solve(v+1,h,1);//if the board is valid, increment by one square, pass a direction value of 1
				   //so that the loop knows to skip over non-editable square forwards instead of backwards
}

int main(int argc, char* argv[]){
	createTouchable();
	printBoard();
	if(checkBoard())solve(0,0,1);	
	printBoard();
	return 0;
}
//git add.
//git commit
//git push
