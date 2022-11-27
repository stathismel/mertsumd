#include <stdio.h>
#define MAXEXP 2

int main(){


    int b, j, n, k , r, p, z, temp, factor, previous=0, ZP=1, sum=0;
    int counter=0;                                                    	/*plithos prwtwn paragontwn*/
    int ps=0;                                                        	/*teleio tetragwno - perfect square - an nai tote 1 alliws 0*/
    int mertens=0;                                                    	/*metritis gia M(n)*/
    int mobius=0;

	int y=1000*ZP;
    printf("Checking numbers in the range [2,%d]\n", y);
	
	for(b=2;b<=y;b++){
    	for(j=1;j<=(b/2);j++)
        {
            if (b%j==0){                                             	/*elegxos an to j einai diairetis tou n*/
                sum=sum+j;    
            }
		}
		if(sum==b){
        	printf("Found perfect number: %d\n", b);
        }
		sum=0;   
    }
}
