/*
 *  linux/bootldr/commands.h
 *
 *  Copyright (C) 2003 Joshua Wise
 *  Bootloader port to Linux Kernel, May 07, 2003
 *
 *  cli for LAB
 */

struct lab_command;

struct lab_cmdlist {
  struct lab_command* command;
  struct lab_cmdlist* next;
};

struct lab_command {
  char* cmdname;
  void(*func)(int,const char**);
  char* help;
  struct lab_cmdlist* subcmd;
};

void lab_cmdinit(void);
void lab_addcommand(char* cmd, void(*func)(int,const char**), char* help);
void lab_addsubcommand(char* cmd, char* cmd2, void(*func)(int,const char**), char* help);
void lab_execcommand(int argc, char** argv);
