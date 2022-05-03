#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include "Players.h"
// #include "rpg.h"
// #include "Enemy.h"

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

//char toto()
//{
//    my_putstr(" _________             _________\n");
//    my_putstr("| -Attack |           |  -Heal  |\n");
//    my_putstr("|_________|           |_________|\n");
//    return 'c';
//}

char python()
{
    my_putstr("\n");
    my_putstr("                            __..._               \n");
    my_putstr("                        ..-'      o.             \n");
    my_putstr("                     .-'            :            \n");
    my_putstr("                 _..'             .'__..--<      \n");
    my_putstr("          ...--\"\"                 '-.            \n");
    my_putstr("      ..-\"                       __.'           \n");
    my_putstr("    .'                  ___...--'                \n");
    my_putstr("   :        ____....---'                         \n");
    my_putstr("  :       .'                                     \n");
    my_putstr(" :       :           _____                       \n");
    my_putstr(" :      :    _..--\"\"\"     \"\"\"--..__              \n");
    my_putstr(":       :  .\"                      \"\"i--.       \n");
    my_putstr(":       '.:                         :    '.      \n");
    my_putstr(":         '--...___i---\"\"\"\"--..___.'      :      \n");
    my_putstr(" :                 \"\"---...---\"\"          :      \n");
    my_putstr("  '.                                     :       \n");
    my_putstr("    '-.                                 :        \n");
    my_putstr("       '--...                         .'         \n");
    my_putstr("         :   \"\"---....._____.....---\"\"           \n");
    my_putstr("         '.    '.                                \n");
    my_putstr("           '-..  '.                              \n");
    my_putstr("               '.  :                             \n");
    my_putstr("                : .'                             \n");
    my_putstr("               /  :                              \n");
    my_putstr("             .'   :                              \n");
    my_putstr("           .' .--'                               \n");
    my_putstr("          '--'                                   \n");
    my_putstr("\n");
}

char shell()
{
    my_putstr("\n");
    my_putstr("            ___\n");
    my_putstr("        .-\"; ! ;\"-.\n");
    my_putstr("      .'!  : | :  !`.\n");
    my_putstr("     /\\  ! : ! : !  /\\\n");
    my_putstr("    /\\ |  ! :|: !  | /\\\n");
    my_putstr("   (  \\ \\ ; :!: ; / /  )\n");
    my_putstr("  ( `. \\ | !:|:! | / .' )\n");
    my_putstr("  (`. \\ \\ \\!:|:!/ / / .')\n");
    my_putstr("   \\ `.`.\\ |!|! |/,'.' /\n");
    my_putstr("    `._`.\\\\!!!// .'_.'\n");
    my_putstr("       `.`.\\|//.'.'\n");
    my_putstr("        |`._`n'_.'|     \n");
    my_putstr("        \"----^----\"\n");
    my_putstr("\n");
}

char sql()
{
    my_putstr("\n");
    my_putstr("      ____               \n");
    my_putstr("     /___/\\_                 \n");
    my_putstr("    _\\   \\/_/\\__             \n");
    my_putstr("  __\\       \\/_/\\            \n");
    my_putstr("  \\   __    __ \\ \\           \n");
    my_putstr(" __\\  \\_\\   \\_\\ \\ \\__     \n");
    my_putstr("/_/\\   __   __  \\ \\_/_/\\        \n");
    my_putstr("\\_\\/_\\__\\/\\__\\/\\__\\/_\\_\\/       \n");
    my_putstr("   \\_\\/_/\\       /_\\_\\/        \n");
    my_putstr("      \\_\\/       \\_\\/         \n");
    my_putstr("\n");
}

char s_boss()
{
    my_putstr("\n");
    my_putstr("\n");
    my_putstr("          .sd$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$; \n");
    my_putstr("        .d$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$       \n");
    my_putstr("      .d$$$$$$$$$$P*\"'   `\"*T$$$$$$$$$$$$$$$         \n");
    my_putstr("     s$$$$$$$$$P*             `*T$$$$$$$$$$$             \n");
    my_putstr("    d$$$$$$$$P'                  `*T$$$$$$$P             \n");
    my_putstr("   d$$$$$$$P'                       `T$$$$P              \n");
    my_putstr("  d$$$$$$P'                           `T$P \\             \n");
    my_putstr(" d$$$$$P'                                   \\            \n");
    my_putstr(".$$$$$'                 .*\"*                 .           \n");
    my_putstr(":$$$$;                  .*\"*-.                           \n");
    my_putstr("$$$$$'                 /                      `          \n");
    my_putstr("$$$$$.                  .s$$s.    `*.         :          \n");
    my_putstr("$$$$$;                 d$$$$$$b      ;     .s$s.         \n");
    my_putstr("$$$$$$b.              d$$$$$$$$b     ;    d$$$$$b        \n");
    my_putstr("$$$$$$$$$bs._        d$$$$P^^T$$b   /    d$P\"\"\"T$b       \n");
    my_putstr("$$$$$$$$$$$$$$bs+=- .$$P*'    `TP       dP     .`T       \n");
    my_putstr("$$$$$$$$$$$$$$$$P'  :P'    __          /                 \n");
    my_putstr("$$$$$$$$$$$$$$$P    $    .'  `.       /`-.    .          \n");
    my_putstr("T$$$$$$$$$$$$$$     :   /      \\     .    `.             \n");
    my_putstr(" T$$$$$$$$$$$$$        :        ;           \\.           \n");
    my_putstr("  T*'   `*^$$$$        |+*\"$P*sss*\"  :*\"$P*ss*\"          \n");
    my_putstr(" /         `T$$        |   Tbd$P     :  Tbd$P            \n");
    my_putstr(";  ._        T$        |    T$$P     :   T$P      _._    \n");
    my_putstr("     `\"*+.    T       *\"**--._/       \\   /`. .-*\"   `*. \n");
    my_putstr("     .*'  `.                  `*       `*---*'          ; \n");
    my_putstr("    (                              `.                   | \n");
    my_putstr("                   .'                \\                  ; \n");
    my_putstr("\\           /     /`*+...___          `-.             .*  \n");
    my_putstr(" `-._   _.+'          `*. __\"\"\"****------`*-.____.+*\"'   \n");
    my_putstr("     \"*\"   \\             `. \"\"\"****------**\"/;           \n");
    my_putstr("            `.         \\   `--..._______...'/            \n");
    my_putstr("              `*--..___.`.                 /             \n");
    my_putstr("                          `*-...______..-*'              \n");
    my_putstr("\n");
}

char ts()
{
    my_putstr("\n");
    my_putstr("        ,----,            \n");
    my_putstr("      ,/   .`|            \n");
    my_putstr("    ,`   .'  : .--.--.    \n");
    my_putstr("  ;    ;     //  /    '.  \n");
    my_putstr(".'___,/    ,'|  :  /`. /  \n");
    my_putstr("|    :     | ;  |  |--`   \n");
    my_putstr(";    |.';  ; |  :  ;_     \n");
    my_putstr("`----'  |  |  \\  \\    `.  \n");
    my_putstr("    '   :  ;   `----.   \\ \n");
    my_putstr("    |   |  '   __ \\  \\  | \n");
    my_putstr("    '   :  |  /  /`--'  / \n");
    my_putstr("    ;   |.'  '--'.     /  \n");
    my_putstr("    '---'      `--'---'   \n");
    my_putstr("\n");
}

int main()
{
    s_boss();
    // welcome();
    // select();
    // char *start;
    // start = (char *)malloc(5);
    // my_putstr("\n Voulez-vous plonger dans la partie : y/n ?\n");
    // start = my_readline();
}