#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_LINE 80
#define MAX_ARGS 10

int main()
{

    char input[MAX_LINE];
    char *token;
    char *argv[MAX_ARGS];

    while(1){
        // prompt
        printf("myshell> ");

        // read command
        fgets(input, MAX_LINE, stdin);
        printf("%s\n", input);

        // tokenize input
        token = strtok(input, " \n\t");
        int i = 0;
        while(token != NULL){
            argv[i++] = token; // argv에 token을 하나씩 집어넣는 작업
            token = strtok(NULL, " \n\t");
        }
        argv[i] = NULL; // 종료를 알림

        if(argv[0] == NULL){ // empty command
            continue;
        }
        if(strcmp(argv[0], "exit") == 0){
            printf("Good bye~\n");
            exit(0);
        }

    }

    return 0;
}