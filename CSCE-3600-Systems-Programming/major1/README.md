AUTHORS:  AnneMarie Sabatini |  Ricardo Garza
EMAILS:   AnnemarieSabatini@my.unt.edu | RicardoGarza3@my.unt.edu

##############################################################################

COMPILE:
  - type 'make' without quotation marks into terminal
RUN:
  - interactive: type 'make run'
  - batch: type './newshell [batchFile]' with batchFile being the name of
    the batch file to run
CLEAN:
  - type 'make clean' without quotation marks into terminal

##############################################################################

ORGANIZATION OF PROJECT

  - Because of the start delay waiting for the third member of the group who
    never showed up, the team decided to split up the code based on a few
    considerations. One was who had more time to focus on the code, and another
    consideration was our individual programming strengths. For the duration of
    the majority of the project, the team did not have the time to meet up during
    the school hours. The team mainly worked together remotely, although we met
    up for a solid stretch of time once during the weekend after the extension
    was given. The breakdown of the work is as follows:

      - RICARDO:
        Worked on the built-in commands pwd, cd, and exit. Implemented batch
        mode and handled the ctrl-D error. Edited README and Makefile. Also
        helped handle error checking for system resource calls.

      - ANNEMARIE:
        Set up the executeInteractive, executeCommand, iopipe, and removeFront
        functions. Set up signal handling to catch SIGINT and SIGQUIT. Created
        Makefile and README. Added comments to code and handled error checking
        for system resource calls. Completed the extra functionality including
        customizable prompt and command history.

______________________________________________________________________________

DESIGN OVERVIEW

  - The shell is designed to split in the main depending on whether it is
    being run in interactive or batch mode. In interactive, a while loop is
    used to continuously get and run user input until exit is entered. Batch
    mode is the exact same except that the input comes from a file and the while
    loop terminates at the end of the batch file. An important data structure that
    is used frequently throughout the shell is an array of char double pointers,
    i.e. an array that stores strings.

  - During the shell's execution, commands are taken in and, depending on what
    they are, call the built-in commands or run through execvp.

______________________________________________________________________________

COMPLETE SPECIFICATION

  - The team handled ambiguities in the specification by delimiting on the
    semicolon character. If the shell encounters lines that have no commands
    between semicolons, it will just continue in the loop. If the line is a
    newline, it continues the loop.

______________________________________________________________________________

KNOWN BUGS/PROBLEMS

  - ^D initiates an infinite loop if pressed after a ^C or ^\ (fixed)
  - in piping, won't store in output file, although it will run commands
  - now messing up multiple commands on same line if involves piping


** might need to change chdir home to /HOME when on cse machine
