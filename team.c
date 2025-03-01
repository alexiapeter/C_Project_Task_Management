#include <stdlib.h>
#include <string.h>
#include "task.h"
#include "ui.h"
#include "team.h"
#include "member.h"


Team teams[MAX_TEAMS];
int numTeams = 0;

// Add a team
void addTeam()
{
    if (numTeams == MAX_TEAMS)
    {
        printf("Error: Maximum number of teams reached.\n");
        return;
    }
    printf("Enter team name: ");
    scanf(" %[^\n]", &teams[numTeams].name);
    teams[numTeams].numMembers = 0;
    numTeams++;
}

void deleteTeam()
{
    char teamName[50];
    int i, j;
    printf("Enter team name: ");
    scanf(" %[^\n]", teamName);
    for (i = 0; i < numTeams; i++){
        if (strcmp(teams[i].name, teamName) == 0){
            for (j = i; j < numTeams - 1; j++)
                teams[j] = teams[j+1];
            numTeams--;
            return;
        }
    }
    for(int i=0; i<numTasks; i++)
        if(strcmp(tasks[i].team,teamName)==0)strcpy(tasks[i].team, "No team assigned!\n");
    printf("Error: Team not found.\n");
}
