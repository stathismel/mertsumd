#include <stdio.h>
#define MAXEXP 2

int main()
{
	
	int n, j, k, a, b, p, r, ekthetis, temp, factor, y, z, next, mobius;
	int ps=0; /*teleio tetragwno*/
	int counter=0;
	int mertens=0;

	ekthetis=MAXEXP;
    for (p=1; ekthetis>0; ekthetis--){
    	p*=10;
	}


	for(n=1;n<=(p+9);n++)
	{
		if(n%4==0 || n%9==0){
			continue;
		}
		y=n;
		if(y%2==0){
			y/=2;
		}
		if(y%3==0){
			y/=3;
		}
		z=5;
		next=0;
		
		while(z*z<=y){
			if(y%z==0){
				y/=z;
				if(y%z==0){
					next=1;
					break;			
				}
			}
			if(z%6==5){
				z+=2;	
			}
			else{
				z+=4;	
			}
		}
		if(next!=0 || n==1){
			ps=1;
		}
		
		if(ps==1) /*an o n exei diaireti teleio tetragwno*/
    	{
    		mertens+=0;
		}
    	else /*an o n den exei diaireti teleio tetragwno*/
    	{
			for(b=1; b<=n; b++){	
				//printf("Prwtoi paragontes %d einai:", b);
				temp=b;
				factor=2;
				while (factor*factor<=temp) {
					while (temp%factor==0){
						//printf(" %d", factor);
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
					//printf(" %d", temp);
					counter++;
				}
				//printf("\n");
				//printf("To plithos paragontwn tou %d einai %d\n\n", b,counter);
				if (counter%2==0)
				{
					mertens+=1;
				}
				else
				{
					mertens+=-1;
				}

				counter=0;
			}		
    	}
    	ps=0;
    	//mertens+=mobius;
    		
    		
    	for(k=1;k<=MAXEXP;k++){
    		ekthetis=k;
		    for (r=1; ekthetis>0; ekthetis--){
    			r*=10;
			}    		
			if((r-9)<=n && n<=(r+9)){
				printf("M(%d)=%d\n", n,mertens);
			}	
		}

		mertens=0;			
	}
	return 0;			
}
