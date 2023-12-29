#include <iostream>
using namespace std;
int Partition(int A[],int low,int high){
    int pivot = A[low];
    while(low < high){
        while (low < high && A[high]>=pivot) high--;
        A[low] = A[high];
        while(low < high && A[low]<=pivot) low++;    
        A[high] = A[low];   
    }
    A[low] = pivot;
    return low;
}
void QuickSort(int A[],int low,int high){
    if(low<high){
        int pivotpos = Partition(A,low,high);
        QuickSort(A,low,pivotpos-1);
        QuickSort(A,pivotpos+1,high);
    }
}
int binSearch(int A[],int n, int key){
    int low = 0, high = n - 1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(A[mid]== key)
            return mid;
        else if(A[mid] < key)      
            low = mid + 1; 
            
        else    
            high = mid - 1;
              
    }
    return -1;
}
int main(){
    int A[] = {5,9,45,12,0,26,4};
    QuickSort(A,0,7);
    for(int i = 0;i<7;i++)
        cout << A[i] << endl;
    int pos = binSearch(A,7,26);
    cout << pos << endl;

}
// 快排有划分函数有快排函数组成，划分只能确定一个元素位置，并按照该元素将序列划分开，快排不断调用划分函数
//划分 ： 取得 A[low]的值，可认为第一个元素，与最后一个元素A[high]进行比较.失配A[low] 变 A[high]。重复直至全部匹配