/***********************************************************/
/* stats.c - See stats.h for copyright and info            */
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
/* FUNCTION NAME: totalMembers                                      */
/* DESCRIPTION: adds up all the members from all teams              */
/* ARGUMENT LIST: no arguments                                      */
/* RETURN VALUE: int number of members                              */
/* CHANGES: -                                                       */
/********************************************************************/
int totalMembers()
{
    int total = 0;
    for(int i = 1; i <= 20 ; i++)
        for(int j=1;j<=20;j++)
            if(matrix_mbr[i][j].mbr_age > 0) total++;
    return total;
}

/********************************************************************/
/* FUNCTION NAME: completedTasks                                    */
/* DESCRIPTION: adds up all the completed tasks                     */
/* ARGUMENT LIST: no arguments                                      */
/* RETURN VALUE: int number of completed tasks                      */
/* CHANGES: -                                                       */
/********************************************************************/
int completedTasks()
{
    int total = 0;
    for(int i = 0; i < numTasks ; i++)
        if(tasks[i].status==2)
            total++;
    return total;
}

/********************************************************************/
/* FUNCTION NAME: uncompletedTasks                                  */
/* DESCRIPTION: adds up all the uncompleted tasks                   */
/* ARGUMENT LIST: no arguments                                      */
/* RETURN VALUE: int number of uncompleted tasks                    */
/* CHANGES: -                                                       */
/********************************************************************/
int uncompletedTasks()
{
    int total = 0;
    for(int i = 0; i < numTasks ; i++)
        if(tasks[i].status==1 || tasks[i].status==0)
            total++;
    return total;
}

/********************************************************************/
/* FUNCTION NAME: mostUrgentTask                                    */
/* DESCRIPTION: find the tasks with the earliest deadline           */
/* ARGUMENT LIST: no arguments                                      */
/* CHANGES: -                                                       */
/********************************************************************/
void mostUrgentTask()
{
    char urgentTask[50],year[10],month[10],day[10];
    int yMin,mMin,dMin,y,d,m;
    strcpy(urgentTask,tasks[0].name);
    day[0]=tasks[0].deadline[0];
    day[1]=tasks[0].deadline[1];
    month[0]=tasks[0].deadline[3];
    month[1]=tasks[0].deadline[4];
    year[0]=tasks[0].deadline[6];
    year[1]=tasks[0].deadline[7];
    year[2]=tasks[0].deadline[8];
    year[3]=tasks[0].deadline[9];
    yMin = atoi(year);
    mMin = atoi(month);
    dMin = atoi(day);
    for(int i=1; i<numTasks; i++)
    {
        day[0]=tasks[i].deadline[0];
        day[1]=tasks[i].deadline[1];
        month[0]=tasks[i].deadline[3];
        month[1]=tasks[i].deadline[4];
        year[0]=tasks[i].deadline[6];
        year[1]=tasks[i].deadline[7];
        year[2]=tasks[i].deadline[8];
        year[3]=tasks[i].deadline[9];
        y = atoi(year);
        m = atoi(month);
        d = atoi(day);
        if(y<yMin)strcpy(urgentTask,tasks[i].name);
        else if(m<mMin)strcpy(urgentTask,tasks[i].name);
        else if(d<dMin)strcpy(urgentTask,tasks[i].name);
    }

    printf("Most urgent task: %s\n\n",urgentTask);
    next();
}
