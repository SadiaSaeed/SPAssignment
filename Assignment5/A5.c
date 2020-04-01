#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <sys/stat.h>
 
enum Tnodetype {n_file, n_directory, n_symlink};
typedef enum Tnodetype Nodetype;
 
struct Tcell{
    struct Tcell *next;
    char * localname;
    char * fullname;
    struct Tcell * content;  // list of files in directory
    Nodetype nodetype;
};
typedef struct Tcell Cell, *List;
 
char * fullname(char *root, char * name)
{
    const char * sep = "/";
    char * res = (char *) malloc(strlen(root)+strlen(sep)+strlen(name)+1);
    strcpy(res,root);
    strcat(res,sep);
    strcat(res,name);
    return res;
}
 
int notdot (char * s)
{
    return  strcmp(s,".") != 0  && strcmp(s,"..")!= 0 ;
}
 
int issymlink(char * name)
{
    struct stat buf;
    lstat(name, &buf);
    return (buf.st_mode & S_IFMT) == S_IFLNK;
}
 
int isdir(char * name)
{
    struct stat buf;
    lstat(name, &buf);
    return (buf.st_mode & S_IFMT) == S_IFDIR;
}
 
List cons(List lp, char * fname, char * lname, Nodetype nodetype)
{ 
     List res = (List)malloc(sizeof(Cell)); 
     res->localname = strdup(lname);
     res->fullname = strdup(fname);
     res->content = NULL;
     res->nodetype = nodetype;
     res->next = lp;
     return res;
}
 
List add_symlink(List lp, char *path, char * name)
{
    Nodetype nodetype = n_symlink;
    return cons(lp, path, name, n_symlink);
}
 
List add_directory(List lp, char *path, char * name)
{
     Nodetype nodetype = n_directory;
     return cons(lp, path, name, n_directory); 
}
 
List add_file(List lp, char *path, char * name)
{
     Nodetype nodetype = n_file;
     return cons(lp, path, name, n_file);
}
 
List filecheck(List lp, char * dirname)
{
    DIR *dd;
    List dir = 0;
    struct dirent *dp;
    int res = 0;
    dd = opendir(dirname);
    assert(dd);
    while ((dp = readdir(dd)))
        if (notdot(dp->d_name)){
            char * name2 = fullname(dirname, dp->d_name);
            if (issymlink(name2))  
                 lp = add_symlink(lp, name2, dp->d_name);
            else if (isdir(name2)){
                 lp = add_directory(filecheck(lp,name2), name2, dp->d_name);
            }
            else
                 lp = add_file(lp, name2, dp->d_name);
        }
    closedir(dd);
    return lp;
}
 
void showtree (List lp)
{
     for ( ; lp ; lp = lp->next)
     printf("  %s - %s\n",lp->fullname);
}
 
int main(int argc, char * argv[]) {
    List lp = 0;
    char * dirname = strdup(( argc >1) ? argv[1] : getenv("HOME"));
    showtree(filecheck(lp, dirname));
    return (0);
}
