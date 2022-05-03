/*
** ETNA PROJECT, 2022
** RPG
** File description:
** rpg
*/

#ifndef RPG_H_
#define RPG_H_
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct Player {
    char *Cat;
    char strength;
    char health;
    char luck;
} Player_t;


typedef struct Enemy_s
{
    char *name;
    int strength;
    int health;
    int luck;
}Enemy_t;

typedef struct Boss_s
{
    char *name;
    int strength;
    int health;
    int luck;
}Boss_t;

#endif /* !RPG_H_ */
