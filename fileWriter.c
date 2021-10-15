#include <string.h>
#include <stdio.h>
#include <ctype.h>
#define BUFLEN 2020

char t[] = "true";
char f[] = "false";
void readFile();
void judgeFile();
int isCharNumber(char *buffer, int index);
unsigned int Sensors[20];
   
void main(){
    //printf(t);
    //printf(f);
    judgeFile();
    return 0;
}

void readAndPrintFile(){
    FILE *fp;
    char sensors[236];
    char buf[BUFLEN];
    fp = fopen("sensors.txt", "r");
    char c = fgetc(fp);

    while(c != EOF){
        if (isdigit(c)){
            printf("sensor nr.");
            while (isdigit(c)){
                printf("%c", c);
                c = fgetc(fp);
            }    
        }
        if(isalpha(c)){
            printf("is:");
            while(isalpha(c)){
                printf("%c", c);
                c = fgetc(fp);    
            }
            if (c == ';'){
                printf("%c\n", c);       
                c = fgetc(fp);
            }
        }
    if (c == ';'){
    printf("%c", c);       
    c = fgetc(fp);        
    }
    }   
    fclose(fp);
};

 void judgeFile(){
    FILE *fp;
    char buf[BUFLEN];
    char sensorNr[236];
    fp = fopen("sensors.txt", "r");
    char c = fgetc(fp);

    while(c != EOF){

        int sensorNr[] = {0,0,0};
        int sensorValue = 0;
        int i;
        printf("%c", c);
        if (isdigit(c)){
            sensorNr[2] = c;
            c = fgetc(fp);
            if (isdigit(c)){
                sensorNr[1] = sensorNr[2];
                sensorNr[2] = c;
                c = fgetc(fp);
                if (isdigit(c)){
                    sensorNr[0] = sensorNr[1];
                    sensorNr[1] = sensorNr[2];
                    sensorNr[2] = c; 
                    for(i = 0; i <=2; i++){
                        printf("%d",sensorNr[i]);
                    }
        
                }
                for(i = 0; i <=2; i++){
                    printf("%d",sensorNr[i]);
                }
            }
            for(i = 0; i <=2; i++){
                printf("%d",sensorNr[i]);
            }
        }
        fgetc(fp);
    }fclose(fp);
 };

            /*printf("sensor nr.");
            while (isdigit(c)){
                
                
                //printf("%c", c);
                c = fgetc(fp);
            }    
        }
        if(isalpha(c)){
            printf("is:");
            while(isalpha(c)){
                printf("%c", c);
                c = fgetc(fp);    
            }
            if (c == ';'){
                printf("%c\n", c);       
                c = fgetc(fp);
            }
        }
    if (c == ';'){
    printf("%c", c);       
    c = fgetc(fp);        
    }
    }   
    fclose(fp);
}
}
}
 };*/