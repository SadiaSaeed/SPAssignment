#include <stdio.h>
#include <string.h>


int main()
{
    char input1[1000];
    fgets(input1, 1000, stdin); //reads a line from input and stores it in input1

    int len = strlen(input1); 

    input1[len-1] = '\0'; //Assigns null to the \n character
    char delim[] = " ";

    char *ptr = strtok(input1, delim);//Tokenizes the input string on space

        if (strcmp(ptr, "ls") == 0){ //compares if the string is equal to "ls"
            printf("ls -> List  information  about  the FILEs (the current directory by default).\n");

            if (ptr != NULL) //checks for the argument
                ptr = strtok(NULL, delim);
            else //if no argument found then exit

                exit(1);
                
            if (strcmp(ptr, "-l") == 0)
            {
                printf("When used with ls command, -l, it displays all the files and directories in the current working directory, along with respective permissions, owners, and created date and time \n");
            }
            else if (strcmp(ptr, "-a") == 0)
            {
                printf("When used with ls command, -a, it can check hidden files and directories. \n");
            }
            else if (strcmp(ptr, "-i") == 0 || strcmp(ptr, "-li") == 0)
            {
                printf("When used with ls command,-i or -li, checks inode number of files and directories.\n");
            }
            else if (strcmp(ptr, "-o") == 0)
            {
                printf("When used with ls command,-o, will show owner of the files and directories and will not show the groups.\n");
            }
            else if (strcmp(ptr, "-m") == 0){
                printf("Linux ls command with option -m will list the files and directories separated by comma.\n");
            }
            else if (strcmp(ptr, "-lQ") == 0){
                printf("When used with ls command,-lQ, will list files and directories in which names of files and directories are enclosed in quotes.\n");
            }
            else if (strcmp(ptr, "-R") == 0){
                printf("When used with ls command,-R, you can list directories recursively. Recursively means it will list all the directory with is all subdirectory in a tree format.\n");
            }
            else if (strcmp(ptr, "~") == 0){
                printf("When used with ls command, ~ , will switch you to home directory.\n");
            }
            else if (strcmp(ptr, "-lt") == 0){
                printf("When used with ls command,-lt, will list the files and directories by it’s modification date in ascending order, means the higher will be come first.\n");
            }
            else if (strcmp(ptr, "-lS") == 0){
                printf("When used with ls command,-lS, you can sort the files and directories by it size.\n");
            }
            else if (strcmp(ptr, "-lh") == 0){
                printf("When used with ls command,-lh, will list the size of the files and directories in Human Readable format for Example 20K (20 KB), 15M (15 MB).\n");
            }
            else if (strcmp(ptr, "-ln") == 0){
                printf("When used with ls command,-ln, will show the UID (User ID) and GID (Group ID) numbers of file and directory.\n");
            }
            else if (strcmp(ptr, "-lG") == 0){
                printf("When used with ls command,-lG, you can list only Owner of the files and directories to which they belong and not groups.\n");
            }
            else if (strcmp(ptr, "-g") == 0){
                printf("When used with ls command,-g, will list the group of the files and directories to which they belong.\n");
            }
            else if (strcmp(ptr, "-lF") == 0){
                printf("When used with ls command,-lF, will list the directories with a/at end.\n");
            }

        }
        else if (strcmp(ptr, "cp") == 0){ 

            printf("The cp command is a command-line utility for copying files and directories. \n\n");
            ptr = strtok(NULL, delim);


            if (strcmp(ptr, "-R") == 0){
                printf("When used with cp command,-R, copy a directory. This will recursively copy a folder and create a copy.\n\n");

                ptr = strtok(NULL, delim);

                if (strcmp(ptr, "-v") == 0)
                {
                    printf("When used with cp command along with -R,-v, show files that are being copied. This prints the files and folders that are being copied to standard output.\n");
                    ptr = strtok(NULL, delim);
                }
            }
            else if (strcmp(ptr, "-b") == 0)
            {
                printf("If a copy operation will overwrite a file the -b flag may be used to create a back up of the file. This copies the file into place and writes a backup file.\n");
                ptr = strtok(NULL, delim);
            }
            else if (strcmp(ptr, "-S") == 0){
                printf("When used with cp command,-S, specifies the name of the backup file.\n");
                ptr = strtok(NULL, delim);
            }
            else if (strcmp(ptr, "-i") == 0) {
                printf("When used with cp command,-i, prompts for confirmation when copying a file. Normally when using the cp command a destination file will be overwritten if it exists when copying. Using the -i flag the command will prompt to overwrite the file.\n");
                ptr = strtok(NULL, delim);
            }
            else if (strcmp(ptr, "-l") == 0)
            {
                printf("When used with cp command,-l, creates a hard link instead of copying. Instead of copying the file a new file will be created that is a hard link to the data on disk. \n");
                ptr = strtok(NULL, delim);
            }
            else if (strcmp(ptr, "--preserve") == 0) {
                printf("When used with cp command,--preserve, preserves file attributes (permissions, group and user owernship). By default mode, ownership and timestamps will be preserved, if any other attributes want to be preserved pass them along with the attributes to be preserved.\n");
                ptr = strtok(NULL, delim);
            }


        }
        else if (strcmp(ptr, "rm") == 0){

            printf("rm is used to delete or remove files and directory. Once you delete the files then you can not recover the contents of files and directory.\n\n");
            ptr = strtok(NULL, delim);

            if ((strcmp(ptr, "-f") == 0) || (strcmp(ptr, "--force") == 0)){
                printf("When used with rm command,-f or --force, ignores nonexistant files, and never prompt before removing.\n");

            }
            else if (strcmp(ptr, "-i") == 0){
                printf("When used with rm command,-i, prompts before every removal.\n");
            }
            else if (strcmp(ptr, "--interactive") == 0){
                printf("When used with rm command,--interactive,prompts according to WHEN: never, once (-I), or always (-i). If WHEN is not specified, then prompt always.\n");
            }
            else if (strcmp(ptr, "--one-file-system") == 0){
                printf("When used with rm command,--one-file-system, removes a hierarchy recursively, skip any directory that is on a file system different from that of the corresponding command line argument\n");
            }
            else if (strcmp(ptr, "--no-preserve-root") == 0){
                printf("When used with rm command,--no-preserve-root, does not treat ""/"" (the root directory) in any special way.\n");
            }
            else if (strcmp(ptr, "--preserve-root") == 0){
                printf("When used with rm command,--preserve-root, does not remove ""/"" (the root directory), which is the default behavior.\n");
            }
            else if ((strcmp(ptr, "-r") == 0) || (strcmp(ptr, "-R") == 0) || (strcmp(ptr, "--recursive") == 0)){
                printf("When used with rm command,-r, removes directories and their contents recursively.\n");
            }
            else if ((strcmp(ptr, "-d") == 0) || (strcmp(ptr, "--dir") == 0)){
                printf("When used with rm command,-d or -dir, removes empty directories. This option permits you to remove a directory without specifying -r/-R/--recursive, provided that the directory is empty. In other words, rm -d is equivalent to using rmdir.\n");
            }
            else if ((strcmp(ptr, "-v") == 0) || (strcmp(ptr, "--verbose") == 0)){
                printf("When used with rm command,-v, enables Verbose mode; explain at all times what is being done.\n");
            }
            else if (strcmp(ptr, "-l") == 0){
                printf("When used with rm command,-l, Prompt once before removing more than three files, or when removing recursively. This option is less intrusive than -i, but still gives protection against most mistakes.\n");
            }

        }
        else if (strcmp(ptr, "mkdir") == 0){
            printf("The mkdir allows the user to create directories.\n\n");

            ptr = strtok(NULL, delim);

            if (strcmp(ptr, "-p") == 0){
                printf("When used with mkdir command,-p, a complete directory structure is created. This is possible, but you'll have to use the -p command line option.\n");
            }
            else if (strcmp(ptr, "-v") == 0)
            {
                printf("When used with mkdir command,-v, displays complete details of the operation it's performing.\n");
            }

            ptr = strtok(NULL, delim);

            printf("Creating directory(ies)... %s", ptr);
        }
        else if (strcmp(ptr, "rmdir") == 0){

            printf("rmdir command is used remove empty directories from the filesystem. \n\n");

            ptr = strtok(NULL, delim);

            printf("Removing directory %s...", ptr);
        }
        else if (strcmp(ptr, "pwd") == 0){
            printf("The pwd command is a command line utility for printing the current working directory. It will print the full system path of the current working directory to standard output.\n");
        }
        else if (strcmp(ptr, "cd") == 0){
            printf("cd command is used to change the current directory (i.e., the directory in which the user is currently working)\n");

            ptr = strtok(NULL, delim);

            if (strcmp(ptr, "/") == 0)
            {
                printf("When used with cd command, / , it changes directory to the root directory, The root directory is the first directory in your filesystem hierarchy.\n");

            }
            else if(strcmp(ptr, "~") == 0)
            {
                printf("When used with cp command, ~ , it is used to change directory to the home directory.\n");
            }

        }
        else if (strcmp(ptr, "mv") == 0){

            printf("mv command is a command line utility that moves files or directories from one place to another. \n");

            ptr = strtok(NULL, delim);

            if (strcmp(ptr, "-i") == 0){
                printf("When used with mv command,-i , makes the command ask the user for confirmation before moving a file that would overwrite an existing file, you have to press y for confirm moving, any other key leaves the file as it is. This option doesn’t work if the file doesn’t exist, it simply rename it or move it to new location.\n");
                ptr = strtok(NULL, delim);
            }
            else if (strcmp(ptr, "-f") == 0){
                printf("When used with mv command, -f , it overrides the minor protection and overwrite the destination file forcefully and delete the source file.\n");
                ptr = strtok(NULL, delim);
            }
            else if (strcmp(ptr, "-n") == 0){
                printf("When used with mv command, -n , mv prevent an existing file from being overwritten.\n");
                ptr = strtok(NULL, delim);
            }

            else if (strcmp(ptr, "-b") == 0){
                printf("When used with mv command, -b , it becomes easier to take a backup of an existing file that will be overwritten as a result of the mv command. This will create a backup file with the tilde character(~) appended to it.\n");
                ptr = strtok(NULL, delim);
            }
            
        }
        else {
            printf("Invalid instruction passed\n");
            exit(-1);
        }

}
