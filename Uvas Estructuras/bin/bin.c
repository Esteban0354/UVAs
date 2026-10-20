#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Esteban Munoz Serrano - 8966406 

int main()
{
    int arr[]={0,0,0,0,0,0,0,0,0};
    int i;
    
    while (scanf("%d",&arr[0])!=EOF)
    {
        for (i = 1;i < 9 ; i++){
            scanf("%d",&arr[i]);
        }    
            
            
        int bin[3];
        int brown[3] = {arr[0],arr[3],arr[6]};
        int green[3] = {arr[1],arr[4],arr[7]};
        int clear[3] = {arr[2],arr[5],arr[8]};
            
        bin[0] = clear[1]+clear[2];
        bin[1] = brown[0]+brown[2];
        bin[2] = green[0]+green[1];
        int cbg = 0;
        for (i = 0; i < 3; i++){
            cbg += bin[i];
                
        }
            
        bin[0] = clear[1]+clear[2];
        bin[1] = green[0]+green[2];
        bin[2] = brown[0]+brown[1];
        int cgb = 0;
        for (i = 0; i < 3; i++){
            cgb += bin[i];
        }
            
        bin[0] = green[1]+green[2];
        bin[1] = clear[0]+clear[2];
        bin[2] = brown[0]+brown[1];
        int gcb = 0;
        for (i = 0; i < 3; i++){
            gcb += bin[i];
        }
            
        bin[0] = green[1]+green[2];
        bin[2] = brown[0]+brown[2];
        bin[1] = clear[0]+clear[1];
            
        int gbc = 0;
        for (i = 0; i < 3; i++){
            gbc += bin[i];
        }
            
        bin[0] = brown[1]+brown[2];
        bin[1] = green[0]+green[2];
        bin[2] = clear[0]+clear[1];
        int bgc = 0;
        for (i = 0; i < 3; i++){
            bgc += bin[i];
        }
            
        bin[0] = brown[1]+brown[2];
        bin[1] = clear[0]+clear[2];
        bin[2] = green[0]+green[1];
            
        int bcg = 0;
        for (i = 0; i < 3; i++){
            bcg += bin[i];
        }
            
        int minArr[] = {cbg,cgb,gcb,gbc,bgc,bcg};
        int min = minArr[0], indx = 0;
        for (i = 0; i < 6; i++){
            if (min > minArr[i]){
                indx = i;
                min = minArr[i];
            }
                
        }
            
            
        switch (indx)
        {
        case 0:
            printf("CBG %d\n",min);
            break;
        case 1:
            printf("CGB %d\n",min);
            break;
        case 2:
            printf("GCB %d\n",min);
            break;
        case 3:
            printf("GBC %d\n",min);
            break;
        case 4:
            printf("BGC %d\n",min);
            break;
        case 5:
            printf("BCG %d\n",min);
            break;
        }
    }
    return 0;
}
    
