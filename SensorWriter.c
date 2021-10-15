#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
struct bits {
    unsigned int a:1;
    unsigned int b:1;
    unsigned int c:1;
};
struct bits mybits;
void sensorCreator();
void fileWriter();
void sensortrigger();
void fileWriter2();
unsigned char sensors[30];

int main(){
srand(time(0));
sensorCreator();
int x = 1;
while(x=1){
    fileWriter();
    sensortrigger();
    Sleep(1000);
}
return 0;
}

void sensorCreator(){
srand(time(0));
    for(int i = 0; i < sizeof(sensors); i++){
        sensors[i] = rand()%(255+1-0)+0;
        printf("%d", sensors[i]);
    }
    printf("\n");
}

void fileWriter(){
    FILE *fp;
    fp = fopen("sensorz.txt", "w");
    for(int i = 0; i < 30; i++){
        fputc(sensors[i], fp);  
    }  
    fclose(fp); 
};

void sensortrigger(){
    unsigned char newValue = 0;
    unsigned char prevValue = 0;
    for (int i = 0; i < 10; i++){
        int shift = rand()%(29+1-0)+0;
        prevValue = sensors[shift];
        newValue = prevValue ^=rand()%(255+1-1)+1;
        sensors[shift] = newValue;
    }
    for(int i = 0; i < sizeof(sensors); i++){
        printf("%d", sensors[i]);
    }
    printf("\n");
}

/*void createSensorValues(){
    srand(time(0));
    for(int i = 0; i < 236; i++){
        sensors[i] = rand()%(1-0+1)+0;
        printf("%d", sensors[i]);


            double time_spent = 0.0;
    clock_t begin = clock();

    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time elapsed: %f ", time_spent);
    }*/
