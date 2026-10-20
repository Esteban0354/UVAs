#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Esteban Munoz Serrano - 8966406 

/*
void case1(double arr[], int size){
    double u=0.0,a=0.0,t=0.0,v=0.0,s=0.0;
    u = arr[1];
    v = arr[2];
    t = arr[3];
    
    a = (v-u)/t;
    s = (u+v)*t / 2;
    
    printf("%.3lf %.3lf\n",s,a);
}

void case2(double arr[], int size){
    double u=0.0,a=0.0,t=0.0,v=0.0,s=0.0;
    u = arr[1];
    v = arr[2];
    a = arr[3];
    printf("%lf\n",v);
    t = (v-u)/a;
    s = (u+v)*t / 2;
    printf("%.3lf %.3lf\n",s,t);
}

void case3(double arr[], int size){
    double u=0.0,a=0.0,t=0.0,v=0.0,s=0.0;
    u = arr[1];
    a = arr[2];
    s = arr[3];
    
    v = sqrt(u*u+2*a*s);
    t = (v-u)/a;
    printf("%.3lf %.3lf\n",v,t);
}

void case4(double arr[], int size){
    double u=0.0,a=0.0,t=0.0,v=0.0,s=0.0;
    v = arr[1];
    a = arr[2];
    s = arr[3];
    printf("%lf\n",v);
    u = sqrt(v*v-2*a*s);
    t = t = (v-u)/a;
    printf("%.3lf %.3lf\n",u,t);
}
*/
int main()
{
    int n,i;
    int caso = 1;
    double u,a,t,v,s;
    int control = 1;
    int flag = 1;
    while (scanf("%d",&n), n!= 0)
    {
        printf("Case %d: ",caso);
        caso++;
        switch (n)
        {
        case 1:
            scanf("%lf %lf %lf",&u,&v,&t);
            a = (v-u)/t;
            s = (u+v)*t / 2;
            printf("%.3lf %.3lf\n",s,a);
            break;
        case 2:
            scanf("%lf %lf %lf", &u,&v,&a);
            t = (v-u)/a;
            s = (u+v)*t / 2;
            printf("%.3lf %.3lf\n", s, t);
            break;
        case 3:
            scanf("%lf %lf %lf", &u,&a,&s);
            v = sqrt(u*u+2*a*s);
            t = (v-u)/a;
            printf("%.3lf %.3lf\n",v,t);
            break;
        case 4:
            scanf("%lf %lf %lf", &v, &a, &s);
            u = sqrt(v*v-2*a*s);
            t = t = (v-u)/a;
            printf("%.3lf %.3lf\n", u, t);
            break;
        case 0:
            flag = 0;
            break;
        }
    }
    /*
    while (control!=0)
    {
        
    
    
        for ( i = 0; i < 4; i++)
        {
            scanf("%lf",&arr[i]);
        }
        
        
        
        
        control = round(arr[0]);
        printf("%d",control);
        
        
        switch (control){
        case 1:
            case1(arr,4);
            break;
        case 2:
            case2(arr,4);
            break;
        case 3:
            case3(arr,4);
            break;
        case 4: 
            case4(arr,4);
            break;
        case 0:
            break;
        }
    
    }
    */

    return 0;
}