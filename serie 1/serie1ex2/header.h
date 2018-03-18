typedef struct header header;

struct header
{
    char comment[128 - ((sizeof(char)*32) + (sizeof(int)*4))];//80
    char imageName[32];//32
    int x;//4
    int y;//4
    int bitCount;//4
    int globalSize;//4
};
