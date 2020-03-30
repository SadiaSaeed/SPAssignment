#include <stdio.h>
//1D Array using new()
/*int main()
{
int i ;
int c = 0 ;
int total_elements=5;

int *p = new int[total_elements];

for (i = 0; i<total_elements; i++)
p[i] = ++c;

for (i = 0; i < total_elements; i++)
printf("%d", p[i]);

return 0;
}
*/

//2D array Using new keyword
int main()
{
    int i, j, c=0;
    int r=3;
    int col=3;
    int** p = new int*[r];
    for(int i = 0; i < r; ++i)
        p[i] = new int[col];
 

 
    for (i = 0; i < r; i++){
        for (j = 0; j < col; j++){
	        p[i][j] = ++c;
            printf("%d ", p[i][j]);
            //printf("%d", p[i][j]);	
    	}
        printf("\n");
    }
 
    return 0;
}
