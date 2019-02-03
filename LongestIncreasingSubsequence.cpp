#include <iostream>
using namespace std;

// Find longest increasing subsequence in O(N^2)
int LIS(int A[], int size){
	int i, j;
	int *M = new int[size];
	
	for(i=0;i<size;i++)
		M[i] = 1;
		
	for(i=1;i<size;i++)	
		for(j=0;j<=i;j++)
			if(A[i] > A[j]){				
				M[i] = (M[j] + 1 > M[i])? M[j] + 1 : M[i];
			}

	int max = 0;
	for(i=0;i<size;i++)
		max = (M[i] > max) ? M[i] : max;
		
	delete M;
	return max;	
}

int main(){
	
	int A[] = {1, 2, 3, 8, 5, 6, 1};
	int size = 7;
	cout << LIS(A, size);
	return 0;
}
