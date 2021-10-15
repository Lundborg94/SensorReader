#include <string.h>
#include <stdio.h>
#include <ctype.h>
#define BUFLEN 2020

//unsigned int sensors[20];

void readScanners(){
    FILE *filePointer;
    char sensors[236];
    char buf[BUFLEN];
    filePointer =fopen("sensors.txt", "r");
    fgets(buf, BUFLEN, filePointer);

    for(int i=0; i<BUFLEN, i++)
    {
        if(buf[i] == ";") {
            if(indexIsNumber(buf, i))

    }

    }

}

int main(){
    printf("hello");
    return 0;
}

int isCharNumber(char *buffer, int index) {
    int digits[3] = {0,0,0}; //skapar plats för att kunna skriva ut nummret
    if(index == 1){
        return 1; //TODO: POTENTIAL BUGG
    }
    for(int i = 0; i <= 2; i++) //Loopar igenom index 1-3 för att skriva ut fullständiga nummret
    {
        if(isdigit(buffer[index - 1 - i])) //Om tecknet på positiionen är en siffra 
        {
            digits[i] = buffer[index - i - 1] - '0'; //Så sätts det indexet till den siffran (på något sett)
        }
        else
        {
            break; //om den inte är en siffra avslutas funktionen
        }
    }
    return digits[0] + digits[1] * 10 + digits[2] * 100;    //Slår ihop så att varje 100tal, 10tal och 1tal bildar fullständ siffra.
    
}




/*Sensorövervakning

En helt ny självkörande bil håller på att tas fram. Du kommer med i projektet och får i uppgift att ta
fram en applikation skriven i antingen C eller C++ som skall larma om någon av bilens sensorer
aktiveras.
För att testa din applikation kommer datat att skrivas till en textfil som du behöver läsa in en gång
per sekund.
 -- filewriter.c

    Constructor SensorList
    int index
    int value

    void createList
    Skapa en array/List med 236 boolean (true / false). Ta in Index (1 - 236) och value 0 per slot (for each loop).

    void listchanger
    Loppar igenom listan steg för steg, och vid varje inex kör randomTrigger, som ev. ändrar värdet från 0 - 1.


    Skapa randomizer - vid varje index i listan göra en areWeChanging
    Get random number from 1-5, if 1, change value to 2.
    
    Changer - Random nr generator from 1 -5, if 5, change to true.

-- fileReader.c
Den skall

Läsa in filen
Spara ner datat till heap som orginal
ta in uppdaterad fil
Spara ner datat till heap som uppdated

jämför varje index i orginal mot uppdaterad

if orginal.value != uppdated.value
fprint("triggerd! Sensor " + index + "has triggerd, status now" + status)

    

Du skall övervaka 236 sensorer. Varje sensor kan vara inaktiv (false) eller aktiv (true).
Vid varje inläsning av filen skall du lagra samtliga sensorers värde i minnet. De skall lagras på heapen,
alltså dynamiskt, men du får endast använda maximalt 70 byte av utrymme på heapen vid ett och
samma tillfälle.

Du skall övervaka samtliga sensorer och jämföra dessa med de nya värdena som du läser in från filen
varje sekund. Om en sensor byter värde (från true till false eller tvärtom) skall ditt program slå larm.
Det räcker och du skriver ut ditt larm på skärmen. Larmet skall innehålla vilken sensor som triggat
larmet och till vilket värde den har bytt.

Nedan följer hur datat i textfilen ser ut:
1;false;2;true;3;true;4;false;5;false;6;false;...234;true;235;true;236;false
Siffran anger sensorns nummer och värdet efter siffran anger nuvarande status får denna sensor.

Du skall visa att din implementation uppfyller minneskraven på just din kompilator. Du måste också
se till att din applikation håller sig till tidsgränsen så att din cykel, från det att du börjar läsa in
textfilen till dess att alla larm har skrivits ut på skärmen inte överstiger en sekund.
Du kan testa applikationen genom att skriva ett externt testprogram som skriver en ny fil med sensor
data varje sekund. Gör detta så att endast ett fåtal sensorer byter värde vid varje ny skrivning, alltså
slumpa inte fram nya värden för samtliga sensorer, utan gör så att cirka 10% av sensorerna byter
värde vid varje skrivning, men att vilka sensorer som gör det är helt slumpmässigt.*/

// ReadFile - Läser in från fil och sparar ner värdet på heapen. 

//Compare



