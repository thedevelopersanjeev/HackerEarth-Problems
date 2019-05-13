// Write an algorithm such that if an element in an MxN matrix is 0, its entire row and
// column are set to 0.

#include<bits/stdc++.h>
using namespace std;

int main(){
	// take input
	int m, n;
	cout <<"Enter m : ";
	cin >>m;
	cout <<"Enter n : ";
	cin >>n;
	int matrix[m][n];
	cout <<"Enter matrix";
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++)
			cin >>matrix[i][j];
	}
	// algorithm starts from here
	bool rowHasZero = false;
	bool columnHasZero = false;
	// check if first row has a zero
	for(int j = 0; j < n; j++){
		if(matrix[0][j] == 0){
			rowHasZero = true;
			break;
		}
	}
	// check if first column has a zero
	for(int i = 0; i < m; i++){
		if(matrix[i][0] == 0){
			columnHasZero = true;
			break;
		}
	}
	// check for zeros in remaining array
	for(int i = 1; i < m; i++){
		for(int j = 1; j < n; j++){
			if(matrix[i][j] == 0){
				matrix[i][0] = 0;
				matrix [0][j] = 0;
			}
		}
	}
	// nullify rows
	for(int i = 1; i < m; i++){
		if(matrix[i][0] == 0){
			for(int j = 0; j < n; j++)
				matrix[i][j] = 0;
		}
	}
	// nullify columns
	for(int j = 1; j < n; j++){
		if(matrix[0][j] == 0){
			for(int i = 0; i < m; i++)
				matrix[i][j] = 0;
		}
	}
	// nullify first row
	if(rowHasZero){
		for(int j = 0; j < n; j++)
			matrix[0][j] = 0;
	}
	// nullify first column
	if(columnHasZero){
		for(int i = 0; i < m; i++)
			matrix[i][0] = 0;
	}
	return 0;
}