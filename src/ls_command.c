#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>

#include "ls_command.h"


void my_ls(void){
    DIR *dir;
    struct dirent *entry;

    dir = opendir("."); // 현재디렉토리만 보여줌??
    if(dir == NULL){ // 오류일 경우
        perror("opendir");
        return;
    }
    else {
        while((entry = readdir(dir)) != NULL){
            if(entry->d_type == DT_DIR){
                printf("%s/\n", entry->d_name);
            } else{
            printf("%s\n", entry->d_name);
            }
        }
    }
    closedir(dir);
}