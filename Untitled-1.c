#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// #include <unistb.h>

int notinpos(int *a, int b, int n){
    int i = 0; 

    while (i < n){
        if (a[i] == b){
            i = n+2;
        }
        i++;
    }
    return i == n? 1 : 0;
}


char *strjoin(char *a, char *b){
    int run = 0;
    char *comp = (char*)malloc(sizeof(char) * (strlen(a) + strlen(b)));
    for (int i = 0; i < strlen(a); i++){
        comp[run++] = a[i];
    }
    for (int i = 0; i < strlen(b); i++){
        comp[run++] = b[i];
    }
    return comp;
}


char* smallestString(int substrings_count, char** substrings) {
    int i = 0;
    char *str;
    int pos[substrings_count];

    for (int blank = 0; blank < substrings_count; blank++)
            pos[blank] = -1;

    while (i < substrings_count){
        str = NULL;
        for (int j = 0; j < -1 + substrings_count; j++){
            if (notinpos(pos, j, substrings_count) && strcmp(str,substrings[j]) > 0){
                str = substrings[j];
                pos[i] = j;
            }

        }
    }
    str = strjoin(substrings[pos[0]], substrings[pos[1]]);
    for (int j = 0; j < substrings_count; j++){
        str = strjoin(str, substrings[pos[j]]);
    }
    return str;
}


int main(void){

char **comp = (char**)malloc(sizeof(char*) * 4);
comp[0] = strjoin("", "aa");
comp[1] = strjoin("", "ab");
comp[2] = strjoin("", "ac");
comp[4] = NULL;
    write(1, 'h', 1);
// printf("%s", smallestString(3, comp));

return 0;
}