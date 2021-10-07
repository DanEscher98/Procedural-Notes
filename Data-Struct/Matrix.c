#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "chario.h"


int main(void){
  int user=1;
  while(user==1){
    HI();

    //code
    printf("\nRepeat program?1/0: ");
    scanf("%d", &user);
  }
  printf("Goodbye.");
  return 0;
}

int detM(int*M){
  int n=sizeof(M)/sizeof(M[0]);
  int k, i, j, ef, ec, user, div=1;
  int*piv, *elm;
  for(k=0; k<n; k++){ //Iteracion de diagonal
    piv = M+k*n+k; if(div==0) break;
    for(i=0; i<n-k-1; i++){
      for(j=0; j<n-k-1; j++){
        elm = (piv+n+1)+(i*n+j);
        ef= piv[div+j+1]; 
        ec= piv[n*(i+1)];
        putM(M,n,n);
        printf("\n(%d*%d - %d*%d)/%d =", *piv, *elm,ef,ec,div);
        *elm = ((*piv)*(*elm) - (ef)*(ec))/div;
        printf(" %d  ", *elm); scanf("%d",&user);
      }
    }
    div = *piv;
    for(i=0;i<n-k;i++){
      piv[i]=0;
      piv[i*n]=0;
    }
    scanf("%d",&user);
  }
  return *(M+n*n-1);
}
