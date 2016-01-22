#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

//#define TEST1

#ifdef TEST1
        #define ARRAY_SIZE     4
#else
        #define ARRAY_SIZE     5
#endif

int solution(int *A, int size)
{
        int index = 0;
        int loopCount = 0;
        int *pArrCheck = (int*)malloc(sizeof(int)*size);
        if (pArrCheck == NULL){
               printf("malloc faild\n");
               return -2;
        }
        memset(pArrCheck, 0, sizeof(int)*size);

        // frist index
        pArrCheck[0] = 1;
        for (loopCount = 0; loopCount < size; loopCount++)
        {
               index = index + A[index];
               printf("%d ", index);
               // vliad index
               if ((index >= 0) && (index<size)){
                       if (pArrCheck[index] != 1){
                              pArrCheck[index] = 1;
                       }
                       else{ // already checked
                              return -1;
                       }
               }
               // invalid index
               else{
                       loopCount++;// last jump
                       break;
               }
        }
        
        return loopCount;
}


void main()
{
#ifdef TEST1
        int array[ARRAY_SIZE] = { 1, 1, -1, 1};
#else
        int array[ARRAY_SIZE] = { 2, 3, -1, 1, 3 };
#endif
        int nRet = solution(array, ARRAY_SIZE);
        printf("\n");
        printf("return : %d \n", nRet );
}
