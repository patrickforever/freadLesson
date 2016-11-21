#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct{
    unsigned char charType;
    unsigned short shortType;
    unsigned int UintType;
}DATA;
typedef struct{
    unsigned int a ;
    unsigned int b ;
    DATA data[2];
}BINFILE;
int main()
{
    int i , j , k , index;
    FILE *pFile;
    BINFILE BinFile;
    BINFILE RBinFile;
    BinFile.a = 5;
    BinFile.b = 10;
    BinFile.data[0].charType = '0';
    BinFile.data[0].shortType = 13;
    BinFile.data[0].UintType = 27;
    BinFile.data[1].charType = '1';
    BinFile.data[1].shortType = 14;
    BinFile.data[1].UintType = 28;
    pFile = fopen("test.bin","wb");
   //fwrite(&BinFile,sizeof(BINFILE),1,pFile);
    index = sizeof(BINFILE);
    fwrite((char*)&BinFile,sizeof(char),index,pFile);
    fclose(pFile);
    pFile = fopen("test.bin","rb");
    //fread(&RBinFile,sizeof(BINFILE),1,pFile);
   // printf("%d %d %c %d %d\n",RBinFile.a,RBinFile.b,RBinFile.data[0].charType,RBinFile.data[0].shortType,RBinFile.data[0].UintType);
    fread((char*)&RBinFile,sizeof(char),index,pFile);
    //fread(&RBinFile,sizeof(BINFILE),1,pFile);
    printf("%d %d %c %d %d\n",RBinFile.a,RBinFile.b,RBinFile.data[0].charType,RBinFile.data[0].shortType,RBinFile.data[0].UintType);




}
