#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned char *readFille(const char *fileName){
  FILE *file;
  unsigned char *buffer;
  unsigned long fileLen;


  file = fopen(fileName, "rb");
  if (!file)
  {
    fprintf(stderr, "Unable to open file %s", fileName);
    return "none";
  }

  fseek(file, 0, SEEK_END);
  fileLen=ftell(file);
  fseek(file, 0, SEEK_SET);

  buffer=(char *)malloc(fileLen);
  if (!buffer)
  {
    fprintf(stderr, "Memory error!");
    fclose(file);
    return "none";
  }

  fread(buffer,fileLen,sizeof(unsigned char),file);
  fclose(file);

  int i=0;
  unsigned char * fileContent = malloc(sizeof(fileLen)*2);
  char *c;
  while (i < fileLen){
    printf("%02X ",((unsigned char)buffer[i]));
    sprintf(fileContent,"%s %02X",fileContent,((unsigned char)buffer[i]));
    i++;
    //if( ! (i % 16) ) printf( "\n" );
  }

  return fileContent;
}

int main(int argc, char *argv[])
{

  unsigned char *res = readFille(argv[1]);
  printf("%s", res);
  return 0;
}
