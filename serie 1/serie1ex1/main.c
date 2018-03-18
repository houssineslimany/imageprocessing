#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "functions.h"

int main()
{
    int i,j,n=1024,pixel=128;
    unsigned char** image;

    //Q1

    image = CreateImageArray(n);

    FillVerticalImage(image,n,pixel);

    SaveImage(image,"rv.pic",n);

    //Q2

    unsigned char** newImage = FillOrientalImage(image,n);

    SaveImage(newImage,"ro.pic",n);

    //Q3

    unsigned char** damier = Damier(image,newImage,n);

    SaveImage(damier,"damier.pic",n);

    printf("image saved!");

    return 0;
}
