/**************************************************************/
/* team_members.c - See team_members.h for copyright and info */
/**************************************************************/

/* System headers and application specific headers: */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "task.h"
#include "ui.h"
#include "teams_members.h"
/* Private constants: */

/* Private types: */

/* Private global variables: */

/* Public global variables: */

/* Implementation of the private functions: */

/* Implementation of the public functions: */

/********************************************************************/
/* FUNCTION NAME: add_member                                        */
/* DESCRIPTION: adds a member in a team                             */
/* ARGUMENT LIST:                                                   */
/* Argument               Type       IO      Description            */
/* __________________ ______________ __ __________________________  */
/* struct member[][]    matrix_mbr   I   matrix of teams and members*/
/* int                     i         I   team id                    */
/* int                     j         I   member id                  */
/* RETURN VALUE : void                                              */
/* CHANGES: -                                                       */
/********************************************************************/
void add_member(struct member matrix_mbr[][21], int i, int j)
{
    printf("\n Enter the member's name: ");
    scanf(" %[^\n]", &matrix_mbr[i][j].mbr_name);
    printf("\n Enter the member's age: ");
    scanf("%d", &matrix_mbr[i][j].mbr_age );
    matrix_mbr[i][j].ok=1;
    printf("Member successfully added!\n");
}

/********************************************************************/
/* FUNCTION NAME: view_member                                       */
/* DESCRIPTION: displays informations about a member from a team    */
/* ARGUMENT LIST:                                                   */
/* Argument               Type       IO      Description            */
/* __________________ ______________ __ __________________________  */
/* struct member[][]    matrix_mbr   I   matrix of teams and members*/
/* int                     i         I   team id                    */
/* int                     j         I   member id                  */
/* RETURN VALUE : void                                              */
/* CHANGES: -                                                       */
/********************************************************************/
void view_member(struct member matrix_mbr[][21], int i, int j)
{
    printf("\nMember id: %d\n", j);
    printf("The member's name: %s\n", matrix_mbr[i][j].mbr_name );
    printf("The member's age: %d\n", matrix_mbr[i][j].mbr_age);
}

/********************************************************************/
/* FUNCTION NAME: delete_member                                     */
/* DESCRIPTION: deletes a member from a team                        */
/* ARGUMENT LIST:                                                   */
/* Argument               Type       IO      Description            */
/* __________________ ______________ __ __________________________  */
/* struct member[][]    matrix_mbr   I   matrix of teams and members*/
/* int                     i         I   team id                    */
/* int                     j         I   member id                  */
/* RETURN VALUE : void                                              */
/* CHANGES: -                                                       */
/********************************************************************/
void delete_member(struct member matrix_mbr[][21], int i, int j)
{
    matrix_mbr[i][j].ok=0;
    matrix_mbr[i][j].mbr_age=0;
    printf("The member %d from team %d has been deleted! That space is free now. Choose option 1 to add a new member!", j,i);
}

/********************************************************************/
/* FUNCTION NAME: delete_team                                       */
/* DESCRIPTION: delets a team                                       */
/* ARGUMENT LIST:                                                   */
/* Argument               Type       IO      Description            */
/* __________________ ______________ __ __________________________  */
/* struct member[][]    matrix_mbr   I   matrix of teams and members*/
/* int                     i         I   team id                    */
/* RETURN VALUE : void                                              */
/* CHANGES: -                                                       */
/********************************************************************/
void delete_team(struct member matrix_mbr[][21], int i)
{
    for(int k=0; k<=10; k++)
        matrix_mbr[i][k].ok=0;
}

/********************************************************************/
/* FUNCTION NAME: teams_menu                                        */
/* DESCRIPTION: allows the user to manage teams and members db      */
/* ARGUMENT LIST:                                                   */
/* RETURN VALUE : void                                              */
/* CHANGES: -                                                       */
/********************************************************************/
void teams_menu()
{
    system("cls");
    print_menu();
    int option;
    scanf("%d", &option);
    while(option != 6 )
    {
        system("cls");
        print_menu();
        switch (option)
        {
        case 1:
            printf("You chose option 1: Add member.\n");
            printf("\n");
            printf("Enter the team number: \n");
            int id_mbr_team, id_mbr_list;
            scanf("%d", &id_mbr_team);
            if(matrix_mbr[id_mbr_team][0].ok==0)
            {
                printf("Team does not exist!\n");
                enter();
                break;
            }
            else if(id_mbr_team<1 || id_mbr_team >20)
            {
                printf("Team ID must be between 1 and 20!\n");
                enter();
                break;
            }
            printf("Enter the member's number: \n");
            scanf("%d", &id_mbr_list);
            if(matrix_mbr[id_mbr_team][id_mbr_list].ok==1)
            {
                printf("Member already exists!\n");
                enter();
                break;
            }
            else if(id_mbr_list<1 || id_mbr_list >20)
            {
                printf("Member ID must be between 1 and 20!\n");
                enter();
                break;
            }
            add_member(matrix_mbr, id_mbr_team, id_mbr_list);
            enter();
            break;

        case 2:
            printf("You chose option 2: View member.\n");
            printf("Enter the id of the team: ");
            int id_team;
            scanf("%d",&id_team);
            if(matrix_mbr[id_team][0].ok==0)
            {
                printf("Team does not exists!\n");
                enter();
                break;
            }
            else if(id_team<1 || id_team >20)
            {
                printf("Team ID must be between 1 and 20!\n");
                enter();
                break;
            }
            printf("Team %d members:\n",id_team);
            for(int j=1; j<=20; j++)
                if(matrix_mbr[id_team][j].mbr_age>1)
                    printf("%d ",j);
            printf("\nEnter the ID of the member you want to see: \n");
            int id_member;
            scanf("%d",&id_member);
            view_member(matrix_mbr, id_team, id_member);
            enter();
            break;

        case 3:
            printf("You chose option 3: Delete member.\n");
            printf("What member would you like to delete?\n");
            printf("Enter the team number: \n");
            scanf("%d", &id_team);
            if(matrix_mbr[id_team][0].ok==0)
            {
                printf("Team does not exists!\n");
                enter();
                break;
            }
            else if(id_team<1 || id_team >20)
            {
                printf("Team ID must be between 1 and 20!\n");
                enter();
                break;
            }
            for(int j=1; j<=20; j++)
                if(matrix_mbr[id_team][j].mbr_age>1)
                    printf("%d ",j);
            printf("\nEnter the ID of the member you want to delete: \n");
            scanf("%d",&id_member);
            delete_member(matrix_mbr, id_team, id_member);
            break;

        case 4:
            printf("You chose option 4: Add team.");
            printf("\n Enter the team number: ");
            int check;
            scanf("%d", &check);
            if(matrix_mbr[check][0].ok==1)
            {
                printf("Team already exists!\n");
                enter();
                break;
            }
            else if(check<1 || check >20)
            {
                printf("Team ID must be between 1 and 20!\n");
                enter();
                break;
            }
            else
                printf("Team %d successfully added!\n", check);
            matrix_mbr[check][0].ok=1;
            enter();
            break;

        case 5:
            printf("You chose option 5: Delete team.");
            printf("\n Enter the team number you want to delete: ");
            scanf("%d", &check);
            if(check<1 || check >20)
            {
                printf("Team ID must be between 1 and 20!\n");
                enter();
                break;
            }
            else
                for(int j=0; j<=20; j++)
                    matrix_mbr[check][j].ok=0;
            printf("Team %d successfully deleted!\n", check);
            enter();
            break;
        }
        printf("\n\t Enter another option: \n");
        scanf("%d", &option);
    }
}

/********************************************************************/
/* FUNCTION NAME: print_menu                                        */
/* DESCRIPTION: displays the available commands                     */
/* ARGUMENT LIST:                                                   */
/* RETURN VALUE : void                                              */
/* CHANGES: -                                                       */
/********************************************************************/
void print_menu()
{
    printf("Choose an option:\n");

    printf("1. Add member \n");
    printf("2. View member \n");
    printf("3. Delete member \n");
    printf("4. Add team \n");
    printf("5. Delete team  \n");
    printf("6. Go back  \n");
}

/********************************************************************/
/* FUNCTION NAME: enter                                             */
/* DESCRIPTION: allows the user to return                           */
/* ARGUMENT LIST:                                                   */
/* RETURN VALUE : void                                              */
/* CHANGES: -                                                       */
/********************************************************************/
void enter()
{
    char next;
    printf("Enter any key to go back: ");
    scanf(" %c",&next);
}
