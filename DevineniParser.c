/*Devineni, Sai Dheeraj --- devinenis7463@uhcl.edu ----- ID:1595002-------*/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main ()
{
    char ch='c';

    while(ch!='q')
    {
        char cmd[100];
        char lv;
        printf("Dheeraj--> ");
   printf("Enter the executable commands with only spaces delimited: ");
   scanf("%[^\n]s",cmd);
   printf("Entered the executable commands %s: ",cmd);

   int i=0,k=0,temp=0,j=0,l=0,f=0,z=0,u=0,no=0,imp=0;
   int notable[10];
   const char s[2] = " ";
   char *token;
  char *notes[25];
  char *first[10][10];

int   fd[2];
  pid_t pid;
  int   tk_in = 0;


token = strtok(cmd, s);

   /* Split the given commands using space delimited*/
   while( token != NULL )
   {
   notes[i]=(char *)malloc(strlen(token)*sizeof(char));

      strcpy(notes[i],token);
       token = strtok(NULL, s);
     i++;
     }


     notes[i]='\0';
     if(notes[i]!='\0')
     printf("values %d\n",i);

/* Split the given commands into individual cmd groups by using pipe and null as delimiter*/

       for(j=0;j<=i;j++)
     {


          if(notes[j]=='\0')
         {
                first[k][l]=(char *)malloc(1*sizeof(char));
            strcpy(first[k][l],"\0");
            //first[k][l]='\0';
             temp=1;
             notable[no]=l;
             no++;
         }
          else if((strcmp(notes[j],"|") == 0))
         {
                first[k][l]=(char *)malloc(1*sizeof(char));
            strcpy(first[k][l],"\0");
            //first[k][l]="\0";
             temp=1;
             notable[no]=l;
             no++;
         }
         else
         {
            first[k][l]=(char *)malloc(strlen(notes[j])*sizeof(char));
            strcpy(first[k][l],notes[j]);
         }

         puts(first[k][l]);
         l++;


         if(temp == 1)
         {
             k++;
             l=0;
             temp=0;
         }
     }

/*To add null char at the each end of array group*/

 for(u=0;u<k;u++)
 {
        first[u][notable[u]]='\0';
 }

/*Fork implementation starts here by storing input into one variable tk_in*/

 while (imp<k)
    {
      pipe(fd);
      if ((pid = fork()) == -1)
        {

        exit(1);
}
      else if (pid == 0)
        {
          dup2(tk_in, 0); 

          if (imp!=k-1)
            dup2(fd[1], 1);
          close(fd[0]);
          execvp(first[imp][0],first[imp]);
         // exit(1);
        }
      else
        {
          wait(NULL);
          close(fd[1]);
          tk_in = fd[0]; 
          imp++;
        }
    }

/*Freeing the spaces allocated*/

for(f=0;f<=i;f++)
        free(notes[f]);

for(z=0;z<k;z++)
        {
        for(j=0;j<l;j++)
        {
        free(first[z][j]);
        }
        }


 printf("Enter q to quit or enter any other letter to continue");
        scanf(" %c",&ch);

        lv=getchar();
}

return 0;
}

