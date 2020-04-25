#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

struct directory
{
    char dname[1000];
    char access[10];
    int filescount;
    int dircount;

    struct directory *next; //to point it to the next object of directory
};

struct filelist
{
    char fname[1000];
    int fsize;
    char access[10];

    struct filelist *next;
};

int main()
{
    struct filelist *fprev, *fhead, *fp; // three objects created to point to prev, head and current
    struct directory *dprev, *dhead, *dp;
    struct dirent **namelist;  //returns the properties of file and directory both
    struct dirent **seminamelist; 
    struct stat fileStat; //returns advanced properties of file  
    int n;
    int fc;
    int dc;
    fhead = NULL;
    dhead = NULL;
    int m;
    char flist[100];
    char path[] = "/home/sadia/"; 
    n = scandir(path, &namelist, NULL, alphasort); //returns the count of all the files and folders in the path

    while (n--)
    {
        if (namelist[n]->d_type == 4) //All the files and folder are saved in namelist, it is checking if it is a directory or not 
        {
            dp = malloc(sizeof(struct directory)); //assign the required no.of bytes by the directory in memory
            sprintf(&dp->dname, "%s", namelist[n]->d_name); //extract d_name and initialzes dname(from direcory object)
            bzero(flist, sizeof(flist)); //flist = "";
            strcpy(flist, path); //updates if there is any other folder in the directory; flist = /home/sadia/
            strcat(flist, namelist[n]->d_name); //flist = /home/sadia/SPAssignments
            m = scandir(flist, &seminamelist, NULL, alphasort); //returns the count of files in the folder of that directory
            fc = 0;
            dc = 0;
            while (m--)
            {
                if (seminamelist[m]->d_type == 4) //checks if there is a directory 
                    dc++; //increment if its a directory
                else
                    fc++; //increment if its a file
            }
            dp->dircount = (int) dc; //assigns the number of directories in that directory
            dp->filescount =(int) fc; //assigns the number of files in that directory

            if (stat(flist, &fileStat) < 0) //checks for error
            {
                perror("Directory: ");
                exit(-1);
            }

            if (S_ISDIR(fileStat.st_mode))//checks if it is a directory
            {
                dp->access[0] = 'd'; //if it is so store at the fisrt index of access
            }
            else
            {
                dp->access[0] = '-';
            }
            if (fileStat.st_mode & S_IRUSR) //checks if it has reading permissions or not for that usergroup
            {
                dp->access[1] = 'r'; 
            }
            else
            {
                dp->access[1] = '-';
            }
            if (fileStat.st_mode & S_IWUSR) //checks if that usrgroup has writing permissions or not
            {
                dp->access[2] = 'w';
            }
                else
            {
                dp->access[2] = '-';
            }

            if (fileStat.st_mode & S_IXUSR) //checks if the usergroup has executable permissions or not
            {
                dp->access[3] = 'x';
            }
            else
            {
                dp->access[3] = '-';
            }
            if (fileStat.st_mode & S_IRGRP) //checks if the group has reading permissions or not
            {
                dp->access[4] = 'r';
            }
            else
            {
                dp->access[4] = '-';
            }

            if (fileStat.st_mode & S_IWGRP) //checks if the group has writing permissions or not
            {
                dp->access[5] = 'w';
            }
            else
            {
                dp->access[5] = '-';
            }
            if (fileStat.st_mode & S_IXGRP) //checks if the group has execution permissions or not
            {
                dp->access[6] = 'x';
            }
            else
            {
                dp->access[6] = '-';
            }
            if (fileStat.st_mode & S_IROTH) //checks if others have reading permissions or not
            {
                dp->access[7] = 'r';
            }
            else
            {
                dp->access[7] = '-';
            }
            if (fileStat.st_mode & S_IWOTH) //checks if others have writing permissions or not
            {
                dp->access[8] = 'w';
            }
            else
            {
                dp->access[8] = '-';
            }
            if (fileStat.st_mode & S_IXOTH) //checks if others have execution permissions or not
            {
                dp->access[9] = 'x';
            }
            else
            {
                dp->access[9] = '-';
            }

            dp->next = NULL; 
            if (dhead == NULL) //checking if the head is null
            {
                dhead = dp; //if null assign the object to directory head
            }
            else
            {
                dprev->next = dp; //else, assign dp to the next pointer of previous node
            }
            dprev = dp; //assign dp to previous node
        }
        else //if finds a file
        {
            fp = malloc(sizeof(struct filelist)); //extract the size of filelist and assign it to the memory
            sprintf(&fp->fname, "%s", namelist[n]->d_name);//fname saved to the file pointer 
            bzero(flist, sizeof(flist));
            strcpy(flist, path);
            strcat(flist, namelist[n]->d_name);
            if (stat(flist, &fileStat) < 0) //checks if the stat function is succesfully called or not
            {
                perror("filelist: ");
                exit(-1);
            }

            
            fp->fsize = (int) fileStat.st_size; //retrieves the file size and stores it in fp object

            if (S_ISDIR(fileStat.st_mode))
            {
                fp->access[0] = 'd';
            }
            else
            {
                fp->access[0] = '-';
            }
            if (fileStat.st_mode & S_IRUSR)
            {
                fp->access[1] = 'r';
            }
            else
            {
                fp->access[1] = '-';
            }
            if (fileStat.st_mode & S_IWUSR)
            {
                fp->access[2] = 'w';
            }
            else
            {
                fp->access[2] = '-';
            }

            if (fileStat.st_mode & S_IXUSR)
            {
                fp->access[3] = 'x';
            }
            else
            {
                fp->access[3] = '-';
            }
            if (fileStat.st_mode & S_IRGRP)
            {
                fp->access[4] = 'r';
            }
            else
            {
                fp->access[4] = '-';
            }

            if (fileStat.st_mode & S_IWGRP)
            {
                fp->access[5] = 'w';
            }
            else
            {
                fp->access[5] = '-';
            }
            if (fileStat.st_mode & S_IXGRP)
            {
                fp->access[6] = 'x';
            }
            else
            {
                fp->access[6] = '-';
            }
            if (fileStat.st_mode & S_IROTH)
            {
                fp->access[7] = 'r';
            }
            else
            {
                fp->access[7] = '-';
             }
            if (fileStat.st_mode & S_IWOTH)
            {
                fp->access[8] = 'w';
            }
            else
            {
                fp->access[8] = '-';
            }
            if (fileStat.st_mode & S_IXOTH)
            {
                fp->access[9] = 'x';
            }
            else
            {
                fp->access[9] = '-';
            }

            fp->next = NULL;
            if (fhead == NULL)
            {
                fhead = fp;
            }
            else
            {
                fprev->next = fp;
            }
            fprev = fp;
        }
    }

    //print all the files
    fp = fhead;
    printf("FILES: \n");
    while (fp != NULL)
    {
        printf("%s\t  %s\t  %d bytes\n", fp->fname, fp->access, fp->fsize);
        fp = fp->next;
    }

    //print all the directories
    dp = dhead;
    printf("DIRECTORIES: \n");
    while (dp != NULL)
    {
        printf("%s\t  %s\t  %d folders\t  %d files\n", dp->dname, dp->access, dp->dircount, dp->filescount);
        dp = dp->next;
    }
}

