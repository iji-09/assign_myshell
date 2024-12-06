#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "ls_command.h"


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
        // printf("%s", input);

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
        else if(strcmp(argv[0], "cd") == 0){
            chdir(argv[1]);
        }
        else if(strcmp(argv[0], "pwd") == 0){
            getcwd(input, MAX_LINE);
            printf("%s\n", input);
        }
        else if(strcmp(argv[0], "ls") == 0){
            my_ls();
        }
        else if(strcmp(argv[0], "cat") == 0){
            // you code comes here...
            // cat 구현
            // argv[1]이 필요
            
            //--------------------------
            if (argv[1] == NULL) {
                printf("cat: missing file operand\n");
            }
            else {
                int fd = open(argv[1], O_RDONLY);

                    if (fd < 0) {
                        perror("cat");
                    } 
                    else {
                        char buffer[1024];
                        ssize_t bytes_read;
                        while ((bytes_read = read(fd, buffer, sizeof(buffer) - 1)) > 0) {
                            buffer[bytes_read] = '\0';
                            printf("%s", buffer);
                        }
                        if (bytes_read < 0) {
                            perror("cat");
                        }
                    close(fd);
                }
            }
            //--------------------------

        }
        else{
            if(access(argv[0], X_OK) == 0){
                printf("execute %s\n", argv[0]);
            }
            else{
                printf("command not found: %s\n", argv[0]);
            }
        }
        

    }

    return 0;
}