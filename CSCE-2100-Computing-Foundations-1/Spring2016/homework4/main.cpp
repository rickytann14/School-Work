/// \file main.cpp

/// \mainpage Ransack and Run
///
/// Ransack and Run is a very short text adventure game
/// in which the player's task is to loot the castle
/// and carry everything back outside. There are
/// two NPCs to deal with along the way. Commands consist of
/// two words, a command word followed by (when appropriate) an item.
/// A list of commands can obtained by typing the command "help".
///
/// The items in each room and the collection of items carried by
/// the player are implemented as linked lists. Program 4 for
/// Ian Parberry's CSCE 2100 class at the University of North Texas
/// in Fall 2016 is to implement the missing code in Linkedlist.cpp.
/// You must not alter any other files.
///
/// Class members can obtain the source code from the CSE machines
/// by cd-ing to ~ian/csce2100/program4/blank. Copy all of the
/// files there to one of your own subdirectories.

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "LinkedList.h"
#include "defines.h"

const int BUFSIZE = 256; ///< Buffer size.
char g_cCmdBuffer[BUFSIZE]; ///< Command buffer.
char g_cItemBuffer[BUFSIZE]; ///< Item buffer.

LinkedList roomContents[NUM_ROOMS]; ///< List of items in each room.
eNPC roomNPC[NUM_ROOMS]; ///< The NPC in each room.

/// \brief Initialize game.
/// Put the items and NPCs in the correct places.

void initialize(){
  roomContents[OUTSIDE_ROOM].Insert(FROG_ITEM);
  roomContents[DRAGON_ROOM].Insert(COIN_ITEM);
  roomContents[THRONE_ROOM].Insert(AXE_ITEM);
  roomContents[DWARF_ROOM].Insert(SWORD_ITEM);
  roomContents[DWARF_ROOM].Insert(JEWEL_ITEM);

  roomNPC[DRAGON_ROOM] = DRAGON_NPC;
  roomNPC[DWARF_ROOM] = DWARF_NPC;
} //initialize

/// \brief Check whether character is a vowel.
/// \param c [IN] A character.
/// \return True if c is an upper or lower case vowel.

bool isVowel(const char c){
  switch(c){
    case 'a': case 'e': case 'i': case 'o': case 'u':
    case 'A': case 'E': case 'I': case 'O': case 'U':
      return true;
    default:
      return false;
  } //switch
} //isVowel

/// \brief Print an item with the correct article ("a" or "an").
/// Given a string, this function prints it to stdout after
/// the correct article ("a" or "an", depending on whether the
/// article starts with a vowel.
/// \param s [IN] Zero-terminated string containing the name of an item.

void printWithArticle(const char* s){
  if(isVowel(s[0]))
    printf("an %s", s);
  else printf("a %s", s);
} //printWithArticle

/// \brief Print a list of items.
/// Print a list of game items to stdout, separated by commas.
/// The last item has the word "and" prepended. An Oxford
/// comma is used unless there are only two items in the list.
/// Member variable L.m_pCurrent is changed as a side-effect.
/// \param L [IN][OUT] Linked list of items.

void printItemList(LinkedList& L){
  if(!L.isEmpty()){ //do nothing for empty list
    int n; //item number
    L.Head(); L.Get(n); printWithArticle(itemToString[eItem(n)]); //print head of list
    for(L.Next(); L.Get(n); L.Next()){ //print tail of list
      if(L.Last()) //last item in list might get an "and" in front of it
        if(L.Length() == 2)printf(" and "); //two items in list, no Oxford comma
        else printf(", and "); //Oxford comma
      else printf(", "); //other comma separator
      printWithArticle(itemToString[eItem(n)]);
    } //for
  } //if
} //printItemList

/// \brief Read command and item from stdin.
/// Read a command from stdin with the associated item, if the command has one.
/// \param s [OUT] Command string.
/// \param t [OUT] Item string.

void readCommand(char* s, char* t){
  char c; //temporary character
  int i; //temporary index
  
  printf("> "); //prompt

  //get command string
  for(c = getchar(), i=0; i<BUFSIZE-1 && c!=' ' && c!='\n'; c = getchar())
    s[i++] = c;
  s[i] = '\0'; //null terminator
  
  //get item string
  if(c == ' ')
    for(c = getchar(), i=0; i<BUFSIZE-1 && c!='\n'; c = getchar())
      t[i++] = c;
  else i = 0;
  t[i] = '\0'; //null terminator

   //skip to end of line
  while(c != '\n')
    c = getchar();
} //readCommand

/// \brief Parse command and item strings.
/// Parse a command string with the item string, if the command has one.
/// \param s [IN] Command string.
/// \param t [IN] Item string.
/// \param command [OUT] Command number.
/// \param item [OUT] Item number.
/// \return true for success, false for failure.

bool parseCommand(const char* s, const char* t, eCommand& command, eItem& item){
  bool found = false;
  int i;

  //parse command
  for(i=0; i<NUM_COMMANDS && !found; i++)
    found = strcmp(s, ((char*)commandToString[i])) == 0;
  if(found)command = (eCommand)(i - 1);
  
  //parse item
  bool found2 = true;
  if(found){
    if(strlen(t) == 0)
      item = NONE_ITEM;
    else{ 
      found2 = false;
      for(i=0; i<NUM_ITEMS && !found2; i++)
        found2 = strcmp(t, ((char*)itemToString[i])) == 0;
      item = found2? (eItem)(i - 1): NONE_ITEM;
    } //else
  } //if

  return found && found2;
} //parseCommand

/// \brief Print the doors in a room.
/// Print a list of doors to stdout, separated by commas.
/// The last door has the word "and" prepended. An Oxford
/// comma is used unless there are only two doors in the list.
/// \param r [IN] The room to describe doors of.

void printDoors(const eRoom r){
  int count = 0; //number of doors

  //count the number of doors
  for(int i=0; i<NUM_DIRS; i++) //for each direction
    if(nextRoom[r][i] != NOT_A_ROOM)
      count++;

  //print beginning of statement
  if(count == 1)
    printf("There is a door");
  else printf("There are doors");

  //describe the doors
  int j=0; //number of doors found
  for(int i=0; i<NUM_DIRS; i++)//for each direction
    if(nextRoom[r][i] != NOT_A_ROOM)
      if(++j == count)
        if(count == 1)printf(" %s.\n", directionToString[i]);
        else printf(" and %s.\n", directionToString[i]);
      else if(count == 2)printf(" %s", directionToString[i]);
      else printf(" %s,", directionToString[i]);
} //printDoors

/// \brief Print room description.
/// Print a description of a room to stdout, including what
/// room it is, what doors lead out of it, what items are there,
/// and what NPC is present.
/// \param r [IN] The room to describe.

void printRoomDescription(const eRoom r){
  printf("You are %s\n", roomToString[r]); //room description

  printDoors(r); //doors out of room

  //items in room
  if(!roomContents[r].isEmpty()){
    printf("There is ");
    printItemList(roomContents[r]);
    printf(" here.\n");
  } //if
  
  //NPCs in room
  if(roomNPC[r] != NO_NPC){
    printf("There is ");
    printWithArticle(npcToString[roomNPC[r]]);
    printf(" here.\n");
  } //if
} //printRoomDescription

/// \brief Print inventory list.
/// Print to stdout a list of the items that the played is carrying.
/// Member variable L.m_pCurrent is changed as a side-effect.
/// \param L [IN][OUT] Linked list of items in inventory.

void printInventory(LinkedList& L){
  if(!L.isEmpty()){ //do nothing for empty list.
    printf("You are carrying ");
    printItemList(L); //where the actual work gets done
    printf(".\n");
  } //if
} //printInventory

/// \brief Print command list.
/// Print to stdout a list of the possible commands.

void printCommands(){
  printf("Commands are:\n");
  printf("  get item\n");
  printf("  drop item\n");
  printf("  left\n");
  printf("  right\n");
  printf("  forwards\n");
  printf("  back\n");
  printf("  inventory\n");
  printf("  look\n");
  printf("  help\n");
  printf("  quit\n");
} //printCommands

/// \brief Perform a command.
/// \param cmd [IN] Command number.
/// \param item [IN] Item associated with command.
/// \param room [IN][OUT] Current room.
/// \param justArrived [IN][OUT] Whether newly arrived in current room.
/// \param myStuff [IN][OUT] List of items carried by player.
/// \return true if the player dies here and now.

bool doCommand(const eCommand cmd, const eItem item, eRoom& room, bool& justArrived, LinkedList& myStuff){
  switch(cmd){       
    case LEFT_CMD:
    case RIGHT_CMD:
    case FORWARDS_CMD:
    case BACK_CMD: { //move
      eRoom destination = nextRoom[room][cmd];
      if(nextRoom[room][cmd] == NOT_A_ROOM)
        printf("You can't go that way.\n");
      else{ 
        room = destination;
        justArrived = true;
      } //else
    } //case
    break;

    case GET_CMD: //get an item
      if(roomContents[room].Find(item)){ //if the item is here
        roomContents[room].Delete(item); //remove it from room contents
        myStuff.Insert(item); //add it to carried items
        printf("OK\n");
      } //if
      else{ //error
        printf("I do not see ");
        printWithArticle(itemToString[item]);
        printf(" here.\n");
      } //else
      break;

    case DROP_CMD: //drop an item
      if(myStuff.Find(item)){ //if carrying the item
        myStuff.Delete(item); //delete it from carried items
        roomContents[room].Insert(item); //add item to the room contents
        printf("OK\n");
      } //if
      else{ //error
        printf("You are not carrying ");
        printWithArticle(itemToString[item]);
        printf(".\n");
      } //else
      break;

    case INVENTORY_CMD: //list the items carried
      printInventory(myStuff);
      break;  

    case LOOK_CMD: //describe the room
      printRoomDescription(room);
      break;
            
    case HELP_CMD: //help - list commands
      printCommands();
      break;

    case QUIT_CMD: //quit the game, you coward
      return true;
      break;
  } //switch

  return false; //not quitting
} //doCommand

/// \brief Perform an NPC action.
/// \param room [IN] Current room.
/// \param justArrived [IN] Whether newly arrived in current room.
/// \return true if the NPC kills the player.

bool doNPC(const eRoom room, const bool justArrived){
  eNPC curNPC = roomNPC[room]; //current NPC in room
  if(curNPC != NO_NPC){ //there is an NPC here
    if(roomContents[room].Find(npcKilledBy[curNPC])){ //if the item that defeats the NPC is in the room
      printf("Suddenly, %s.\n", npcDeathString[curNPC]); //describe what happens
      roomNPC[room] = NO_NPC; //no NPC here now, it's either dead or it left
    } //if
    else //the NPC can attack the player
      if(!justArrived){ //unless the player has just arrived (player needs time to drop the right item)
        printf("Suddenly, %s.\n", npcAttackString[curNPC]); //describe the attack
        printf("Unfortunately, you are now quite dead.\n"); 
        return true; //report death
      } //if
  } //if

  return false; //not dead yet
} //doNPC

/// \brief Main.
/// \return 0 for success, 1 for failure.

int main(){
  eRoom eCurrentRoom = OUTSIDE_ROOM; //player is currently in this room
  LinkedList myStuff; //items that the player is carrying

  initialize();

  bool finished = false; //whether the game is over
  bool justArrived = true; //whether the player just arrived in the room

  //welcome text
  printf("Welcome to Ransack and Run, a game for all ages.\n\n");
  printf("Your task, if you should choose to undertake it, is to loot the castle of\n");
  printf("everything that you can find and bring it all back here.\n\n");
  printf("Type \"help\" for a list of commands.\n\n");

  while(!finished){ //until player death or cowardly quitting
    
    //describe the room only on first arrival
    if(justArrived)
      printRoomDescription(eCurrentRoom);

    //perform NPC action
    finished = doNPC(eCurrentRoom, justArrived);

    //check win condition
    if(eCurrentRoom == OUTSIDE_ROOM && myStuff.Length() == NUM_ITEMS - 1){
      printf("You win!");
      finished = true;
    } //if
    
    //we haven't just arrived - this will be reset later if this is wrong
    justArrived = false;

    //get a player command, parse it, and perform it
    if(!finished){
      eCommand cmd; //command number
      eItem item; //item number
      readCommand(g_cCmdBuffer, g_cItemBuffer); //read command
      if(parseCommand(g_cCmdBuffer, g_cItemBuffer, cmd, item)) //if it parses
        finished = doCommand(cmd, item, eCurrentRoom, justArrived, myStuff); //perform it
      else printf("I don't understand that.\n"); //report bad command
    } //else
  } //while

  printf("\n");
  
#if defined(_MSC_VER) //Microsoft Visual Studio 
  system("pause"); //don't close the damn window yet, you idiot OS
#endif

  return 0;
} //main
