// Esteban Munoz Serrrao  
#include <stdio.h>

int reverse(int num){
    
    int reverseNum = 0;
    while (num>0)
    {
        reverseNum *= 10;
        reverseNum += num%10;
        num /= 10;


    }
    return reverseNum;
}

int isPalindromo(int num, int reverseNum){
    int isPal = 0;
    if (num == reverseNum)
    {
        isPal = 1;
    }
    return isPal;
}

void palindromo(int num,int reverseNum){
    int flag = 0, isPal = 0;
    int cont = 0;
    while (flag == 0){
            
        reverseNum = reverse(num);
        isPal = isPalindromo(num,reverseNum);
        if (isPal == 0){
            num += reverseNum;
            cont++;
        }else
        {
            flag = 1;
                
        }
    }
    printf("%d %d\n",cont,num);
}
int main(){
    
    int num,aux,i; 
    int reverseNum;
    int flag = 0, isPal = 0;
    int cont = 0;
    scanf("%d",&aux);
    for (i = 0; i < aux; ++i)
    {
        scanf("%d",&num);
        reverseNum = reverse(num);
        palindromo(num,reverseNum);
        
    }
}

