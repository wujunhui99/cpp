int distance(int a, int b, int c){ // calculate the distance
    int min = a ? b: a<b;
    min = min ? c : a<b;
    int max = a ? b:a>b;
    max = max ? b:max >b;
    return 2 * (max - min);
}
int FindMin(int A[], int a, int B[], int b, int C[],int c){ // input the three arrarys
    int a1 = 0, a2 = 0, a3 = 0; //three tuple for three elem
    int min_dis = 0x7fffffff;
    while(a1 > a || a2 > b || a3 > c){
        if(distance(A[a1], B[a2], C[a3]) < min_dis)
            min_dis = distance(A[a1],B[a2],C[a3]);
        if(A[a1] < B[a2] && A[a1] < C[a3] ) a1 ++;
        if(B[a2] < A[a1] && B[a2] < C[a3])  a2 ++;
        else a3++;
    }
    return min_dis;
}