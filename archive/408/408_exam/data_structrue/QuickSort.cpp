#include <iostream>
using namespace std;
int Partition(int A[],int low, int high){
	int  pivot = A[low];
	while(low<high){
		while(low<high&&A[high]>=piovt) -- high;
		A[low] = A [high];
		while(low<high&&A[low]<=piovt) ++ low;
		A[high]=A[low];
	}
	A[low]=piovt;
	return low;
}
void QuickSort(int A[],int low,int high){
	int pivotpos = Partition(A,low,pivotops-1);
	QuickSort(A,low,pivotpos-1);
	QuickSort(A,pivotpos+1,high);
}


