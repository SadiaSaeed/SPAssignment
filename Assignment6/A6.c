#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>


int main()
{
    // Directory path to list files
    char path[100];

    // Input path from user
    printf("Enter path to list files: ");
    scanf("%s", path); 

    tree(path, 0);

    return 0;
}
void tree(char *basePath, const int root)
{
    int i;
    char path[1000];
    struct dirent *dp;
    DIR *dir = opendir(basePath); //opens the directory and returns all files and folders in the directory 

    if (!dir) //checks if nothing exists in directory
        return;

    while ((dp = readdir(dir)) != NULL) //reads all the files and folders in that direcotry 
    {
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0) //if a single '.' or '..' encountered, then ignore
        {
            for (i=0; i<root; i++) //else run the loop for visualizattion. If you are in root folder then it wont operate
            {
                if (i%2 == 0 || i == 0) //based on the level of subfolder, the pipes are printed
                    printf("%c", '|');
                else
                    printf(" ");

            }

            printf("%c%c%c%s\n",'|', '-', '-', dp->d_name); //print file name

            strcpy(path, basePath); //updates path
            strcat(path, "/"); //
            strcat(path, dp->d_name);
            tree(path, root + 2);
        }
    }

    closedir(dir);
}
