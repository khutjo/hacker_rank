#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct t_node
{
    int data;
    struct t_node *next;
}               s_node;


char *strnew(char *b){
    int run = 0;
    char *comp = (char*)malloc(sizeof(char) * strlen(b));
    for (int i = 0; b[i]; i++){
        comp[run++] = b[i];
        comp[run] = '\0';
    }
    return comp;
}

void printhead(s_node *head)
{
                if (head == NULL)
                printf("EMPTY\n");
            else
                printf("%d\n", head->data);
}

void printstack(s_node *head){
    
}

int find(char *str){
    int i = strlen(str);
    while (str[i]!= ' ')
        i--;
    return i;
}

void superStack(int operations_size, char** operations) {
    int i = 0;
    int len;
    int count;
    s_node *node;
    s_node *head;
    s_node *run;

    len = 0;
    head = NULL;
    while (operations[i]){
        if (!strncmp(operations[i], "push", 4)){
            node = (s_node*)malloc(sizeof(s_node));
            node->data = atoi(&operations[i][4]);
            node->next = head;
            head = node;
            len++;
        }
        if (!strncmp(operations[i], "pop", 3)){
            if (head){
                node = head;
                head = head->next;
                free(node);
                len--;
            }
        }
        if (!strncmp(operations[i], "inc", 3)){
            run = head;
            count = 0;
            while (run){
                if (len - atoi(&operations[i][3]) >= count){
                    printf("==> %s <==", operations[i]);
                    printf(" in %d  ", run->data);
                    run->data += atoi(&operations[i][find(operations[i])]);
                    printf(" out %d  ", run->data);
                }
                run = run->next;
                count++;
            }
        }
        printhead(head);
        i++;
    }
}


int main(){

char **comp = (char**)malloc(sizeof(char*) * 11);

comp[0] = strnew("push 4");
comp[1] = strnew("pop");
comp[2] = strnew("push 3");
comp[3] = strnew("push 5");
comp[4] = strnew("push 2");
comp[5] = strnew("inc 3 1");
comp[6] = strnew("pop");
comp[7] = strnew("push 1");
comp[8] = strnew("inc 2 2");
comp[9] = strnew("push 4");
comp[10] = strnew("pop");
comp[11] = strnew("pop");

comp[11] = NULL;
printf("%d", atoi(&comp[5][find(comp[5])]));
superStack(10, comp);
    return 0;
}