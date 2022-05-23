#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <unistd.h>

int main()
{
    char c;
    int r = 0, g = 27, b = 255, dir_r = 1, dir_g = 1, dir_b = -1;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns, rows;



    SetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), 0b111);//Permette di usare correttamente gli escape codes ANSI anche sul terminale di Clion
    SetConsoleOutputCP(CP_UTF8); //Permette di usare i caratteri UTF-8 su windows

    printf("\033[?25l");

    do
    {
        if(r > 255 || r < 0)
            dir_r = -dir_r;
        if(g > 255 || g < 0)
            dir_g = -dir_g;
        if(b > 255 || b < 0)
            dir_b = -dir_b;

        printf("\033[1;0H");
        printf("\033[38;2;%d;%d;%dm\n", r, g, b);
        printf("░██████╗███████╗██╗░░██╗\n"
               "██╔════╝██╔════╝╚██╗██╔╝\n"
               "╚█████╗░█████╗░░░╚███╔╝░\n"
               "░╚═══██╗██╔══╝░░░██╔██╗░\n"
               "██████╔╝███████╗██╔╝╚██╗\n"
               "╚═════╝░╚══════╝╚═╝░░╚═╝");
        usleep(10000);

        r+=dir_r;
        g+=dir_g;
        b+=dir_b;
    }
    while(1);

    return 0;
}
