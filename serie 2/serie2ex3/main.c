#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
int main()
{
    int h[256],length=256;
    unsigned char** image;
    unsigned char** histogram;
    char* f_import = "test.raw";
    char* f_export = "histogram.raw";
    int width=256,height=256;
    int i,j,max;
    image = ReadImage(height,width,f_import);

    for(i=0;i<length;i++)
    {
        h[i] = GetColorFrequency(image,height,width,i);
    }
    max = GetMax(h,length);

    histogram = FillHistogram(h,length);

    SaveImage(histogram,f_export,GetMax(h,length),length);

    printf("histogram saved!\n");


    return 0;
}
