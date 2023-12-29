#include <iostream>
using namespace std;
int arr[] = {1,3,5,7,9,11,13,17,19,21};
int binSearch(int R[], int n,int target){
	int s = 0 , e = n -1, mid;//定义并初始化数组开始和结束位置，定义中间位置
	while(e>=s){
		mid = (s+e)/2; 
		if(target < R[mid])
			e = mid - 1;
		else if(target > R[mid])
			s = mid + 1;
		else
			return mid;//相等返回
		}
	return -1; //查找失败
}




