void nhapmt(int a[50][50],int d, int c)
{ 
    printf("\nNhap vao ma tran\n");
    for(int i=0;i<d;i++)
    {
       for(int j=0;j<c;j++)
        {
        	printf("\nNhap phan tu a[%d][%d]= ",i,j);
            scanf("%d ", &a[i][j]);
        }
    }
}