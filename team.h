#ifndef TEAM_H
#define TEAM_H

#define MAX_TEAMS 50
#define MAX_MEMBERS 100

// Struct for a team
typedef struct {
  char name[50];
  char members[MAX_MEMBERS][50];
  int numMembers;
} Team;

extern Team teams[MAX_TEAMS];
extern int numTeams;

void addTeam();
void viewTeams();
void deleteTeam();

#endif
