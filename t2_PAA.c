//NOME: JOÃO VITOR FIDELIS CARDOZO RA: 769719


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//CONTA O NUMERO DE INVERSOES E INTERCALA O VETOR
int conta_e_intercala (int A[], int p, int q, int r) 
{
    int i = p, k=0, j=q, tam = r-p, inversoes = 0;        
    int *B = (int*) malloc (tam * sizeof (int));      
                                 
    while (i<q && j<r){  
        if (A[i]<=A[j]) {
            B[k++] = A[i++]; 
        }      
        else {
            B[k++] = A[j++]; 
            inversoes = inversoes + (q -i) + 2;
        }             
    }   
    while (i<q) B[k++] = A[i++]; 
    while (j<r) B[k++] = A[j++];  
    for (i=p; i<r; i++) A[i] = B[i - p]; 
    
    free (B);   
    return inversoes;               
}

//CONTA O NUMERO DE INVERSOES E ORDENA O VETOR
int conta_e_ordena (int A[], int p, int r)
{
    int q = 0;
    int inversoes = 0;

    if (p>=r-1){
        return 0;
    }
    else{
        q = (p + r) / 2;          
        inversoes += conta_e_ordena (A, p, q);        
        inversoes += conta_e_ordena (A, q, r);        
        inversoes += conta_e_intercala (A, p, q, r);     
        return inversoes;
    }
}

int main (){
    FILE *arquivo;
    int tamanho = 1, i=0;
    char nome_arquivo[15];
    scanf("%s", nome_arquivo);
    arquivo = fopen(nome_arquivo, "r");
    int *vetor = NULL;
    int trocas_atuais = 0;

    
    while (tamanho != 0){
        fscanf(arquivo, "%d", &tamanho);
        vetor = (int*) malloc(tamanho * sizeof(int));
        for (i=0; i<tamanho; i++){
            fscanf(arquivo, "%d", &vetor[i]);
        }
        trocas_atuais = conta_e_ordena(vetor, 0, tamanho);
        if (tamanho !=0){
            if (trocas_atuais % 2 == 0){ //SE RESTO DA DIVISAO POR 2 == 0, IMPLICA QUE FINN FEZ A TROCA
                printf("Finn\n");
            }
            else{
                printf("Jake\n"); //SE RESTO DA DIVISAO POR 2 !=0, IMPLICA QUE JAKE FEZ A TROCA
            }
        }
    }    

    free(vetor);
    fclose(arquivo);
    return 0;
    
}
