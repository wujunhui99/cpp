int binSearch(int A[],int n, int key){
    int low = 0, mid = n / 2, high = n - 1;
    while(low <= high){
        if(A[mid]== key)
            return mid;
        else if(A[mid] < key)      
            high = mid - 1;
        else    
            low = mid + 1;   
    }
    return -1;
}