int M_Seach(int M[],int m,int N[],int n){
    int mid_index = (m + n + 1) / 2; //need for foreach
    int p1 = 0, p2 =0;
    for(int i = 0;i<mid_index;i++){
        if(p1 == m-1)   p2 ++;
        else if(p2 == n-1)  p1++;
        else if(M[p1] > N[p2])  p2++;
        else p1++;     
    }
    return M[p1] ? N[p2] : M[p1] > N[p2]; //return the last ,is the bigger
}