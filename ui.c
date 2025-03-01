/***********************************************************/
/* ui.c - See ui.h for copyright and info                  */
/***********************************************************/

/* System headers and application specific headers: */
#include <stdio.h>
#include <string.h>
#include "task.h"
#include "ui.h"
#include "team.h"
#include "member.h"
#include "stats.h"
#include "teams_members.h"

/* Private constants: */

/* Private types: */

/* Private global variables: */

/* Public global variables: */

/* Implementation of the private functions: */

/* Implementation of the public functions: */

/********************************************************************/
/* FUNCTION NAME: printTasks                                        */
/* DESCRIPTION: prints the tasks on 3 columns based on their status */
/* ARGUMENT LIST: no arguments                                      */
/* CHANGES: -                                                       */
/********************************************************************/
void printTasks()
{
    system("cls");
    printf("Task Management App\n");
    printf("************************************************\n");
    printf("*     To do     |     Doing     |     Done     *\n");
    for(int i=0; i<numTasks; i++)
    {
        int l=strlen(tasks[i].name);
        l=16-l;
        if(tasks[i].status == 0)
        {
            printf("*");
            for(int i=1; i<=l/2; i++)
                printf(" ");
            printf("%s",tasks[i].name);
            if(l%2==0)
                l--;
            for(int i=1; i<=l/2; i++)
                printf(" ");
            printf("|               |              *\n");
        }
        if(tasks[i].status == 1)
        {
            printf("*               |");
            for(int i=1; i<=l/2; i++)
                printf(" ");
            printf("%s",tasks[i].name);
            if(l%2==0)
                l--;
            for(int i=1; i<=l/2; i++)
                printf(" ");
            printf("|              *\n");
        }
        if(tasks[i].status == 2)
        {
            printf("*               |               |");
            for(int i=1; i<=l/2; i++)
                printf(" ");
            printf("%s",tasks[i].name);
            if(l%2==0)
                l--;
            for(int i=1; i<l/2; i++)
                printf(" ");
            printf("*\n");
        }
    }
    printf("************************************************\n");
}

/********************************************************************/
/* FUNCTION NAME: printTeams                                        */
/* DESCRIPTION: prints the teams with their members                 */
/* ARGUMENT LIST: no arguments                                      */
/* CHANGES: -                                                       */
/********************************************************************/
void printTeams()
{
    printf("                      Teams:\n");
    printf("------------------------------------------------\n");
    int checkTeamList=0;
    for(int i=1;i<=20;i++)
        if(matrix_mbr[i][0].ok==1)
            checkTeamList=1;
    if(checkTeamList==0)
        printf("There are no teams.\n");
    for(int i = 1; i <= 20; i++)
    {
        if(matrix_mbr[i][0].ok==1){
            printf("Team %d with the members :\n", i);
            for(int j=1;j<=20;j++)
                if(matrix_mbr[i][j].mbr_age>1)
                    printf("%s(%d) ",matrix_mbr[i][j].mbr_name,matrix_mbr[i][j].mbr_age);
            printf("\n\n");
        }
    }
    printf("------------------------------------------------\n");
}

/********************************************************************/
/* FUNCTION NAME: printMenu                                         */
/* DESCRIPTION: prints the menu with the options                    */
/* ARGUMENT LIST: no arguments                                      */
/* CHANGES: -                                                       */
/********************************************************************/
void printMenu()
{
    printf("1. Add task\n");
    printf("2. Move task\n");
    printf("3. View task\n");
    printf("4. Delete task\n");
    printf("5. Teams and members\n");
    printf("6. Assign team\n");
    printf("7. Statistics\n");
    printf("8. Exit\n");
}

/********************************************************************/
/* FUNCTION NAME: next                                              */
/* DESCRIPTION: allows you to go back by entering any key           */
/* ARGUMENT LIST: no arguments                                      */
/* CHANGES: -                                                       */
/********************************************************************/
void next()
{
    char next;
    printf("Enter any key to go back: ");
    scanf(" %c",&next);
    system("cls");
}

/********************************************************************/
/* FUNCTION NAME: statsMenu                                         */
/* DESCRIPTION: allows you to go back by entering any key           */
/* ARGUMENT LIST: no arguments                                      */
/* CHANGES: -                                                       */
/********************************************************************/
void statsMenu(){
    system("cls");
    printf("Task management app statistics: \n\n");
    printf("Total members: %d\n",totalMembers());
    printf("Completed tasks: %d\n",completedTasks());
    printf("Uncompleted tasks: %d\n",uncompletedTasks());
    mostUrgentTask();
}

