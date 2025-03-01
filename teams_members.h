/**********************************************************/
/* teams_members.h - Header file for module teams_members */
/* Copyright: 2022                                        */
/* Author: Peter Alexia                                   */
/* Version: 15-12-2022                                    */
/**********************************************************/

#ifndef TEAMS_MEMBERS_H_INCLUDED
#define TEAMS_MEMBERS_H_INCLUDED

/* Headers required by the following definitions/declarations */
#include <stdlib.h>

/* Constants definitions: */
struct member
{
    char mbr_name[100];
    int mbr_age;
    int ok;
} matrix_mbr[21][21];

/* Types definitions: */

/* Global variables declarations: */

/* Function prototypes: */
void add_member(struct member matrix_mbr[][21], int, int );
void view_member(struct member matrix_mbr[][21], int, int );
void delete_member(struct member matrix_mbr[][21], int, int );
void view_team(struct member matrix_mbr[][21], int );
void delete_team(struct member matrix_mbr[][21], int );
void teams_menu();
void print_menu();

#endif // TEAMS_MEMBERS_H_INCLUDED
