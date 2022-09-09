/* ======================================================================
File Name   :  shell.c
Authors     :  AnneMarie Sabatini, Ricardo Garza
Emails      :  AnnemarieSabatini@my.unt.edu, RicardoGarza3@my.unt.edu
Description :  This program implements a command line interpreter that
               works in both interactive and batch mode, incorporates
               built-in commands, includes I/O redirection and pipelining,
               and supports signal handling and terminal control.
====================================================================== */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>

/* function prototypes */
void executeInteractive(), executeCommand(char cmd[]), pwd(),
  cd(char *cmd), sigCatch(int sig), batchMode(char filename[]);
int iopipe(char *cmd); char* removeFront(char *token);

int main(int argc, char **argv)
{
  /* ======================================================================
  Function     :  main
  Parameters   :  int value, array of c-strings
  Return       :  int value
  Description  :  This function will determine if we run the program in
                  interactive or batch mode, and will output an error
                  message if the incorrect number of arguments are passed
                  from the command line.
  ====================================================================== */
  if (argc == 1) { executeInteractive(); }
  else if (argc == 2) { batchMode(argv[1]); }
  else { printf("\nusage: ./newshell [batchFile]\n\n"); }
  return 0;
}

void executeInteractive()
{
  /* ======================================================================
  Function     :  executeInteractive
  Parameters   :  none
  Return       :  none
  Description  :  This function will run an indefinite amount of commands
                  from the prompt.
  ====================================================================== */
  /* cmdCount keeps track of index for cmdHistory array */
  int cmdCount = 0;
  /* cmd and prompt are c-strings for user input */
  char cmd[1000], prompt[100];
  /* args splits up multiple commands on same line and cmdHistory keeps
  track of all the commands the user has run so far */
  char *args[150], *cmdHistory[150];

  /* this for loop sets all the cmdHistory elements to NULL */
  for(int k = 0; k < 150; k++) { cmdHistory[k] = NULL; }

  /* these watch out for the ctrl-C and ctrl-\ signals */
  if(signal(SIGINT, sigCatch) == SIG_ERR || signal(SIGQUIT, sigCatch) == SIG_ERR)
  { fprintf(stderr, "Error: signal handling failed.\n"); }

  /* these lines of code get custom prompt and remove newline */
  printf("\nCustomize prompt: "); fgets(prompt, 100, stdin);
  for(int i = 0; prompt[i] != '\0'; i++)
  { if(prompt[i] == '\n') { prompt[i] = '\0'; } }

  while(1) {
    /* exitPro is a boolean value that keeps track of if exit is called
    on the command line */
    int exitPro = 0;

    /* this for loop sets all the args elements to NULL */
    for(int k = 0; k < 150; k++) { args[k] = NULL; }

    /* this prints out the prompt and gets user input */
    printf("%s> ", prompt); fgets(cmd, 1000, stdin);

    /* if the cmd is a newline, continues loop */
    if(strcmp(cmd,"\n") == 0) { continue; }
    /* if ctrl-D is hit, will reopen stdin and continue loop */
    if(feof(stdin) == 1) { printf("\n"); freopen("/dev/tty", "r", stdin); continue; }

    /* argc keeps track of index we're at in args array, and this while loop tokenizes
    the given user input along a semicolon delimiter. we send token through removeFront
    and then store it in the cmdHistory, increment cmdCount, and store the token in args
    if it's not an empty string */
    int argc = 0; char *token = strtok(cmd,";");
    while (token) {
      token = removeFront(token);
      cmdHistory[cmdCount] = token; cmdCount++;
      if(strcmp(token,"") == 0) { }
      else { args[argc] = token; argc++; }
      token = strtok(NULL,";"); }

    /* this for loop will go through all the commands and flip the boolean exitPro to
    true if exit is a given command, call pwd() if pwd is entered, call iopipe if the
    command involves I/O redirection or pipelining, or cd() if cd is entered */
    for(int m = 0; args[m] != NULL; m++) {
      int execute = 1;
      //fflush(stdin);
      if (strcmp(args[m],"exit") == 0) { exitPro = 1; continue; }
      else if (strcmp(args[m],"pwd") == 0) { pwd(); }
      else {
        for(int n=0; args[m][n] != '\0'; n++) {
          if (args[m][n] == '|' || args[m][n] == '<' || args[m][n] == '>')
          { iopipe(args[m]); execute = 0; break; }
          if (args[m][n] == 'c' && args[m][n+1] == 'd')
          { cd(args[m]); execute = 0; break; } }
        if (execute) { executeCommand(args[m]); } } }

    /* this if statement, if executed, will print out the shell's command history
    and then exit the shell */
    if(exitPro) {
      printf("\n\nSHELL COMMAND HISTORY\n");
      for(int k=0; k < 150; k++) { if(cmdHistory[k] != NULL)
      { printf("command: %s\n", cmdHistory[k]); } }
      exit(0); }
  }
}

void executeCommand(char cmd[])
{
  /* ======================================================================
  Function     :  executeCommand
  Parameters   :  c-string
  Return       :  none
  Description  :  This function will execute a given command using execvp()
  ====================================================================== */
  /* declares array of strings and sets all elements to NULL */
  char *args[150]; for(int k=0; k < 150; k++) { args[k] = NULL; }
	pid_t pgid;
	pgid = getpgrp();
  /* this section of code tokenizes given command along space delimiter */
  int c = 0; char* token = strtok(cmd, " ");
  while (token) { args[c] = token; c++; token = strtok(NULL, " "); }

	tcsetpgrp(1, pgid);
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
  /* this section of code creates a child process in which the command is
  passed to execvp, and if it fails, will print out an error message and
  exit the child process. the parent process just waits for the child to
  finish */
  if(fork() == 0) {
    if(strcmp(cmd,"\n") == 0) { }
    else {
	for(int i=0; args[i]!=NULL; i++) {printf("Args[%d]: %s\n",i, args[i]);}
      execvp(args[0], args);
      for(int j=0; args[j] != NULL; j++) { printf("%s ", args[j]); }
      printf(": command not found\n"); exit(0); } }
  else { wait((int *)0); }
}

char* removeFront(char *token)
{
  /* ======================================================================
  Function     :  removeFront
  Parameters   :  c-string
  Return       :  c-string
  Description  :  This function will remove any unnecessary characters
                  from a given string.
  ====================================================================== */
  /* this section of code declares a dynamic c-string, finds out size of
  token, and resizes line to that size */
  char *line = (char *) malloc(sizeof(char));
  int i = 0; while(token[i] != '\0') { i++; }
  line = (char *)realloc(line, i-1);

  /* this for loop will go through token, and if the first index is not a space,
  will copy the token to line without adding the newline. if the first index is
  a space, moves up all the characters one space until reach a newline */
  for(int j = 0; j < i; j++) {
    if(token[0] != ' ') {
      if (token[j] == '\n') { break; }
      else { line[j] = token[j]; continue; } }
    else {
      if (token[j+1] == '\n') { }
      else { line[j] = token[j+1]; } } }

  return line;
}

void pwd()
{
  /* ======================================================================
  Function     :  pwd
  Parameters   :  none
  Return       :  none
  Description  :  This function will print out the current directory path.
  ====================================================================== */
  /* creates array to store the current working directory */
  char cwd[512];
  /* if the getcwd() system call executes, will print out cwd; otherwise
  will print out error message to terminal */
  if (getcwd(cwd, sizeof(cwd)) != NULL) { printf("%s\n", cwd); }
  else { perror("Error: getcwd() failed.\n"); }
}

void cd(char *cmd)
{
  /* ======================================================================
  Function     :  cd
  Parameters   :  c-string
  Return       :  none
  Description  :  This function will change our currrent directory to a
                  given target destination.
  ====================================================================== */
  /* creates 2-element array, one index to hold cd command and one index to
  hold the path if it's given */
  char *cmdv[] = {NULL, NULL};

  /* tokenizes cmd to get path if given */
  int c = 0; char* token = strtok(cmd, " ");
  while (token) { cmdv[c] = token; c++; token = strtok(NULL, " "); }

  /* if no path given, cd to HOME directory; otherwise, change directory
  to the given path destination */
  if (cmdv[1] == NULL) { chdir("/home"); } else { chdir(cmdv[1]); }
}

int iopipe(char *cmd)
{
  /* ======================================================================
  Function     :  iopipe
  Parameters   :  c-string
  Return       :  int value
  Description  :  This function will execute any command that requires
                  I/O redirection and/or pipelining.
  ====================================================================== */
  /* cmdCpy holds a copy of cmd, infile and outfile hold file names */
  char* cmdCpy; char* infile = "empty"; char* outfile = "empty";
  /* pipes keeps track of number of pipes, in and out are boolean values to
  keep track of whether or not we have input/output files */
  int pipes = 0, in = 0, out = 0;
  /* cmdv breaks up cmd to find infile and outfile; args, args2, and args3
  holds commands for each command between each pipe */
  char *cmdv[150], *args[150], *args2[150], *args3[150];

  /* initializes all array elements to NULL */
  for(int k=0; k < 150; k++)
  { cmdv[k] = NULL; args[k] = NULL; args2[k] = NULL; args3[k] = NULL; }

  /* copies cmd to cmdCpy */
  cmdCpy = strdup(cmd);

  /* tokenizes cmd */
  int c = 0; char* token = strtok(cmd, " ");
  while (token) { cmdv[c] = token; c++; token = strtok(NULL, " "); }

  /* goes through cmdv to find file names and how many pipes there are */
  for(int k=0; cmdv[k] != NULL; k++)
  {
    if(strcmp(cmdv[k],"|") == 0) { pipes++; }
    else if(strcmp(cmdv[k],"<") == 0)
    { infile = strdup(cmdv[k+1]); in = 1; cmdv[k+1] = NULL; k++; }
    else if(strcmp(cmdv[k],">") == 0)
    { outfile = strdup(cmdv[k+1]); out = 1; cmdv[k+1] = NULL; k++; }
  }

  /* if no pipes, just I/O redirection, execute this section of code */
  if(pipes == 0) {
    /* tokenizes cmdCpy and stores in args as long as not file name */
    int c = 0; char* token = strtok(cmdCpy, " < > ");
    while (token) {
      token = removeFront(token);
      if(strcmp(token,infile) == 0 || strcmp(token,outfile) == 0) { }
      else { args[c] = token; c++; }
      token = strtok(NULL, " < > "); }

    /* creates child process to execute I/O redirection command */
    if(fork() == 0) {
      /* creates objects of file stream */
      FILE *ifp, *ofp;

      /* if input file name was entered */
  		if(in)
      {
        /* open input file, if fails will return 0 */
        printf("attempting to open the file %s!!!\n", infile);
	//int ifp = open(infile, O_RDONLY);
	//if(ifp == -1) { printf("Error: cannot open file.\n"); }
	ifp = fopen(infile, "r");
        if(ifp == NULL) {
          printf("Error: Can't open input file.\n", infile);
          return 0; } // note: if do cd in batch before doing an iopipe, will fail since no longer in correct directory. make sure cd back into correct directory before accessing any files

        /* set instream from stdin to input file */
        dup2(fileno(ifp), 0); fclose(ifp);//fclose(ifp);
      }

      /* if output file was entered, created in write mode and outstream
      set from stdout to output file */
      if(out)
      { ofp = fopen(outfile, "w"); dup2(fileno(ofp), 1); fclose(ofp); }
	
      for(int i=0;args[i]!=NULL;i++) {printf("args[%d]: %s\n", i, args[i]);}
      /* runs command via execvp */
      execvp(args[0], args);

      /* if execvp fails, prints out error message and exits process */
      for(int j=0; args[j] != NULL; j++) { fprintf(stderr, "%s ", args[j]); }
      fprintf(stderr, ": command not found\n"); exit(0);

    } else { wait((int *)0); }
  }
  /* if there are pipes in the command */
  else if(pipes <= 2) {
    /* c, r, and g are index trackers for args, args2, and args3 respectively,
    while ac keeps track of which array we need to be storing in (args, args2,
    or args3, which depends on when we see the pipe command) */
    int status, c = 0, r = 0, g = 0, ac = 0;
    /* tokenizes cmdCpy along < and > delimiters and stores in arrays */
    char* token = strtok(cmdCpy, " < > ");
    while (token) { token = removeFront(token);
      if((in || out) && (strcmp(token,infile) == 0 || strcmp(token,outfile) == 0)) { }
      else if(strcmp(token,"|") == 0 || strcmp(token,"") == 0) { ac++; }
      else { if(ac == 0) { args[c] = token; c++; }
        else if(ac == 1) { args2[r] = token; r++; }
        else { args3[g] = token; g++; }
      } token = strtok(NULL, " < > "); }

    /* creates file descriptors and pipes them */
  	int fd1[2], fd2[2];
  	pipe(fd1); pipe(fd2);

    /* runs first command in the pipe */
  	if (fork() == 0) {
      /* creates file stream objects */
      FILE *ifp, *ofp;

      /* if input file exits, open it. if open fails, print error message and return
      0; otherwise set input stream from stdin to input file */
    	if(in) { ifp = fopen(infile, "r");
        if(ifp == NULL) { printf("Error: Can't open input file.\n"); return 0; }
        dup2(fileno(ifp), 0); fclose(ifp); }

      /* if output file entered, open and set output stream to output file */
      if(out) { ofp = fopen(outfile, "w"); dup2(fileno(ofp), 1); fclose(ofp); }

      /* duplicate write end of first command to stdout */
  		dup2(fd1[1], 1);
      /* close all file descriptors */
  		close(fd1[0]); close(fd1[1]); close(fd2[0]); close(fd2[1]);
      /* run first command */
      execvp(args[0], args);

      /* if execvp fails, print out error message and exit */
      for(int j=0; args[j] != NULL; j++) { fprintf(stderr, "%s ", args[j]); }
      fprintf(stderr, ": command not found\n"); exit(0); }
      /* parent process that will fork again to execute second command */
      else {
        /* if one or two pipes, forks again */
        if (pipes >= 1 && fork() == 0) {
          /* duplicate read end of args2 pipe to stdin */
  				dup2(fd1[0], 0);

          /* if two pipes, duplicate read end of args3 to stdout */
  				if (pipes == 2) { dup2(fd2[1], 1); }

          /* closes all file descriptors */
  				close(fd1[0]); close(fd1[1]); close(fd2[0]); close(fd2[1]);
          /* runs command */
  	  		execvp(args2[0], args2);

          /* if execvp fails, will print out error message and exit */
          for(int j=0; args2[j] != NULL; j++) { fprintf(stderr, "%s ", args2[j]); }
          fprintf(stderr, ": command not found\n"); exit(0); }
        /*  */
        else {
  	  		if (pipes == 2 && fork() == 0) {
  					dup2(fd2[0], 0);
  					close(fd1[0]); close(fd1[1]);
  					close(fd2[0]); close(fd2[1]);
            execvp(args3[0], args3);

            for(int j=0; args3[j] != NULL; j++)
            { fprintf(stderr, "%s ", args3[j]); }
            fprintf(stderr, ": command not found\n");
            exit(0);
          } else { wait((int *)0); } } }

  	close(fd1[0]); close(fd1[1]);
  	close(fd2[0]); close(fd2[1]);

    for (int i = 0; i < pipes; i++) { wait(&status); }
  }
  else { printf("This shell only supports up to two pipes.\n"); }

  return 1;
}

void sigCatch(int sig)
{
  /* ======================================================================
  Function     :  sigCatch
  Parameters   :  int value
  Return       :  none
  Description  :  This function handles the signal handling.
  ====================================================================== */
	executeCommand(" ");
}

// gotta comment for this one too, Check the return values of all functions utilizing system resources
void batchMode(char filename[])
{
  /* ======================================================================
  Function     :  batchMode
  Parameters   :  c-string
  Return       :  none
  Description  :  This function will execute the program in batch mode.
  ====================================================================== */
  FILE *ifp; char cmd[1000]; char *args[64];

	ifp = fopen(filename, "r");
	if(ifp == NULL) { printf("Batch file not found. Terminating shell.\n"); exit(0); }

	while(1) {
      int i = 0, exitPro = 0;
      for(i = 0; i < 64; i++) { args[i] = NULL; }
      for(i = 0; i < 1000; i++) { cmd[i] = '\0'; }

      if(fgets(cmd, 1000, ifp) == NULL) { exit(0); }
      else {
      printf("\ncommand(s): %s", cmd);

      for(int i = 0; cmd[i] != '\0'; i++) { if(cmd[i] == '\n') { cmd[i] = ' '; break; } }

  		if(strcmp(cmd, "\n") == 0) { continue; }
      if(cmd[513] != '\0') { printf("\nError: commands must be less than 512 bytes.\n"); continue; }

  		int argc = 0; char *token = strtok(cmd, ";");
  		while (token) {
  			token = removeFront(token);
  			if(strcmp(token,"") == 0) {}
  			else { args[argc] = token; argc++; }
  			token = strtok(NULL, ";"); }

  		for(int m = 0; args[m] != NULL; m++) {
  			int execute = 1;
  			if(strcmp(args[m], "exit") == 0) { exitPro = 1; continue; }
  			else if(strcmp(args[m], "pwd") == 0) { pwd(); }
  			else {
  				for(int n = 0; args[m][n] != '\0'; n++) {
  					if (args[m][n] == '|' ||
              args[m][n] == '<' || args[m][n] == '>')
            { iopipe(args[m]); execute = 0; break; }
  					if(args[m][n] == 'c' && args[m][n+1] == 'd')
            { cd(args[m]); execute = 0; break; } }
  				if(execute) { executeCommand(args[m]); } }
  		} if(exitPro){ exit(0); } } }
}
