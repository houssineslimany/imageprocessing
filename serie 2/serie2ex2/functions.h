
#include <math.h>

unsigned char** CreateImageArray(int height,int width)
{
    int i;
    unsigned char** image;
    image = (char**) malloc(sizeof(unsigned char*) * height);

    for(i=0;i<height;i++)
        image[i] = (char*) malloc(sizeof(unsigned char) * width);

    return image;

}

unsigned char** ReadImage(int height,int width,char* src)
{
    FILE* f;
    f = fopen(src,"rb");
    int i,j;
    unsigned char** fullImage;
    fullImage = CreateImageArray(height,width);

    for(i=0;i<height;i++)
    fread(fullImage[i], sizeof(unsigned char),width,f);

    fclose(f);
    return fullImage;

}

int GetColorFrequency(unsigned char** image,int height,int width,int c)
{
    int i,j,n=0;
    for(i=0;i<height;i++)
        for(j=0;j<width;j++)
            if((int)image[i][j] == c)
                n++;

    return n;
}

void SaveImage(unsigned char** image,char* filename,int height,int width)
{
    int i,j;

    FILE* f;
    f = fopen(filename,"wb");

    for(i=0;i<height;i++)
    {
        for(j=0;j<width;j++)
        {
             fprintf(f,"%c",image[i][j]);
        }
    }

    fclose(f);
}
