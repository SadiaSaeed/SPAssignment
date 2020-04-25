#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>

int main()
{
    char command[1024];

    int ci = read(STDIN_FILENO, command, sizeof(command));

    if (ci < 0)
    {
        perror("Reading command: ");
        exit(-1);
    }
    command[ci - 1] = '\0';

    char delim[] = " ";
    char *ptr = strtok(command, delim);

    if (strcmp(ptr, "cp") == 0)
    {
        ptr = strtok(NULL, delim);
        //int ou = write(STDOUT_FILENO, "YES\n", sizeof("YES\n"));
        if (ptr == NULL)
        {
            int ou = write(STDOUT_FILENO, "Error! Not enough arguements\n", sizeof("Error! Not enough arguements\n"));
            exit(0);
        }
        else if (strcmp(ptr, "-r") == 0)
        {

            ptr = strtok(NULL, delim);
            char source[strlen(ptr)];

            strcpy(source, ptr);

            ptr = strtok(NULL, delim);
            char dest[strlen(ptr)];

            strcpy(dest, ptr);

            cpr(source, dest);
        }
        else
        {
            char source[strlen(ptr)];

            strcpy(source, ptr);

            ptr = strtok(NULL, delim);
            char dest[strlen(ptr)];

            strcpy(dest, ptr);

            char buffer[1024];
            int file1, file2;

            int count;

            if (strstr(source, ".") != NULL)
            {
                file1 = open(source, O_RDONLY);

                if (file1 < 0)
                {
                    perror("File 1: ");
                    exit(-1);
                }

                if (strstr(dest, ".") != NULL)
                {

                    file2 = open(dest, O_CREAT | O_RDWR);

                    if (file2 < 0)
                    {
                        perror("File 2: ");
                        exit(-1);
                    }

                    while ((count = read(file1, buffer, sizeof(buffer))) != 0)
                    {
                        write(file2, buffer, count);
                    }

                    if (close(file1) < 0)
                    {
                        perror("File 1 closing: ");
                    }

                    if (close(file2) < 0)
                    {
                        perror("File 2 closing: ");
                    }

                    return 0;
                }
                else
                {
                    int ou = write(STDOUT_FILENO, "Error! Specify filename\n", sizeof("Error! Specify filename\n"));
                    exit(0);
                }
            }
            else
            {

                int ou = write(STDOUT_FILENO, "Error! Directory not allowed. Use -r\n", sizeof("Error! Directory not allowed. Use -r\n"));
                exit(0);
            }
        }
    }
}

int cpr(char source[], char dest[])
{

    struct dirent **namelist;
    int n = scandir(source, &namelist, NULL, alphasort);
    char filename1[1024];
    char filename11[1024];
    char filename2[1024];

    while (n--)
    {
        //printf("Upar wala %d\n", n);
        if (namelist[n]->d_type != 4)
        {
            char buffer[1024];
            int count = 0;
            //Its a file
            bzero(filename1, sizeof(filename1));
            strcpy(filename1, source); //file = /home/maaz/Downloads
            strcat(filename1, "/");
            strcat(filename1, namelist[n]->d_name); // file = /home/maaz/Downloads/sample.txt

            int file1 = open(filename1, O_RDONLY);

            if (file1 < 0)
            {
                perror("File 1: ");
                exit(-1);
            }

            bzero(filename2, sizeof(filename2));
            strcpy(filename2, dest);
            strcat(filename2, "/");
            strcat(filename2, namelist[n]->d_name);

            int file2 = open(filename2, O_WRONLY | O_CREAT);

            if (file2 < 0)
            {
                perror("File 2: ");
                exit(-1);
            }

            while ((count = read(file1, buffer, sizeof(buffer))) != 0)
            {
                write(file2, buffer, count);
            }

            write(STDOUT_FILENO, "Pasted: ", sizeof("Pasted: "));
            write(STDOUT_FILENO, filename2, sizeof(filename2));
            write(STDOUT_FILENO, "\n", sizeof("\n"));

            if (close(file1) < 0)
            {
                perror("File 1 closing: ");
            }

            if (close(file2) < 0)
            {
                perror("File 2 closing: ");
            }
        }
        else {
            bzero(filename1, sizeof(filename1));
            strcpy(filename1, dest); //file = /home/maaz/testSP
            strcat(filename1, "/");
            strcat(filename1, namelist[n]->d_name); // file = /home/maaz/testSP/SomeFolder
            int c = mkdir(filename1, 0777);
            if (c < 0)
            {
                if (errno == EEXIST)
                    break;
                perror("Dir not created: ");
                write(STDOUT_FILENO, filename1, sizeof(filename1));
                exit(-1);
            }

            bzero(filename11, sizeof(filename11));
            strcpy(filename11, source); //file = /home/maaz/Downloads
            strcat(filename11, "/");
            strcat(filename11, namelist[n]->d_name); // file = /home/maaz/Downloads/SomeFolder

            cpr(filename11, filename1);

        }   
        //printf("Neeche wala %d\n", n);
    }
}