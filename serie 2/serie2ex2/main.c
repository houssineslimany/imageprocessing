#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
int main()
{
    int h[256];
    unsigned char** image;
    int width=400,height=300;
    int i,j,k=0;
    image = ReadImage(height,width,"collineraw385H289.raw");

    for(i=0;i<256;i++)
    {
        h[i] = GetColorFrequency(image,height,width,i);
    }

    for(i=0;i<256;i++)
    {
        printf("%d\n",h[i]);
    }


    return 0;
}
