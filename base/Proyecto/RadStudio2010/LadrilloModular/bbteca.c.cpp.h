// bbteca.c.cpp.h
// Octulio Biletán - Agosto de 2020
// Biblioteca estándar de clases y funciones en C/C++ agrupadas en 'struct'
// Se utilizan tanto puntero a función como puntero a clase.
// Compatible con Embarcadero RAD Studio 10.2 y versiones posteriores.

#ifndef _BBTECA_H
#define _BBTECA_H

#include <_stddef.h>

#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <ctime>
#include <clocale>

#include <cprocess.h>
#include <cdir.h>
#include <conio.h>
#include <mem.h>

using namespace std;

struct _cstdio
{
    int (*printf)(const char *fmt, ...);
    int (*puts)(const char *txt);
    int (*putchar)(const int cc);
    int (*putc)(const int __c, FILE *__fp);

    int   (*scanf)(const char *fmt, ...);
    char* (*gets)(char * __s);
    int   (*getchar)(void);

    void  (*perror)(const char *txt);
    char* (*strerror)(int nerr);

    int   (*fclose)(FILE * __stream);
    FILE* (*fopen)(const char * __path, const char * __mode);
    int   (*getc)(FILE * __fp);
    int   (*fgetchar)(void);
    int   (*fgetc)(FILE * __stream);
    char* (*fgets)(char * __s, int __n, FILE * __stream);
    int   (*ungetc)(int __c, FILE * __stream);
    int   (*fputchar)(int __c);
    int   (*fputc)(int __c, FILE * __stream);
    int   (*fputs)(const char * __s, FILE * __stream);
    int   (*fscanf)(FILE * __stream, const char * __format, ...);
    int   (*fprintf)(FILE * __stream, const char * __format, ...);
    _SIZE_T (*fread)(void * __ptr, _SIZE_T __size, _SIZE_T __n, FILE * __stream);
    _SIZE_T (*fwrite)(const void * __ptr, _SIZE_T __size, _SIZE_T __n, FILE * __stream);
    int  (*fseek)(FILE * __stream, long __offset, int __whence);
    int  (*fseeki64)(FILE * __stream, __int64 __offset, int __whence);
    __int64 (*ftelli64)(FILE * __stream);
    int  (*fsetpos)(FILE * __stream, const fpos_t*__pos);
    long (*ftell)(FILE * __stream);
    int  (*flushall)(void);
    int  (*fflush)(FILE * __stream);
    int  (*fileno)(FILE * __fp);
    int  (*fcloseall)(void);
    int  (*feof)(FILE * __fp);
    int  (*ferror)(FILE * __fp);
    void (*rewind)(FILE * __stream);
    void (*clearerr)(FILE * __stream);

#if __BORLANDC__ > 0x621
    int (*sprintf)(char * __buffer, const char * __format, ...) __ATTRIB_FORMAT(printf, 2, 3);
#else
    int (*sprintf)(char * __buffer, const char * __format, ...);
#endif
    int (*sscanf)(const char * __buffer,  const char * __format, ...);
};

struct _conio
{
    int (*getch)(void);
    void (*clrscr)(void);
};

struct _mem
{
   void* (*memset)(void *s, int c, size_t n);
};

struct _cstring
{
   int (*strcmp)(const char *txt1, const char *txt2);
   char* (*strlwr)(char *__s);
   const char* (*strchr)(const char *__s, int __c);
   wchar_t*  (*wcscpy)(wchar_t *__dst, const wchar_t *__src);
};

struct _cstdlib
{
#if __BORLANDC__ > 0x621
    void _NO_RETURN_DECL (*exit)(int __status);
#else
    void (*exit)(int __status);
#endif
   char* (*getenv)(const char *__name);
   int (*putenv)(const char *__name);
};

struct _cctype
{
    int (*isdigit)(int __c);
};

struct _cprocess
{
    int (*system)(const char * __command);

    int (*spawnl)(int __mode, const char * __path, const char * __arg0, ...);
    int (*spawnle)(int __mode, const char * __path, const char * __arg0, ...);
    int (*spawnlp)(int __mode, const char * __path, const char * __arg0, ...);
    int (*spawnlpe)(int __mode, const char * __path, const char * __arg0, ...);
    int (*spawnv)(int modo, const char *trayectoria, char * const *argv);
    int (*spawnve)(int __mode, const char * __path, char * const * __argv, char * const * __env);
    int (*spawnvp)(int __mode, const char * __path, char * const * __argv);
    int (*spawnvpe)(int __mode, const char * __path, char * const * __argv, char * const * __env);

    int (*execl)(const char * __path, const char * __arg0, ...);
    int (*execle)(const char * __path, const char * __arg0, ...);
    int (*execlp)(const char * __path, const char * __arg0, ...);
    int (*execlpe)(const char * __path, const char * __arg0, ...);
    int (*execv)(const char * __path, char * const * __argv);
    int (*execve)(const char * __path, char * const * __argv, char * const * __env);
    int (*execvp)(const char * __path, char * const * __argv);
    int (*execvpe)(const char * __path, char * const * __argv, char * const * __env);

    int (*cwait)(int *_term_stat, int _pid, int _accion);
};

struct _cmath
{
    double (*pow)(double __x, double __y);
};

struct _ctime
{
    char* (*strtime)(char *__timestr);

};

struct _cdir
{
   int (*getcurdir)(int __drive, char *__directory);

};

struct _clocale
{
   char* (*setlocale)(int __category, const char *__locale);

};

#include <iostream>

struct _iostream
{
    ostream *cerr;
    ostream *cout;
    istream *cin;
};

#endif

