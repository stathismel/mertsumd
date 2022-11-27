#include <stdio.h>
#define MAXEXP 2

int main()
{
	
	int n, j, k, a, b, p, r, ekthetis, temp, factor, mobius;
	int ps=0; /*teleio tetragwno*/
	int counter=0;
	int mertens=0;

	ekthetis=MAXEXP;
    for (p=1; ekthetis>0; ekthetis--){
    	p*=10;
	}


	for(n=1;n<=(p+9);n++)
	{
    	for(j=2;j<=(n/2) && ps==0;j++)
    	{
			//ps=0;
    		if (n%j==0) /*elegxos an to j einai diairetis tou n*/
    		{
    
    			for(a=2;a<=j;a++) /*elegxos an to j einai teleio tetragwno*/
				{
					if (a*a==j)
					{
						a=j+1;
						ps=1;
					}
				}
			}	
		}
		for(a=1;a<=n && n!=1;a++) /*elegxos an to n einai teleio tetragwno*/
        {
			if (a*a==n)
			{	
				a=n+1;
				ps=1;
        	}
		}
		
		if(ps==1) /*an to n exei diaireti teleio tetragwno*/
    	{
    		mertens=0;
		}
    	else /*an o n den exei diaireti teleio tetragwno*/
    	{
			//for(b=1; b<=n; b++){	
				//printf("Oi prwtoi paragontes tou %d einai:", b);
				temp=n;
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
				if (counter%2==0 || n==1)
				{
					mertens+=1;
				}
				else
				{
					mertens+=-1;
				}

				counter=0;
			//}		
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

		//mertens=0;			
	}
	return 0;			
}
