#include <stdio.h>

//Swap Function
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

//struct with char,int,char     &       int,char[with sise 1,2,3,4,5],int
struct s1 {

    char a;
    int b;
    char c;

};

struct s2 {

    int a;
    char b[1];
    char c[2];
    char d[3];
    char e[4];
    char f[5];
    int g;

};

int main() {
    //int i;
    struct s1 ST1;
    struct s2 ST2;
    char i;

    printf("Address of Structure 1: %u\n", &ST1);
    printf("Address of Structure 2: %u\n", &ST2);

    printf("Size of Structure 1: %d\n", sizeof(ST1));
    printf("Size of Structure 2: %d\n", sizeof(ST2));
}
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
/*int main()
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
*/

