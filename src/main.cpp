#include <iostream>
#include <vector>

//int argc ==
//char argv[] ==
using namespace std;
int main(int argc, char* argv[]){

	vector<vector<int> > nums {{1,2,3},{4,5,6},{7,8,9}};

	for (int i = 0; i < nums.size(); i++) {
		for (int j = 0; j < nums[i].size();j++){
			cout << nums[i][j] << " ";
		}
	cout<<endl;
	}
}
