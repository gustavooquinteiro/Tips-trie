#include "../lib/filemanager.h"

FILE * open(char *mode){
    FILE * suggestionfile = fopen(SUGGEST_FILE, mode);
    if (!ferror(suggestionfile))
      return suggestionfile;
    exit(EXIT_FAILURE);
}

void write(char * text){
  static int append = FALSE;
  FILE * file;
  if (append){
    file = open(APPEND_MODE);
  } else{
    file = open(WRITE_MODE);
    append = TRUE;
  }
  fprintf(file, "\t%s\n", text);
  close(file);
}

void read(){
  char buffer;
  FILE  * file = open(READ_MODE);
  while (!feof(file)) {
    fscanf(file, "%c", &buffer);
    printf("%c", buffer);

  }
  close(file);
  delete();
}

int delete(){
  if(!remove(SUGGEST_FILE))
    return TRUE;
  exit(EXIT_FAILURE);

}

void close (FILE * file){
  fclose(file);
}

char *append(char *orig, char c){
    size_t sz = strlen(orig);
    char *str = malloc(sz + 2);
    strcpy(str, orig);
    str[sz] = c;
    str[sz + 1] = '\0';
    return str;
}
