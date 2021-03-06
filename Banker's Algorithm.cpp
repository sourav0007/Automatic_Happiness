          /* sourav verma IPG_2013108
                  ABV-IIITM,Gwalior */
                  
                  

#include <bits/stdc++.h>
using namespace std;

int main() {
	int Max[10][10],Need[10][10],Alloc[10][10],Avail[10],SafeSequence[10];
	bool Finish[10];
	int p,r,i,j,process,count=0;
	
	printf("Enter the no of processes : "); 
	scanf("%d",&p);
	
	for(i=0;i<p;i++)  Finish[i]=false;
	
	printf("\n\nEnter the no of resources : "); 
	scanf("%d",&r);
	
	printf("\n\nEnter the allocation for each process : ");
    for(i=0;i<p;i++){
    	printf("\nFor process %d : ",i + 1);
    	for(j=0;j<r;j++)
           scanf("%d",&Alloc[i][j]);  
    }
    
	printf("\n\nEnter the Max Matrix for each process : ");
	for(i=0;i<p;i++){
		printf("\nFor process %d : ", i+1);
		for(j=0;j<r;j++)
		    scanf("%d",&Max[i][j]);
    }
    
    printf("\n\nEnter the Available Resources : ");
    for(i=0;i<r;i++)
        scanf("%d",&Avail[i]); 
 
    for(i=0;i<p;i++){
        for(j=0;j<r;j++)
            Need[i][j]=Max[i][j]-Alloc[i][j];
    }
    
    do{
    	printf("\n Max matrix:\tAllocation matrix:\n");
    	for(i=0;i<p;i++){
    		for(j=0;j<r;j++)
    		    printf("%d  ",Max[i][j]);
            printf("\t\t");
            for(j=0;j<r;j++)
                printf("%d  ",Alloc[i][j]);
            printf("\n");
        }
        process=-1;
        for(i=0;i<p;i++){
        	if(Finish[i]==false){
        		process=i ;
        		for(j=0;j<r;j++){
        			if(Avail[j]<Need[i][j]){
        				process=-1;
                        break;
                    }
                }
            }
            if(process!=-1)
               break;
        }
        
        if(process!=-1){
        	printf("\nProcess %d runs to completion!", process+1);
        	SafeSequence[count]=process+1;
        	count++;
        	for(j=0;j<r;j++){
        		Avail[j]+=Alloc[process][j];
        		Alloc[process][j]=0;
        		Max[process][j]=0;
        		Finish[process]=true;
            }
        }
    
    }while(count!=p && process!=-1);
    
    if(count==p){
    	printf("\nThe system is in a safe state!!\n");
    	printf("Safe Sequence : < ");
    	for( i = 0; i < p; i++)
            printf("%d  ",SafeSequence[i]);
        printf(">\n");
    }
    else
        printf("\nThe system is in an unsafe state!!");
        
	// your code goes here
	return 0;
}


