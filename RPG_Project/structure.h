#include "rpg.h"

int main(int argc, char **argv)
{
  struct s_Playeurs archer;
  archer.Class_name = "Archer";
  archer.strength = 60;
  archer.health = 40;

  struct s_Playeurs Warrior;
  Warrior.Class_name = "Warrior";
  Warrior.strength = 70;
  Warrior.health = 40;

  struct s_Playeurs Doctor;
  Doctor.Class_name = "Doctor";
  Doctor.strength = 20;
  Doctor.health = 125;

  struct s_Playeurs Mum;
  Mum.Class_name = "Mum";
  Mum.strength = 80;
  Mum.health = 30;
}