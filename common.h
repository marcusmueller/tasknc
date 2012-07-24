/*
 * common.h
 * for tasknc
 * by mjheagle
 */

#ifndef _COMMON_H
#define _COMMON_H

/* action definitions */
typedef enum {
	ACTION_EDIT = 0,
	ACTION_COMPLETE,
	ACTION_DELETE,
	ACTION_VIEW
} task_action_type;

/* ncurses settings */
typedef enum {
	NCURSES_MODE_STD = 0,
	NCURSES_MODE_STD_BLOCKING,
	NCURSES_MODE_STRING
} ncurses_mode;

/* var struct management */
typedef enum {
	VAR_UNDEF = 0,
	VAR_CHAR,
	VAR_STR,
	VAR_INT
} var_type;

typedef struct _task
{
	unsigned short index;
	char *uuid;
	char *tags;
	unsigned int start;
	unsigned int end;
	unsigned int entry;
	unsigned int due;
	char *project;
	char priority;
	char *description;
	struct _task *prev;
	struct _task *next;
} task;

typedef struct _var
{
	char *name;
	var_type type;
	void *ptr;
} var;

typedef struct _funcmap
{
	char *name;
	void (*function)();
	int argn;
} funcmap;

typedef struct _bind
{
	int key;
	void (*function)();
	int argint;
	char *argstr;
	struct _bind *next;
} keybind;

/* log levels */
typedef enum {
	LOG_DEFAULT = 0,
	LOG_INFO,
	LOG_WARN,
	LOG_ERROR,
	LOG_DEBUG,
	LOG_DEBUG_VERBOSE
} log_mode;

/* runtime config */
typedef struct _config {
	int nc_timeout;
	int statusbar_timeout;
	log_mode loglvl;
	char *version;
	char sortmode;
	char silent_shell;
} config;

#endif