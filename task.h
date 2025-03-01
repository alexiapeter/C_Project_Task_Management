/*************************************************/
/* task.h - Header file for module task          */
/* Copyright: 2022                               */
/* Author: Gansca Tudor                          */
/* Version: 15-12-2022                           */
/*************************************************/

#ifndef TASK_H
#define TASK_H

/* Headers required by the following definitions/declarations */
#include <stdlib.h>

/* Constants definitions: */
#define MAX_TASKS 100
#define MAX_MEMBERS 100

/* Types definitions: */

/* Global variables declarations: */
typedef struct {
  char name[50];
  char description[100];
  int team;
  char members[MAX_MEMBERS][50];
  int numMembers;
  int status;
  char deadline[20];
} Task;

extern Task tasks[MAX_TASKS];
extern int numTasks;

/* Function prototypes: */
void addTask();
void deleteTask();
void assignTeam();
void viewTask();
void moveTask();
#endif
