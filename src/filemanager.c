#include "../lib/filemanager.h"

FILE * open(char *mode){
    FILE * suggestionfile = fopen(SUGGEST_FILE, mode);
    if (!suggestionfile){            
        exit(EXIT_FAILURE);
    }
    return suggestionfile;
}

void write(char * text){
    FILE * file = open(APPEND_MODE);
    fprintf(file, "\t%s\n", text);  
    close(file);
}

char * read(){
    char * buffer = (char *)malloc(MAX_SIZE* sizeof(char)); 
    FILE  * file = open(READ_MODE);
    int len = fread(buffer, sizeof(char), MAX_SIZE, file);
    close(file);
    buffer[len] = '\0';
    return buffer;
}

int delete(){
  if(!remove(SUGGEST_FILE))
    return TRUE;
  exit(EXIT_FAILURE);

}

void close (FILE * file){
  fclose(file);
}


