void Reverse(int R[],int n, int p){
    int tmp[p];
    for(int i = 0; i < p; i++){
        tmp[i] = R[i];
    }
    for(int i = p;i<n;i++)
        R[i - p] = R[i];
    for(int i = 0; i < p; i++){
        R[i] = tmp[i];
    }
}