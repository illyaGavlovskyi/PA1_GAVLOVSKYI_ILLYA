//Illya Gavlovskyi
//CS 446
//PA1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>

#define MAX 100

int parseInput(char * input, char splitWords[][500], int maxWords);
void changeDirectories(const char *path);
int executeCommand(char * const* enteredCommand, const char* infile, const char* outfile);

int main()
{
    char input[MAX];
    char splitWords[MAX][500];

    while(1)
    {
        char cwd[MAX];
        getcwd(cwd,MAX);
        printf("igavlovskyi:%s$",cwd);

        fgets(input, sizeof(input), stdin);
        int numWords = parseInput(input, splitWords, MAX);
        
        if(strcmp(splitWords[0],"cd") == 0)
        {
            changeDirectories(splitWords[1]);   
        }
        else if(strcmp(splitWords[0],"exit") == 0)
        {
            break;
        }
        else
        {
            for()
            {
                if(strcmp(splitWords[0], "<") == 0)
                {

                }
                else if(strcmp(splitWords[0], ">") == 0)
                {

                }
                else
                {
                    // executeCommand();
                }
            }
        }
    }
    return 0;
}

int parseInput(char * input, char splitWords[][500], int maxWords)
{
    char *token;
    token = strtok(input, " ");
    int num = 0;
    while(token != NULL) {
        printf( "%s\n", token); // TEST

        strcpy (splitWords[num], token);
        token = strtok(NULL, " \n");
        num++;
   }
   return num; 
}

void changeDirectories(const char *path)
{
    int check = chdir(path);
    if(check == -1)
    {
        printf("chdir Failed: %s\n", strerror(errno));
    }
}

int executeCommand(char * const* enteredCommand, const char* infile, const char* outfile)
{
    
}