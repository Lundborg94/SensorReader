#include<stdio.h>
#include<



void loopTrough();



void printRandoms(int lower, int upper, 
                             int count)
{
    int i;
    for (i = 0; i < count; i++) {
        int num = (rand() %
           (upper - lower + 1)) + lower;
        printf("%d ", num);
    }
}
  
// Driver code
int main()
{
    int lower = 1, upper = 5, count = 1;
  
    // Use current time as 
    // seed for random generator
    srand(time(0));
  
    printRandoms(lower, upper, count);
  
    return 0;
}


/*int radomizer = 0;


int main(){
	FILE *out=fopen("name_of_file.txt","w");
	fputs("Hello File",out);
	fclose(out);
	return 0;
}*/