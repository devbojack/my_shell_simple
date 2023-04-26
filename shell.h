#ifndef _SHELL_H_
#define _SHELL_H_

/* Environ var */
extern char **environ;

/* Macros */
#define DELIM " \t\r\n\a"
#define PRINTER(c) (write(STDOUT_FILENO, c, str_len(c)))
#define BUFFERSIZE 1024

/* Libraries */
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/limits.h>

/* String functions */
unsigned int matcher(char ch, const char *str);
int str_compare(char *str1, char *str2);
int is_alphabet(int ch);
void rev_array(char *arr, int len);
int int_len(int numb);
char *string_tok(char *str, const char *lim);
int _putchar(char c);
char *str_copy(char *dest, char *src, int size);
int str_len(char *ch);
int _atoi(char *str);
char *_itoa(unsigned int n);
void _puts(char *str);
char *string_concat(char *dest, char *src);
char *string_copy(char *dest, char *src);
char *char_locator(char *str, char ch);
int string_compare(const char *s1, const char *s2, size_t n);
char *str_dup(char *str);

/* Memory functions */
void *re_alloc(void *ptr, unsigned int old_size, unsigned int new_size);
void *array_filler(void *ptr, int ptrx, unsigned int len);
char *mem_copy(char *dest, char *src, unsigned int size);
void free_environ(char **environ);
void *c_alloc(unsigned int size);
void freeler(char **input, char *line);

/* Input functions */
void prompt(void);
void signal_handler(int sign);
char *_getline(void);

/* Command parse */
int path_cmd(char **line);
char *get_environ(char *name);
char **parse_command(char *cmd);
int handle_builtin(char **cmd, int st);
void file_reader(char *filename, char **argv);
char *build(char *token, char *value);
int built_in_checker(char **cmd);
void create_environ(char **environ);
int cmd_checker(char **tokens, char *line, int count, char **argv);
void file_fixer(char *line, int counter, FILE *fd, char **argv);
void exit_bul_for_file(char **cmd, char *line, FILE *fd);

/* Built in functions */
void handle_hashtag(char *buff);
int history(char *input);
int display_history(char **cmd, int er);
int dis_env(char **cmd, int er);
int dir_changer(char **cmd, int state);
int display_help(char **cmd, int er);
int echo_bul(char **cmd, int er);
void b_exit(char **cmd, char *input, char **argv, int count);
int print_echo(char **cmd);

/* Error handle and Printer */
void print_number(unsigned int n);
void print_number_in(int n);
void print_error(char *line, int c, char **argv);
void pr_error(char **argv, int c, char **cmd);

/**
 * struct bulltin - contain bultin to handle and function to excute
 * @command:pointer to char
 * @fun:fun to excute when bultin true
 */
typedef struct  bulltin
{
	char *command;
	int (*fun)(char **line, int er);
} bul_t;

#endif
