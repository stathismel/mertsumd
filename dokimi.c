#include <stdio.h>
#define MAXEXP 8

int main(){


    int h, b, j, n, k , r, p, z, temp, factor, previous=0, ZP=0, sum=0, afthonoi=0, elattomatikoi=0, teleioi=0;
    int counter=0;                                                    	/*plithos prwtwn paragontwn*/
    int ps=0;                                                        	/*teleio tetragwno - perfect square - an nai tote 1 alliws 0*/
    int mertens=0;                                                    	/*metritis gia M(n)*/
    int mobius=0;
    
    int ekthetis=MAXEXP;                    
    for (p=1; ekthetis>0; ekthetis--){                                	/*euresi tou 10 eis tin MAXEXP*/
        p*=10;
    }


    for(n=1;n<=(p+9);n++)                                         /*gia kathe n sto [1, (10^MAEXP)+9]*/
    {    
        z=n;
        while(z==n){    
            //printf("Oi prwtoi paragontes tou %d einai:", z);
            temp=z;
            factor=2;
            while (factor*factor<=temp) {
                while (temp%factor==0 && ps!=1){
                    //printf(" %d", factor);
                    if(previous==factor){
                        ps=1;
                    }
                    previous=factor;
                    counter++;
                    temp /= factor;                                    	/*temp=temp/factor*/
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
            if (temp!=1 && ps!=1){
                //printf(" %d", temp);
                counter++;
            }
            //printf("\n");
            //printf("To plithos paragontwn tou %d einai %d\n", z,counter);    
            //printf("To ps tou %d einai %d\n\n", z,ps);
            
            if(ps==1){
                mobius=0;            
            }
            else if(ps==0 && (counter%2)==0){
                mobius=1;
            }
            else {										//isws na mh xreiazetai katholou olokliri h parenthesi - if(ps==0 && (counter%2)!=0)
                mobius=-1;
            }
            z=0;
        }
            
        mertens+=mobius;
        
        if(mertens==0){
            ZP++;
        }
        counter=0;
        previous=0;
        ps=0;    
            
        for(k=1;k<=MAXEXP;k++){
            ekthetis=k;
            for (r=1; ekthetis>0; ekthetis--){
                r*=10;
            }            
            if((r-9)<=n && n<=(r+9)){
                printf("M(%d) = %d\n", n,mertens);
            }    
        }
    }
    
    printf("Found %d zero points of the Mertens function\n", ZP);
    
    int y=1000*ZP;
    printf("Checking numbers in the range [2,%d]\n", y);
    
    for(b=2;b<=y;b++){
    	/*riza=b/2;
    	w=0;
    	while(riza!=w){														//euresi tetragwnikis rizas gia kathe b
    		w=riza;
    		riza=(b/w+w)/2;
    	}*/
    	
    	/*double low=0; 													//riza
    	double high=b+1;
    	while (high-low>1){													//euresi tetragwnikis rizas gia kathe b
			double mid=(low+high)/2;
			if (mid*mid<=b){
				low=mid;	
			}
			else{
        		high=mid;
			}
		}*/
		/*double riza=1;
		int q=0;
    	while (1==1){														//euresi tetragwnikis rizas gia kathe b
			q=q+1;
			riza=(b/riza+riza)/2;
			if(q==b+1) {
				break;
			}
		}*/
		
    	//riza=low;
    	//printf("H riza einai: %d\n", riza);
        /*for(j=1;j<=riza;j++)
        {
            if (b%j==0){                                             		//elegxos an to j einai diairetis tou n
                sum=sum+j;    
            }
		}*/
		
		for (h=1;h*h<=b;h++) {
            if (b%h==0) {
                sum+=h;
                if (h*h!=b) {
                    sum+=b/h;
                }

            }
        }
        sum=sum-b;
		
		if(sum==b){
			teleioi++;
        	printf("Found perfect number: %d\n", b);
        }
        else if(sum<b){
        	elattomatikoi++;
        }
        
        sum=0;
    }
    afthonoi=y-elattomatikoi-teleioi-1;
    printf("Found %d deficient numbers\n", elattomatikoi);
	printf("Found %d abundant numbers\n", afthonoi);              
    return 0;
}  
