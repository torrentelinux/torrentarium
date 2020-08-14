// bbteca.c.cpp.h
// Biblioteca estándar de clases y funciones en C/C++ agrupadas en 'struct'
// Se utilizan tanto puntero a función como puntero a clase.

#include <_stddef.h>

struct _cstdio
{
    int (*printf)(const char *fmt, ...);
    int (*puts)(const char *txt);
    int (*putchar)(const int cc);

    int (*scanf)(const char *fmt, ...);

    void (*perror)(const char *txt);
    char* (*strerror)(int nerr);
};

struct _conio
{
    int (*getch)(void);
};

struct _mem
{
   void* (*memset)(void *s, int c, size_t n);
};

struct _cstring
{
   int (*strcmp)(const char *txt1, const char *txt2);
};

struct _cstdlib
{
    void (*exit)(int e);
};

struct _process
{
    int (*spawnv)(int modo, const char *trayectoria, char * const *argv);
    int (*cwait)(int *_term_stat, int _pid, int _accion);
};

#include <iostream>

struct _iostream
{
    ostream *cerr;
    ostream *cout;
    istream *cin;
};

