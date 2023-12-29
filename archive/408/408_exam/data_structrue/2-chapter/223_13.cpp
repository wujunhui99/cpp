int FindMissNum(int A[],int n){
    int *B = new int[n]; //
    for(int i = 0;i<n;i++) B[i] = 0; //turn 0
    for(int i = 0;i<n;i++)
        if(A[i]>0 && A[i]<=n)
            B[A[i]-1] = 1;
    for(int i = 0;i<n;i++)
        if(B[i] == 0)
            return i+1;
    return n+1;
}
