#include<stdio.h>

int main(){
	
	float num=0;
	int var=0;
      
  	for(num=1;num>=0 && var!=64;num=num+num){
  		
   		var++;
   		
    	printf("%i° Quad. tem %.0f grãos\n",var,num );
    	
  }
  	return 0;
}
