// Given an image represented by an NxN matrix, where each pixel in the image is 4
// bytes, write a method to rotate the image by 90 degrees. Can you do this in place?

#include<bits/stdc++.h>
using namespace std;

bool rotate(vector<vector<int>> &matrix, int size){
	if(size == 0)
		return false;
	for(int layer = 0; layer < size / 2; layer++){
		int first = layer;
		int last = size - 1 - layer;
		for(int i = first; i < last; i++){
			int offset = i - first;
			// save top
			int top = matrix[first][i];
			// left -> top
			matrix[first][i] = matrix[last - offset][first];
			// bottom -> left
			matrix[last - offset][first] = matrix[last][last - offset];
			// right -> bottom
			matrix[last][last - offset] = matrix[i][last];
			// top -> right
			matrix[i][last] = top;
		}
	}
	return true;
}

int main(){
	int n, ele;
	cout <<"Enter the size of matrix : ";
	cin >>n;
	vector<vector<int>> matrix(n);
	cout <<"Enter the matrix : ";
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >>ele;
			matrix[i].push_back(ele);
		}
	}
	rotate(matrix, n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			cout <<matrix[i][j] <<" ";
		cout <<endl;
	}
	return 0;
}