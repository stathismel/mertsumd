#include <stdio.h>
#define MAXEXP 3

int main(){


    int n, k , r, p, z, temp, factor, previous=0;
    int counter=0;                                                    /*plithos prwtwn paragontwn*/
    int ps=0;                                                        /*teleio tetragwno - perfect square - an nai tote 1 alliws 0*/
    int mertens=0;                                                    /*metritis gia M(n)*/
    int mobius=0;
    
    int ekthetis=MAXEXP;                    
    for (p=1; ekthetis>0; ekthetis--){                                /*euresi tou 10 eis tin MAXEXP*/
        p*=10;
    }


    for(n=1;n<=(p+9);n++)                                            /*gia kathe n sto [1, (10^MAEXP)+9]*/
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
                    temp /= factor;                    /*temp=temp/factor*/
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
            else if(ps==0 && (counter%2)!=0){
                mobius=-1;
            }
            z=0;
        }
            
        mertens+=mobius;

        counter=0;
        previous=0;
        ps=0;    
            
        for(k=1;k<=MAXEXP;k++){
            ekthetis=k;
            for (r=1; ekthetis>0; ekthetis--){
                r*=10;
            }            
            if((r-9)<=n && n<=(r+9)){
                printf("To M(%d) einai %d\n", n,mertens);
            }    
        }
    }                
    return 0;
} 
