/******************************************************************************
!!!!! The code is shit but works. Not tested for corner cases!!!!!!
todo: cleanup and improve.  
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdint.h>
void* alligned_malloc(int almt, int bytz){
    
    void* temp_i = malloc(bytz+almt+4);
    
    printf("temp addr = %ld, reminder = %ld\n", (long int)temp_i, (long int )temp_i%almt);
    void* temp=temp_i + (almt-((long int)temp_i%(long int)almt));
    
    *(uint8_t*) (temp-1) = (temp-temp_i);
    printf("diff = %d\n", *(uint8_t*)(temp-1));
    
	//returns pointer to aligned memory -> temp
	//A byte before temp contains the difference between initial malloc pointer and the shifted pointer. 
	//It can be accessed using *(uint8_t*)(temp-1). Since its only a byte it can store upto 255. So alignment only possible till 255.
    return temp;	
	
}

void free_mal(void * ptrf){
    void* free_add;
    
    printf("\n\nreceived add = %ld\n",(long int)ptrf );
    void* temp = free_add - ( *(uint8_t*)(free_add-1));
    printf("address to be freed = %ld", (long int)temp);
    free(temp);
}

int main()
{
    printf("Align malloc to 15 bytes\n");
    
    
    void *a =  alligned_malloc(15, 100); // -> first arguement - alignment bytes, second arguement - total memory to be aligned
    
    printf("Address = %ld\n", (long int)a);
    
    free_mal(a);
    

    return 0;
}