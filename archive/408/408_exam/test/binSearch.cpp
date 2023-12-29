#include <iostream>
using namespace std;
int R[] = {1,3,5,6,7,13,16,25,17};
int n = 9;
int binSearch(int R[],int n,int aim){
	int left = 0,right = n, mid, index = -1;
	while(right>left){
		mid = (left + right) / 2;
		if(R[mid]>aim)
			right = mid -1;
		else if(R[mid]<aim)
			left = mid + 1;
		else{
			index = mid;
			break;
		}
	}
	return index;
}
int main(){
	int aim; 
	cin >> aim;
	int w = binSearch(R,n,aim);
	cout << w << endl;
	return 0;
}
				

