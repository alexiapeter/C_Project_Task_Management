/***********************************************************/
/* task.c - See task.h for copyright and info              */
/***********************************************************/

/* System headers and application specific headers: */
#include <stdio.h>
#include <string.h>
#include "task.h"
#include "team.h"
#include "ui.h"
#include "stats.h"
#include "teams_members.h"

/* Private constants: */

/* Private types: */

/* Private global variables: */

/* Public global variables: */
int numTasks = 0;
Task tasks[MAX_TASKS];

/* Implementation of the private functions: */

/* Implementation of the public functions: */

/********************************************************************/
/* FUNCTION NAME: addTask                                           */
/* DESCRIPTION: adds a task to the list of tasks                    */
/* ARGUMENT LIST: no arguments                                      */
/* CHANGES: -                                                       */
/********************************************************************/
void addTask()
{
    if (numTasks == MAX_TASKS)
    {
        printf("Error: Maximum number of tasks reached.\n");
        return;
    }
    printf("Enter task name: ");
    scanf(" %[^\n]", &tasks[numTasks].name);
    printf("Enter task description: ");
    scanf(" %[^\n]", &tasks[numTasks].description);
    printf("Enter task deadline(dd/mm/yyyy): ");
    scanf(" %[^\n]", &tasks[numTasks].deadline);
    tasks[numTasks].numMembers = 0;
    tasks[numTasks].status = 0;
    numTasks++;
}

/********************************************************************/
/* FUNCTION NAME: deletesTask                                       */
/* DESCRIPTION: deletes a task from the list of tasks               */
/* ARGUMENT LIST: no arguments                                      */
/* CHANGES: -                                                       */
/********************************************************************/
void deleteTask()
{
    char taskName[50];
    int taskIndex;
    printf("Enter task name: ");
    scanf(" %[^\n]", taskName);
    // Find the task to delete
    taskIndex = -1;
    for (int i = 0; i < numTasks; i++)
    {
        if (strcmp(tasks[i].name, taskName) == 0)
        {
            taskIndex = i;
            break;
        }
    }

    if (taskIndex == -1)
    {
        printf("Error: Task not found.\n");
        return;
    }

    // Shift tasks down in the array to overwrite the task to delete
    for (int i = taskIndex; i < numTasks - 1; i++)
    {
        tasks[i] = tasks[i+1];
    }
    numTasks--;
}

/********************************************************************/
/* FUNCTION NAME: assignTeam                                        */
/* DESCRIPTION: assigns a team to a certain task                    */
/* ARGUMENT LIST: no arguments                                      */
/* CHANGES: -                                                       */
/********************************************************************/
void assignTeam()
{
    char taskName[50];
    int teamID;
    int taskIndex, teamIndex;
    printf("Enter task name: ");
    scanf(" %[^\n]", &taskName);
    printf("Enter team ID from the following: ");
    for(int i=1; i<=20; i++)
        if(matrix_mbr[i][0].ok)
            printf("%d ",i);
    printf("\n");
    scanf("%d", &teamID);
    taskIndex = -1;
    for (int i = 0; i < numTasks; i++)
    {
        if (strcmp(tasks[i].name, taskName) == 0)
        {
            taskIndex = i;
            break;
        }
    }
    if (taskIndex == -1)
    {
        printf("Error: Task not found.\n");
        return;
    }
    if (teamIndex == -1)
    {
        printf("Error: Team not found.\n");
        return;
    }
    tasks[taskIndex].team = teamID;
}

/********************************************************************/
/* FUNCTION NAME: moveTask                                          */
/* DESCRIPTION: changes the status of a give task                   */
/* ARGUMENT LIST: no arguments                                      */
/* CHANGES: -                                                       */
/********************************************************************/
void moveTask()
{
    printf("Enter the name of the task you want to move : ");
    char nameToMove[50];
    scanf(" %[^\n]", &nameToMove);
    for(int i = 0; i < numTasks; i++)
    {
        if (strcmp(tasks[i].name, nameToMove) == 0 && tasks[i].status <= 1)
            tasks[i].status++;
        else
            printf("Can't change task status!\n");
    }
}

/********************************************************************/
/* FUNCTION NAME: viewTask                                          */
/* DESCRIPTION: displays the information of a task                  */
/* ARGUMENT LIST: no arguments                                      */
/* CHANGES: -                                                       */
/********************************************************************/
void viewTask()
{
    printf("Enter the name of the task you want to see: ");
    char nameToSee[50];
    scanf(" %[^\n]", &nameToSee);
    for(int i = 0; i < numTasks; i++)
    {
        if (strcmp(tasks[i].name, nameToSee) == 0)
        {
            printf("Task data: \nDescription: %s\nDeadline: %s\n",tasks[i].description,tasks[i].deadline);
            printf("Assigned team: ");
            if(!tasks[i].team)
                printf("No team assigned!\n");
            else
                printf("%d\n",tasks[i].team);
            next();
        }
    }
}
