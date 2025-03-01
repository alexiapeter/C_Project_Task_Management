#include <stdio.h>
#include <string.h>
#include "member.h"
#include "team.h"
#include "task.h"
#include "ui.h"


void addMember()
{
    char name[50];
    char team[50];
    int i;
    printf("Enter member name: ");
    scanf(" %[^\n]", name);
    printf("Enter team name: ");
    scanf(" %[^\n]", team);
    for (i = 0; i < numTeams; i++)
    {
        if (strcmp(teams[i].name, team) == 0)
        {
            if(checkAlreadyInTeam(name,i))
            {
                printf("Member already exists in the team!\n");
                next();
                return;
            }
            strcpy(teams[i].members[teams[i].numMembers], name);
            teams[i].numMembers++;
            return;
        }
    }
    for (i = 0; i < numTasks; i++)
    {
        if (strcmp(tasks[i].team, team) == 0)
        {

            strcpy(tasks[i].members[tasks[i].numMembers], name);
            tasks[i].numMembers++;
            return;
        }
    }
    printf("Error: Team not found.\n");
}

int checkAlreadyInTeam(char memberName[100],int teamIndex)
{
    for (int j = 0; j < teams[teamIndex].numMembers; j++)
        if (strcmp(teams[teamIndex].members[j], memberName) == 0)
            return 1;
    return 0;
}

void deleteMember()
{
    char memberName[50],teamName[50];
    int i, j;
    printf("Enter member name: ");
    scanf(" %[^\n]", memberName);
    printf("Enter team name: ");
    scanf(" %[^\n]", teamName);
    for (i = 0; i < numTeams; i++)
    {
        if (strcmp(teams[i].name, teamName) == 0)
        {
            for(j = 0; j < teams[i].numMembers; j++)
            {
                if(strcmp(teams[i].members[j],memberName)==0)
                {
                    for (int k = j; k < teams[i].numMembers - 1; k++)
                        strcpy(teams[i].members[k],teams[i].members[k+1]);
                    teams[i].numMembers--;
                    return;
                }
            }
        }
    }
}

