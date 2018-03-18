#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "header.h"
#include "functions.h"
#include <string.h>

int main()
{
    int i,j,n=1024,pixel=128;
    unsigned char** image;
    header h;

    strcpy(h.imageName,"damier.pic");
    h.x = h.y = n;
    h.bitCount = n * n * 8;
    h.globalSize += (sizeof(header) * 8);
    strcpy(h.comment,"image d'un damier");

    image = CreateImageArray(n);

    FillVerticalImage(image,n,pixel);

    unsigned char** newImage = FillOrientalImage(image,n);

    unsigned char** damier = Damier(image,newImage,n);

    SaveImageWithHeader(damier,"damier.pic",n,h);

    printf("image saved!");

    return 0;
}
