
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

unsigned char** CreateHistogram(int height,int width)
{
    int i,j;
    unsigned char** image;
    image = CreateImageArray(height,width);

    for(i=0;i<height;i++)
    {
        for(j=0;j<width;j++)
        {
            image[i][j] = 255;
        }
    }

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

int GetMax(int h[],int length)
{
    int m = h[0];
    int i;

    for(i=0;i<length;i++)
            if(h[i]>m)
                m = h[i];

    return m;
}

unsigned char** FillHistogram(int h[],int length)
{
    int i,j;
    int m = GetMax(h,length);
    unsigned char** histogram;
    for(i=0;i<length;i++)
    {
        //vous pouvez choisir 3000 si vous voulez comme mentionné dans l'exercice
        //j'ai choisi 400 pour obtenir un histogramme de petite taille
        h[i] = (int) (h[i] * 400) / m ;
    }

    m = GetMax(h,length);
    histogram = CreateHistogram(m,length);

    for(i=0;i<length;i++)
    {
        j = h[i];
        while(j > 0)
        {
            histogram[m - j][i] = 0;
            j--;
        }
    }

    return histogram;
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
