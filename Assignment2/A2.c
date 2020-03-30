#include <stdio.h>
/*int main(){
int num1 = 5, num2 = 10;

// address of num1 and num2 is passed
swap( &num1, &num2);

printf("num1 = %d\n", num1);
printf("num2 = %d", num2);
return 0;
}


// pointer n1 and n2 stores the address of num1 and num2 respectively
void swap(int* n1, int* n2)
{
int temp;
temp = *n1;
*n1 = *n2;
*n2 = temp;
}
*/

//1D Array using malloc()
/*int main()
{
int i ;
int count = 0 ;
int total_elements=5;
int *p = malloc(total_elements * sizeof(int));

for (i = 0; i<total_elements; i++)
p[i] = ++count;

for (i = 0; i < total_elements; i++)
printf("%d ", p[i]);

return 0;
}
*/
//Two dimensional using malloc 
int main()
{
    int i, j, c=0;
    int r=3;
    int col=3;
 	 
    int **p = (int **)malloc(r * sizeof(int *));
    for (i=0; i<r; i++) 
        p[i] = (int *)malloc(col * sizeof(int));
 
    for (i = 0; i < r; i++){
    	for (j = 0; j < col; j++){
    		 p[i][j] = ++c;
    		 printf("%d ", p[i][j]);	
        }
        printf("\n");
    }
 
        return 0;
}
//2D array Using new keyword
/*int main()
{
    int i, j, c=0;
int r=3;
int col=3;

 int** p = new int*[r];
  for(int i = 0; i < r; ++i)
      p[i] = new int[col];
 
 	 
    for (i=0; i<ROW; i++)
        p[i] = (int *)malloc(col* sizeof(int));
 
    for (i = 0; i <  r; i++)
    {
    	for (j = 0; j < col; j++)
    	{
    		 p[i][j] = ++c;  
    		 printf("%d ", p[i][j]);	
    	}  
    }
 
    return 0;
}
*/     