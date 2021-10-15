#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)  \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0')

struct bits {
    unsigned int a:1;
    unsigned int b:1;
    unsigned int c:1;
};
struct bits mybits;

void readFile();
void overWrite();
void stream();
void compareFiles();
unsigned char *newData;
unsigned char *oldData;

int main(){
    oldData = malloc(30);
    stream();
    return 0;
}
void stream(){
    int x = 1;
    while(x=1){
        readFile();
        compareFiles();
        overWrite();
        Sleep(1000);
    }
}
void readFile(){
    newData = malloc(30);
    FILE *fp;
    fp = fopen("sensorz.txt", "r");
    for (int i = 0; i < 30; i++){
        newData[i] = (fgetc(fp));
        printf("%d", newData[i]);
    }
    fclose(fp);
    printf("file scan complete.\n");
};
void compareFiles(){
    int nrOfTriggers =0;
    for (int i = 0; i <= 29; i++){
        int roundCounter = i;
        int n = newData[i];
        int o = oldData[i];
        int shift = 7;
        int mask = 1;    
        for (int y = 0; y < 8; y++){
            int bitCounter = y+1;
            int sensornr = roundCounter*8+bitCounter;
            if (sensornr == 237){
                printf("Trigger check complete, total number of triggers = %d\n", nrOfTriggers);
                return;}
            int n = newData[i];
            int o = oldData[i]; 
            n >>=shift;
            n &=mask;
            o >>=shift;
            o &=mask;
            mybits.a = n;
            mybits.b = o;
            if(mybits.a !=mybits.b){
                nrOfTriggers++;
                printf("sensor nr %d triggerd!, status is now %d \n", sensornr, mybits.a );}
            else{printf("%d = %d/%d\n",sensornr ,mybits.a,mybits.b);}
            shift = shift-1;
        } 
    }       
};
void overWrite(){
    for (int i = 0; i < 30; i++){
        oldData[i] = newData[i];
        printf("%d", oldData[i]);
    };
    printf("\noverwrite complete.\n");
    free(newData);
};       
                

        //printf(BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(newData[1])); //vi lyckas skriva ut det första värdet i new data.
        //printf("\n");

                    //printf("newData: ");
            //printf(BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(newData[i]));
            //printf("\n");
            //printf("oldData: ");
            //printf(BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(oldData[i]));
            //printf("\n");