#include <stdio.h>
#define MAXEXP 2

int main()
{
	int n=60, b, temp, factor, counter;
		//for(b=1; b<=n; b++){	
				printf("Oi prwtoi paragontes tou %d einai:", n);
				temp=n;
				factor=2;
				while (factor*factor<=temp) {
					while (temp%factor==0){
						printf(" %d", factor);
						counter++;
						temp /= factor;
					}
					if (factor==2){
						factor=3;
					}
					else if (factor==3){
						factor=5;
					}
					else if (factor%6==5) {
						factor+=2;
					}
					else {
						factor+=4;
					}
				}
				if (temp!=1){
					printf(" %d", temp);
					counter++;
				}
				printf("\n");
				printf("To plithos paragontwn tou %d einai %d\n\n", n,counter);	
}
