 /// \file "defines.h"

#pragma once

#if defined(_MSC_VER) //Microsoft Visual Studio 
  #pragma warning(disable : 4996) //disable annoying security warnings for stdio functions
#endif

static const int SHORTSTRINGLENGTH = 16; ///< Length of a short string.
static const int LONGSTRINGLENGTH = 128; ///< Length of a long string.

///////////////////////////////////////////////////////////////////////////////////////////////////
//Items

/// \brief Item number.

enum eItem{
  NONE_ITEM, SWORD_ITEM, JEWEL_ITEM, AXE_ITEM, FROG_ITEM, COIN_ITEM,
  NUM_ITEMS //must be last
}; //eItem

typedef enum eItem eItem; //added (typedef trick)

/// \brief Description string corresponding to each item number.

const char itemToString[NUM_ITEMS][SHORTSTRINGLENGTH] = {
  "none",
  "sword",
  "jewel",
  "axe",
  "frog",
  "coin",
}; //itemToString[][]


///////////////////////////////////////////////////////////////////////////////////////////////////
//NPCs: Non Player Characters

/// \brief NPC number.

enum eNPC{
  NO_NPC, DRAGON_NPC, DWARF_NPC,
  NUM_NPCS //must be last
}; //eNPC

typedef enum eNPC eNPC; //added (typedef trick)

/// \brief Description string corresponding to each NPC number.

const char npcToString[NUM_NPCS][LONGSTRINGLENGTH] = {
  "",
  "great green fire-breathing dragon",
  "short, smelly dwarf"
}; //npcToString[][]

/// \brief Attack string corresponding to each NPC number.

const char npcAttackString[NUM_NPCS][LONGSTRINGLENGTH] = {
  "",
  "the dragon attacks you in a flurry of scales and fire",
  "the dwarf jumps on you with his iron-shod feet"
}; //npcAttackString[][]

/// \brief Death string corresponding to each NPC number.

const char npcDeathString[NUM_NPCS][LONGSTRINGLENGTH] = {
  "",
  "the dragon takes one look at the frog and flies away",
  "the dwarf picks up the axe and accidentally cuts off\nhis own head. The body disappears in a cloud of greasy smoke"
}; //npcDeathString[][]

/// \brief The killing item for each NPC number.

eItem npcKilledBy[NUM_NPCS] = {
  NONE_ITEM, FROG_ITEM, AXE_ITEM
}; //npcKilledBy

///////////////////////////////////////////////////////////////////////////////////////////////////
//Player commands

/// \brief Command number.

enum eCommand{
  LEFT_CMD, RIGHT_CMD, FORWARDS_CMD, BACK_CMD, GET_CMD, DROP_CMD, INVENTORY_CMD, QUIT_CMD,
  LOOK_CMD, HELP_CMD,
  NUM_COMMANDS //must be last
}; //eCommand

/// \brief Description string corresponding to each command number.

const char commandToString[NUM_COMMANDS][SHORTSTRINGLENGTH] = {
  "left",
  "right",
  "forwards",
  "back",
  "get",
  "drop",
  "inventory",
  "quit",
  "look",
  "help",
}; //commandToString[][]

///////////////////////////////////////////////////////////////////////////////////////////////////
//Directions

/// \brief Direction number.

enum eDirection{
  LEFT_DIR, RIGHT_DIR, FORWARD_DIR, BACK_DIR,
  NUM_DIRS //must be last
}; //eDirection

/// \brief Description string corresponding to each direction number.

const char directionToString[NUM_DIRS][SHORTSTRINGLENGTH] = {
  "on your left",
  "on your right",
  "in front of you",
  "behind you"
}; //directionToString[][]

///////////////////////////////////////////////////////////////////////////////////////////////////
//Rooms

/// \brief Room number.

enum eRoom{
  NOT_A_ROOM, OUTSIDE_ROOM, DRAGON_ROOM, THRONE_ROOM, DWARF_ROOM,
  NUM_ROOMS //must be last
}; //eRoom

typedef enum eRoom eRoom; //added (typedef trick)
/// \brief Description string corresponding to each room number.

const char roomToString[NUM_ROOMS][LONGSTRINGLENGTH] = {
  "",
  "outside a rather run-down and dilapidated castle. It is raining.",
  "in a dusty entry hall. Dingy paintings of nondescript\npeople glare down at you sullenly.",
  "in a large room filled with rather more antique furniture\nthan it needs.",
  "in a smallish closet."
}; //roomToString[][]

/// \brief Next room in each direction.
/// There is a row for each room in order of eRoom.
/// Each row has a sequence of rooms accessible through doors,
/// in order of eDirection. NOT_A_ROOM means there is no door
/// from that room in that direction.

const eRoom nextRoom[NUM_ROOMS][NUM_DIRS] = {
  {NOT_A_ROOM, NOT_A_ROOM, NOT_A_ROOM, NOT_A_ROOM},
  {NOT_A_ROOM, NOT_A_ROOM, DRAGON_ROOM, NOT_A_ROOM}, //OUTSIDE_ROOM
  {DWARF_ROOM, NOT_A_ROOM, THRONE_ROOM, OUTSIDE_ROOM}, //DRAGON_ROOM
  {NOT_A_ROOM, NOT_A_ROOM, NOT_A_ROOM, DRAGON_ROOM}, //THRONE_ROOM
  {NOT_A_ROOM, NOT_A_ROOM, NOT_A_ROOM, DRAGON_ROOM}, //DWARF_ROOM
}; //nextRoom
