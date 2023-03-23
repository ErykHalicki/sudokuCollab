#include <iostream>
#include <vector>

//int argc ==
//char argv[] ==
using namespace std;

int main(int argc, char* argv[]){

	vector<vector<int> > nums {{0,0,0,0,0,0,0,0,0},
				   {0,0,0,0,0,0,0,0,0},
				   {0,0,0,0,0,0,0,0,0},
				   {0,0,0,0,0,0,0,0,0},
				   {0,0,0,0,0,0,0,0,0},
				   {0,0,0,0,0,0,0,0,0},
				   {0,0,0,0,0,0,0,0,0},
				   {0,0,0,0,0,0,0,0,0},
				   {0,0,0,0,0,0,0,0,0}};
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
}
