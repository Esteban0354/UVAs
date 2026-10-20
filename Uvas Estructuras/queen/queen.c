#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Esteban Munoz Serrano - 8966406 

int main()
{
    int x1,x2,y1,y2;
	int absX, absY;
	

	while (scanf("%d %d %d %d", &x1, &y1, &x2, &y2 ), x1 != 0  && y1 != 0 && x2 != 0 && y2 !=0){
		absX = x2 - x1;
		absX = abs(absX);
		absY = y2 - y1;
		absY = abs(absY);
		if (x1 == x2 && y1 == y2)
		{
			printf("0 \n");
		}else if (x1 == x2 || y1 == y2 || absX == absY)
		{
			printf("1\n");
		}else{
			printf("2\n");
		}
		
		
	}
	
	return 0;

}