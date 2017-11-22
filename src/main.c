/* primesort
 * rafael 147704
 */

#include <stdio.h>
#include <sys/time.h>

int main() {

	int x, n_divisores_x=0, j=0;
	
	FILE *loucura; //pipe louco criado

	loucura = popen("sort -n -r","w"); 

	while (1){
		inicio:
		scanf("%d\n", &x);

		if (x==-1) break;
		
		if ((x==0) || (x==1) || (x!=2 && x%2==0)){ // teste para excluir os números
					       //0, 1 e pares (sem incluir o 2)	
			fprintf(loucura, "%d\n", x);
		}

		else {   
			n_divisores_x = 0;
 
			for (j=2; j<=x; j++){	

				if (x%j==0)
				{
					n_divisores_x+=1;
				
					if (n_divisores_x>1){					
						fprintf(loucura, "%d\n", x);	
						goto inicio;						
					}		
				}

		    	}

		}		
	
	}	

	pclose(loucura); 
	 
  return 0;
}
