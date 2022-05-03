/*
** ETNA PROJECT, 2022
** RPG
** Andrea, Styven, Amélie
** File description:
** RPG en C
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Players.h"
#include "rpg.h"
#include "Enemy.h"

char *my_readline(void)
{
  char *buff;
  ssize_t size;

  buff = malloc(sizeof(*buff) * (50 + 1));
  if (buff == NULL)
    return NULL;
  size = read(0, buff, 50);
  if (size > 1)
  {
    buff[size - 1] = '\0';
    return buff;
  }
  free(buff);
  return NULL;
}

int myAtoi(char *str)
{
  // Initialize result
  int res = 0;

  // Iterate through all characters
  // of input string and update result
  // take ASCII character of corresponding digit and
  // subtract the code from '0' to get numerical
  // value and multiply res by 10 to shuffle
  // digits left to update running total
  for (int i = 0; str[i] != '\0'; ++i)
    res = res * 10 + str[i] - '0';

  // return result.
  return res;
}

int my_strlen(const char *str)
{
  int i;
  i = 0;

  while (str[i] != '\0')
  {
    i++;
  }
  return (i);
}

void my_putchar(char c)
{
  write(1, &c, 1);
}

void my_putstr(const char *str)
{
  for (int i = 0; str[i] != '\0'; i++)
  {
    my_putchar(str[i]);
  }
}

char *my_strdup(const char *src)
{
  int i = 0;

  char *dest;
  dest = malloc(sizeof(char) * my_strlen(src) + 1);
  while (src[i] != '\0')
  {
    dest[i] = src[i];
    i++;
  }
  dest[i] = '\0';
  return (dest);
}

char welcome()
{
    my_putstr("\n");
    my_putstr(" ____  _                                            _                  \n");
    my_putstr("|  _ \\(_)                                          | |                 \n");
    my_putstr("| |_) |_  ___ _ ____   _____ _ __  _   _  ___    __| | __ _ _ __  ___  \n");
    my_putstr("|  _ <| |/ _ \\ '_ \\ \\ / / _ \\ '_ \\| | | |/ _ \\  / _` |/ _` | '_ \\/ __| \n");
    my_putstr("| |_) | |  __/ | | \\ V /  __/ | | | |_| |  __/ | (_| | (_| | | | \\__ \\ \n");
    my_putstr("|____/|_|\\___|_| |_|\\_/ \\___|_| |_|\\__,_|\\___|  \\__,_|\\__,_|_| |_|___/ \n");
    my_putstr("              _                                  _       \n");
    my_putstr("             | |                                | |      \n");
    my_putstr("             | | ___   _ __ ___   ___  _ __   __| | ___  \n");
    my_putstr("             | |/ _ \\ | '_ ` _ \\ / _ \\| '_ \\ / _` |/ _ \\ \n"); //
    my_putstr("             | |  __/ | | | | | | (_) | | | | (_| |  __/ \n");
    my_putstr("             |_|\\___| |_| |_| |_|\\___/|_| |_|\\__,_|\\___|\n");
    my_putstr("           __            _            _   _\n");
    my_putstr("          / _|          | |          | | (_)\n");
    my_putstr("         | |_ __ _ _ __ | |_ __ _ ___| |_ _  __ _ _   _  ___ \n");
    my_putstr("         |  _/ _` | '_ \\| __/ _` / __| __| |/ _` | | | |/ _ \\\n");
    my_putstr("         | || (_| | | | | || (_| \\__ \\ |_| | (_| | |_| |  __/\n");
    my_putstr("         |_| \\__,_|_| |_|\\__\\__,_|___/\\__|_|\\__, |\\__,_|\\___|\n");
    my_putstr("                                               | |           \n");
    my_putstr("                                               |_|            \n");
    my_putstr("                                     _      \n");
    my_putstr("                                    | |     \n");
    my_putstr("                                  __| | ___ \n");
    my_putstr("                                 / _` |/ _ \\\n");
    my_putstr("                                | (_| |  __/\n");
    my_putstr("                                 \\__,_|\\___|\n");
    my_putstr("\n");
    my_putstr("          _____                   _______                  _______                   _____  \n");
    my_putstr("         /\\    \\                 /::\\    \\                /::\\    \\                 /\\    \\ \n");
    my_putstr("        /::\\    \\               /::::\\    \\              /::::\\    \\               /::\\____\\\n");
    my_putstr("       /::::\\    \\             /::::::\\    \\            /::::::\\    \\             /:::/    /\n");
    my_putstr("      /::::::\\    \\           /::::::::\\    \\          /::::::::\\    \\           /:::/    / \n");
    my_putstr("     /:::/\\:::\\    \\         /:::/~~\\:::\\    \\        /:::/~~\\:::\\    \\         /:::/    /  \n");
    my_putstr("    /:::/__\\:::\\    \\       /:::/    \\:::\\    \\      /:::/    \\:::\\    \\       /:::/    /   \n");
    my_putstr("   /::::\\   \\:::\\    \\     /:::/    / \\:::\\    \\    /:::/    / \\:::\\    \\     /:::/    /    \n");
    my_putstr("  /::::::\\   \\:::\\    \\   /:::/____/   \\:::\\____\\  /:::/____/   \\:::\\____\\   /:::/    /     \n");
    my_putstr(" /:::/\\:::\\   \\:::\\____\\ |:::|    |     |:::|    ||:::|    |     |:::|    | /:::/    /      \n");
    my_putstr("/:::/  \\:::\\   \\:::|    ||:::|____|     |:::|    ||:::|____|     |:::|    |/:::/____/       \n");
    my_putstr("\\::/    \\:::\\  /:::|____| \\:::\\    \\   /:::/    /  \\:::\\    \\   /:::/    / \\:::\\    \\       \n");
    my_putstr(" \\/_____/\\:::\\/:::/    /   \\:::\\    \\ /:::/    /    \\:::\\    \\ /:::/    /   \\:::\\    \\      \n");
    my_putstr("          \\::::::/    /     \\:::\\    /:::/    /      \\:::\\    /:::/    /     \\:::\\    \\     \n");
    my_putstr("           \\::::/    /       \\:::\\__/:::/    /        \\:::\\__/:::/    /       \\:::\\    \\    \n");
    my_putstr("            \\::/____/         \\::::::::/    /          \\::::::::/    /         \\:::\\    \\   \n");
    my_putstr("             ~~                \\::::::/    /            \\::::::/    /           \\:::\\    \\  \n");
    my_putstr("                                \\::::/    /              \\::::/    /             \\:::\\    \\ \n");
    my_putstr("                                 \\::/____/                \\::/____/               \\:::\\____\\\n");
    my_putstr("                                  ~~                       ~~                      \\::/    /\n");
    my_putstr("                                                                                    \\/____/ \n");
    my_putstr("                                                                                            \n");
    my_putstr("\n");
}

void start_game()
{
  char *name = malloc(sizeof(char) * my_strlen(name) + 1);
  int i = 0;

  my_putstr("\n");
  my_putstr("Bienvenue dans le monde fantastique de POOL !\n\n");
  my_putstr("Vous incarnez un canard qui doit parcourir le monde merveilleux de POOL et affronter diverses épreuves afin de pouvoir accéder au merveilleux jour du barbecue !\n");
  my_putstr("quel est le nom de votre canard ? : \n");
  my_putstr("->");
  name = my_readline();
  my_putstr("Welcome canard ");
  my_putstr(name);
  my_putstr(" !\nVous allez également devoir définir votre class, vous avez le choix entre :\n");

  for (i = 0; i < 4; i++)
  {
    my_putstr(Class_Cat[i]);
    my_putstr(", health:");
    my_putstr(Class_health[i]);
    my_putstr(", strentgh:");
    my_putstr(Class_strength[i]);
    my_putstr(", luck:");
    my_putstr(Class_luck[i]);
    my_putstr("\n");
  }
}

char choix_playeur()
{
  char *cat = (char *)malloc(10);
  my_putstr(" \nQuelle catégorie de canard choissisez vous?\n");
  cat = my_readline();

  while (*cat != *"archer" || *cat != *"warrior" || *cat != *"doctor" || *cat != *"mum")
  {
    if (*cat == *"archer")
    {
      my_putstr("\nVous avez choisi le canard ");
      my_putstr(Class_Cat[0]);
      my_putstr(" avec ");
      my_putstr(Class_strength[0]);
      my_putstr(" points de force et ");
      my_putstr(Class_health[0]);
      my_putstr(" points de vie. Votre pourcentage de chances dans la vie est de ");
      my_putstr(Class_luck[0]);
      my_putstr(" %. Bonne chance!\n");
      break;
    }
    else if (*cat == *"warrior")
    {
      my_putstr("\nVous avez choisi le canard ");
      my_putstr(Class_Cat[1]);
      my_putstr(" avec ");
      my_putstr(Class_strength[1]);
      my_putstr(" points de force et ");
      my_putstr(Class_health[1]);
      my_putstr(" points de vie. Votre pourcentage de chances dans la vie est de ");
      my_putstr(Class_luck[1]);
      my_putstr(" %. Bonne chance!\n");
      break;
    }
    else if (*cat == *"doctor")
    {
      my_putstr("\nVous avez choisi le canard ");
      my_putstr(Class_Cat[2]);
      my_putstr(" avec ");
      my_putstr(Class_strength[2]);
      my_putstr(" points de force et ");
      my_putstr(Class_health[2]);
      my_putstr(" points de vie. Votre pourcentage de chances dans la vie est de ");
      my_putstr(Class_luck[2]);
      my_putstr(" %. Bonne chance!\n");
      break;
    }
    else if (*cat == *"mum")
    {
      my_putstr("\nVous avez choisi le canard ");
      my_putstr(Class_Cat[3]);
      my_putstr(" avec ");
      my_putstr(Class_strength[3]);
      my_putstr(" points de force et ");
      my_putstr(Class_health[3]);
      my_putstr(" points de vie. Votre pourcentage de chances dans la vie est de ");
      my_putstr(Class_luck[3]);
      my_putstr(" %. Bonne chance!\n");
      break;
    }
    else
    {
      cat = my_readline();
    }
  }
}

void in_game()
{

  char *choix = (char *)malloc(10);

  my_putstr("\nVous êtes arrivé à l'ETNA, vous devez vous rendre dans l'open space afin de récupérer votre livre de quête.\n");
  my_putstr("Vous arrivez dans l open space et vous trouvez un livre appellé Gates Of Hyrule, voulez vous ouvrir le livre ? y/n \n");
  my_putstr("->");
  choix = my_readline();

  while (*choix != 'y' || *choix != 'n')
  {

    if (*choix == 'y')
    {
      break;
    }
    else if (*choix == 'n')
    {
      break;
    }
    else
    {
      my_putstr("->");
      choix = my_readline();
    }
  }

  my_putstr("\nHo non un shell, c'est un ennemi de bas niveau mais faites attention !\nVous pouvez choisir d'attaquer ou de vous soigner avec les commandes :\n- Attack\n- Heal\n\n");
  
  char select()
{
    my_putstr(" _________             _________\n");
    my_putstr("| -Attack |           |  -Heal  |\n");
    my_putstr("|_________|           |_________|\n");
}
  int player_pdv = 10;
  int mob_pdv = 5;

  while (mob_pdv > 0 || player_pdv > 0)
  {
    my_putstr("->");
    choix = my_readline();

    if (*choix == *"Attack")
    {
      my_putstr("Vous lancer un coup de bec à votre ennemi, il perd 5 pdv\n");
      mob_pdv -= 5;
      my_putstr("Shell vous attaque avec un coup de man, vous perdez 5 pdv\n");
      player_pdv -= 5;
    }

    if (*choix == *"Heal")
    {
      my_putstr("Vous invoquez un Bubble Tea, vous récupérez 5 pdv\n");
      player_pdv += 5;
      my_putstr("Shell vous attaque avec un coup de man, vous perdez 5 pdv\n");
      player_pdv -= 5;
    }

    if (player_pdv == 0)
    {
      my_putstr("You Lose\n");
      break;
    }

    if (mob_pdv == 0)
    {
      my_putstr("Vous avez vaincu Shell ! Vous recevez le livre Gates of Hyrule.\n\n");
      break;
    }
  }

  my_putstr("Souhaitez vous ouvrir le livre ? y/n\n");
  my_putstr("->");
  choix = my_readline();

  while (*choix != 'y' || *choix != 'n')
  {

    if (*choix == 'y')
    {
      my_putstr("Une fée apparaît.\nLa fée : Bonjour, je suis Linda, je suis ton guide dans cette quête.\n");
      break;
    }
    else if (*choix == 'n')
    {
      my_putstr("Le livre s'agite comme enerver, une fée apparaît.\n La fée (en colère) : Mais ! Pourquoi ne m'as tu pas ouvert T_T, je suis linda ton guide pour cette quête !!!\n");
      break;
    }
    else
    {
      my_putstr("->");
      choix = my_readline();
    }
  }

  my_putstr("Tu va devoir récupérer 5 objets sacrés, dont mon livre, afin d'accéder jour magique du BARBECUE *.*\n Acceptes tu la quête afin de pouvoir manger des brochettes ?\n");
  my_putstr("->");
  my_readline();
  my_putstr("\n");
  my_putstr("Linda : Ton avis m'importe peu finalement, tu as payé alors tu dois faire cette quête :p.\n\n");
  my_putstr("Linda : Ta prochaine étape est d'affronter un monstre du nom de Typescript. Tu récupérera son objet sacrée. Fais attention à toi et Bonne chance =)\n");
  my_putstr("Tu te diriges donc vers la salle suivante afin d'affronter Typescript, mais ...\n\n");
  my_putstr("Un MYSQL sauvage apparaît sans prévenir !!!\n\n");

  mob_pdv = 10;
  mob_pdv = 5;

  while (mob_pdv > 0 || player_pdv > 0)

  {
    my_putstr("->");
    choix = my_readline();
    my_putstr("\n");

    if (*choix == *"Attack")
    {
      my_putstr("MYSQL vous attaque avec un coup de INNER JOIN, vous perdez 5 pdv\n");
      player_pdv -= 5;
      my_putstr("Vous lancez un coup de bec à votre ennemie, il perd 5 pdv\n");
      mob_pdv -= 5;
    }

    if (*choix == *"Heal")
    {
      my_putstr("Shell vous attaque avec un INNER JOIN, vous perdez 5 pdv\n");
      player_pdv -= 5;
      my_putstr("Vous invoquez un Bubble Tea, vous récupérez 5 pdv\n");
      player_pdv += 5;
    }

    if (player_pdv == 0)
    {
      my_putstr("You Lose\n");
      break;
    }

    if (mob_pdv == 0)
    {
      my_putstr("Vous avez vaincu MYSQL ! Vous recevez un pokedex.\n\n");
      break;
    }
  }
  my_putstr("Félicitation ! Tu vas enfin pouvoir te diriger vers Typescript.\n\n Toujours sur le chemin vers le monstre, vous tombez sur un coffre.\nSouhaitez vous l'ouvrir ? y/n\n");
  while (*choix != 'y' || *choix != 'n')
  {

    if (*choix == 'y')
    {
      my_putstr("Vous obtenez un stickers ! Et encore un objet sacré dans la poche\n\n");
      break;
    }
    else if (*choix == 'n')
    {
      my_putstr("BOOM !!!\nle coffre explose en laissant s'échapper un stickers, heureusement que la chance vous sourie, c'est un objet sacré !\n\n");
      break;
    }
    else
    {
      my_putstr("->");
      choix = my_readline();
    }
  }
}

int main(void)
{
  welcome();
  start_game();
  choix_playeur();
  in_game();
  return (0);
}