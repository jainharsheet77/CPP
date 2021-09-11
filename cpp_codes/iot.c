#include <stdio.h>

struct sensor
{
    char name[100];
    char type[2][100];
};



int main() 
{
    struct sensor sensors[4];

    enum name{"BME280","SHT3x","DHT11","DHT22"};
    strcpy(sensors[0].name,"BME280");
    strcpy(sensors[1].name,"SHT3x");
    strcpy(sensors[2].name,"DHT11");
    strcpy(sensors[3].name,"DHT22");

    srcpy(sensors[0].type[0],"Temperature sensors");
    srcpy(sensors[0].type[1],"Humidity");

    srcpy(sensors[1].type[0],"Temperature sensors");

    srcpy(sensors[2].type[0],"Temperature sensors");
    srcpy(sensors[2].type[1],"Humidity");
    
    srcpy(sensors[3].type[0],"Temperature sensors");

    char input[];
    gets(input);
    for(int i=0;i<2;i++)
    {
        if(sensors[input].type[i]!=NULL)
        printf("%s",sensors[input].type[i]);
    }



	
	
}
