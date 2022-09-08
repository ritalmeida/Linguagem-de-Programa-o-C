#ifndef pr12_h
#define pr12_h

#include <stdlib.h>
#include <string.h>
#include <stdio.h>


/**
 * Structures used for storing a game of cards, where:
 *  - CARD_DECK is the node for the dynamic array od cards of CARDs;
 *  - PLAYER_NODE is the node for the linked-list of PLAYER.
 */
typedef struct card {
    char cardId;
    char cardSuit;
    int cardPoints;
} CARD;

typedef struct card_deck {
    int n_cards;
    int size_cards;
    CARD * pcards;
} CARD_DECK;

typedef struct player {
    char *pusername;
    CARD_DECK deck;
} PLAYER;

typedef struct player_node {
    PLAYER player;
    struct player_node * pnext;
} PLAYER_NODE;

typedef struct game {
    PLAYER_NODE *pplayers;
    int nplayers;
} GAME;

/**
* Given an array of names, creates and initializes with the received values a list
* with *size* players. Each player will be initialized with an empty dynamic array of cards.
* @param pnames - string array with player names;
* @param size - number of players to be insert;
* @return pointer to the created card game.
*/ 
GAME * create_list_players(const char **pnames, int size);

/**
* Function that inserts a player into the game. Initializes with empty an card array.
* @param pg - pointer to the game;
* @param player - player name;
*/ 
void insert_player_into_list(GAME *pg, char *player);

/**
* Finds a player given an unique name
* @param pg - pointer to the game;
* @param player - player name;
* @return pointer to found player.
*/ 
PLAYER *find_player (GAME * pg, const char * player);

/**
* Function that inserts an array of cards in the linked player list
* @param pg - pointer to the game;
* @param player - name of the player to be insert;
* @param id - id of the card;
* @param suit - card suit;
* @param points - chart points;
*/ 
void insert_card_dynarray_into_player_list(GAME *pg, char *player, char id, char suit, int points);

/**
* Function that returns the card with the highest value given a player and a card suit.
* @param g - copy of game;
* @param suit - suit to look for;
* @param pname - player to look for;
* @return pointer to the found card (NULL if not existing).
*/ 
CARD* find_highest_card_player(GAME g, char suit, char *pname);

/**
* Function that prints all the information related to a game to stdout
* @param g - copy of the game to be printed;
*/ 
void print_game (GAME g);

/**
* Function that saves a given game to a text file
* @param g - copy of the card game;
* @param fn - path to the text file where the card game information will be saved.
*/ 
void save_existing_game_txt(GAME g, char fn[]);


#endif /* pr12_h */
