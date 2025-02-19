//ESTE PROGRAMA TRAE LA FUNCION KBHIT() A LINUX. SIRVE PARA SABER CUANDO EL USUARIO INTERACTUó CON EL TECLADO
//SE IMPLEMENTARá PARA INTERRUMPIR ALGORITMOS DE LUCES E INCREMENTAR VELOCIDAD DE BARRIDO SIN DETENER EL BUCLE
#include "kbhit.h"
#include <termios.h>
#include <unistd.h>   // for read()

static struct termios initial_settings, new_settings;
static int peek_character = -1;

void init_keyboard() //SE DEBE ENTRAR AL MODO CANONICO Y DESHABILITAR EL ECHO
{
    tcgetattr(0,&initial_settings);
    new_settings = initial_settings;
    new_settings.c_lflag &= ~ICANON;
    new_settings.c_lflag &= ~ECHO;
    new_settings.c_lflag &= ~ISIG;
    new_settings.c_cc[VMIN] = 1;
    new_settings.c_cc[VTIME] = 0;
    tcsetattr(0, TCSANOW, &new_settings);
    tcflush(0,TCIFLUSH);
}

void close_keyboard()
{
    tcsetattr(0, TCSANOW, &initial_settings);
}
int kbhit()
{
unsigned char ch;
int nread;

    if (peek_character != -1) return 1;
    new_settings.c_cc[VMIN]=0;
    tcsetattr(0, TCSANOW, &new_settings);
    nread = read(0,&ch,1);
    new_settings.c_cc[VMIN]=1;
    tcsetattr(0, TCSANOW, &new_settings);
    if(nread == 1) 
    {
        peek_character = ch;
        return 1;
    }
    return 0;
}

int readch()
{
char ch;

    if(peek_character != -1) 
    {
        ch = peek_character;
        peek_character = -1;
        return ch;
    }
    read(0,&ch,1);
    return ch;
}
