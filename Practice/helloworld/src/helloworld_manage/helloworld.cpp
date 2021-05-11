//  helloworld.cpp
#include "helloworld.h"
#include <stdio.h>
#include <stdlib.h>

static int g_arr[2] = {0,1};
void helloworld::outputWord()
{
    std::cout << "hello world!" << std::endl;
}

void generateRand(int num)
{
    int icount = 0;
    printf("the generate arr is : \n");
    int temp = 0;
    // struct tm *p;
    for(int i = 0; i < num; ++i)
    {
        if(((i %10) == 0) && (0 != i))
        {
            printf("\n");
        }
        temp = g_arr[rand()%2];
        // printf(" %d", rand());
        printf(" %d", temp);
        if(0 == temp)
        {
            ++icount;
        }
        // printf("Argument %d is %s\n", i, argv[i]);
    }
    printf("\n");
    printf("the arr num of 0 :%d, the num of 1: %d\n", icount, (num - icount));
}
