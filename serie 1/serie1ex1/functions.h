
unsigned char** CreateImageArray(int length)
{
    int i;
    unsigned char** image;
    image = (char**) malloc(sizeof(unsigned char*) * length);

    for(i=0;i<length;i++)
        image[i] = (char*) malloc(sizeof(unsigned char) * length);

    return image;

}

void FillVerticalImage(unsigned char** image,int length,int pixel)
{
    int i,j,bit=0;
    bool isWhite = true;
    for(i=0;i<length;i++)
    {
        for(j=0;j<length;j++)
        {
            if(isWhite)
            {
                image[i][j] = 255;
                bit++;
            }
            else
            {
                image[i][j] = 0;
                bit++;
            }

            if(bit == pixel)
            {
                isWhite = !isWhite;
                bit = 0;
            }
        }
        isWhite = true;
    }
}

void DisplayImage(unsigned char** image,int length)
{
    int i,j;
    for(i=0;i<length;i++)
    {
        for(j=0;j<length;j++)
        {
             printf("%d",image[i][j]);
             if((j+1)%8 == 0)
                printf("\t");
        }
        printf("\n");
    }
}

void SaveImage(unsigned char** image,char* filename,int length)
{
    int i,j;

    FILE* f;
    f = fopen(filename,"w");

    for(i=0;i<length;i++)
    {
        for(j=0;j<length;j++)
        {
             fprintf(f,"%c",image[i][j]);
        }
    }

    fclose(f);
}

unsigned char** FillOrientalImage(unsigned char** image,int length)
{
    unsigned char** newImage = CreateImageArray(length);
    int i,j;

    for(i=0;i<length;i++)
    {
        for(j=0;j<length;j++)
        {
            newImage[i][j] = image[j][i];
        }
    }

    return newImage;
}

unsigned char** Damier(unsigned char** image_rv,unsigned char** image_ro,int length)
{
    unsigned char** damier = CreateImageArray(length);
    int i,j;

    for(i=0;i<length;i++)
    {
        for(j=0;j<length;j++)
        {
           /*if(((int)image_rv[i][j]) == 255 && ((int)image_ro[i][j]) == 255)
                damier[i][j] = 255;
           else if(((int)image_rv[i][j]) == 0 && ((int)image_ro[i][j]) == 0)
                damier[i][j] = 255;
           else damier[i][j] = 0;*/
            damier[i][j] = (image_rv[i][j] == image_ro[i][j]) ? 255 : 0;
        }
    }

    return damier;
}
