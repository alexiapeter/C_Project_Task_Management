/*****************************************************************************/
/* Task management application                                               */
/* Copyright: 2023                                                           */
/* Author: Peter Alexia & Gânscă Tudor <Peter.Sa.Alexia@student.utclu.ro>    */
/*                                     <Gansca.Au.Tudor@student.utcluj.ro>   */
/* Version: 08/01/2023                                                       */
/*****************************************************************************/

/* Include standard headers: */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Include modules header that are direclty invoked: */
#include "task.h"
#include "ui.h"
#include "team.h"
#include "member.h"
#include "stats.h"
#include "teams_members.h"


int main()
{
  int choice;
  while (1) {
    printTasks();
    printTeams();
    printMenu();
    printf("Enter your choice: ");
    scanf("%d", &choice);
    char next;
    switch (choice) {
      case 1:
        addTask();
        break;
      case 2:
        moveTask();
        break;
      case 3:
        system("cls");
        printTasks();
        printTeams();
        viewTask();
        printTasks();
        printMenu();
        break;
      case 4:
        deleteTask();
        break;
      case 5:
        teams_menu();
        break;
      case 6:
        assignTeam();
        break;
      case 7:
        statsMenu();
        break;
      case 8:
        exit(1);
        break;
      default:
        printf("Invalid choice.\n");
        break;
    }
  }
  return 0;
}
