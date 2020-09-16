// Header file section

#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <stdbool.h>

#include "PlaylistNode.h"

void PrintMenuHeader(char *title)

{

  printf("%s PLAYLIST MENU\n", title);

  printf("a - Add song\n");

  printf("r - Remove song\n");

  printf("c - Change position of song\n");

  printf("s - Output songs by specific artist\n");

  printf("t - Output total time of playlist (in seconds)\n");

  printf("o - Output full playlist\n");

  printf("q - Quit\n\n");

}

// Create a method named "PrintMenu" to accept the user input

// and perform the menu operations.

void PrintMenu(char *title)

{

  PlaylistNode *head = NULL;

  PlaylistNode *current = NULL;

  PlaylistNode *tail = NULL;

  PlaylistNode *nodeObj = NULL;

  PlaylistNode *beforeNode = NULL;

  PlaylistNode *afterNode = NULL;

  PlaylistNode *newBeforeNode = NULL;

  PlaylistNode *newAfterNode = NULL;

  int sNum = 0;

  int position = 0;

  int newPosition = 0;

  char uId[50];

  char sName[50];

  char aName[50];

  int sLength = 0;

  bool fNode = false;

  PrintMenuHeader(title);

  char c = '\0';

  while (c != 'q')

  {

    printf("Choose an option:\n");

    scanf(" %c", &c);

    switch (c)

    {

    case 'a':

      printf("ADD SONG\n");

      printf("Enter song's unique ID:\n");

      scanf(" %100[^\n]", uId);

      printf("Enter song's name:\n");

      scanf(" %100[^\n]", sName);

      printf("Enter artist's name:\n");

      scanf(" %100[^\n]", aName);

      printf("Enter song's length (in seconds):\n\n");

      scanf("%d", &sLength);

      if (head == NULL)
      {

        head = (PlaylistNode *)malloc(sizeof(PlaylistNode));

        CreatePlaylistNode(uId, sName, aName, sLength, head, NULL);

        tail = head;
      }

      else
      {

        current = (PlaylistNode *)malloc(sizeof(PlaylistNode));

        CreatePlaylistNode(uId, sName, aName, sLength, current, NULL);

        InsertPlaylistNodeAfter(tail, current);

        tail = current;
      }

      PrintMenuHeader(title);

      break;

    case 'r':

      printf("REMOVE SONG\n");

      printf("Enter song's unique ID:\n");

      scanf(" %50[^\n]", uId);

      current = head;

      tail = NULL;

      do
      {

        if (strcmp(current->uniqueID, uId) == 0)

        {

          fNode = true;

          if (current == head)

          {

            head = current->nextNodePtr;
          }

          else

          {

            tail->nextNodePtr = current->nextNodePtr;
          }

          printf("\"%s\" removed.\n\n", current->songName);

          free(current);
        }

        else

        {

          tail = current;

          current = current->nextNodePtr;
        }

      } while ((fNode == false) && (current != NULL));

      fNode = false;

      PrintMenuHeader(title);

      break;

    case 'c':

      printf("CHANGE POSITION OF SONG\n");

      printf("Enter song's current position: ");

      scanf("%d", &position);

      printf("Enter new position for song: ");

      scanf("%d", &newPosition);

      current = head;

      if (position == 1)

      {

        nodeObj = current;

        afterNode = current->nextNodePtr;

        current = current->nextNodePtr;

        sNum = 2;
      }

      else

      {

        sNum = 1;
      }

      if (newPosition == 1)

      {

        newAfterNode = current;
      }

      while (current->nextNodePtr != NULL)

      {

        if (sNum == position - 1)

        {

          beforeNode = current;

          nodeObj = current->nextNodePtr;
        }

        if ((sNum == position) && (position != 1))

        {

          afterNode = current->nextNodePtr;
        }

        if ((sNum == newPosition - 1) && (newPosition < position))

        {

          newBeforeNode = current;

          newAfterNode = current->nextNodePtr;
        }

        if ((sNum == newPosition) && (newPosition > position))

        {

          newBeforeNode = current;

          newAfterNode = current->nextNodePtr;
        }

        current = current->nextNodePtr;

        sNum++;
      }

      if (position == 1)

      {

        head = afterNode;
      }

      else

      {

        nodeObj->nextNodePtr = newAfterNode;
      }

      if (newPosition == 1)

      {

        head = nodeObj;
      }

      else

      {

        newBeforeNode->nextNodePtr = nodeObj;
      }

      beforeNode->nextNodePtr = afterNode;

      printf("\"%s\" moved to position %d\n", nodeObj->songName, newPosition);

      PrintMenuHeader(title);

      break;

    case 's':

      printf("OUTPUT SONGS BY SPECIFIC ARTIST\n");

      printf("Enter artist's name:");

      scanf(" %50[^\n]", aName);

      current = head;

      sNum = 1;

      while (current != NULL)

      {

        if (strcmp(aName, current->artistName) == 0)

        {

          printf("%d.\n", sNum);

          PrintPlaylistNode(current);
        }

        current = GetNextPlaylistNode(current);

        sNum++;
      }

      break;

    case 't':

      printf("OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)\n");

      int sum = 0;

      current = head;

      while (current != NULL)

      {

        sum += current->songLength;

        current = GetNextPlaylistNode(current);
      }

      printf("Total time: %d seconds\n", sum);

      break;

    case 'o':

      printf("%s - OUTPUT FULL PLAYLIST\n", title);

      if (head == NULL)

      {

        printf("Playlist is empty\n\n");
      }

      else

      {

        current = head;

        sNum = 1;

        while (current != NULL)

        {

          printf("%d.\n", sNum);

          PrintPlaylistNode(current);

          current = GetNextPlaylistNode(current);

          sNum++;
        }
      }

      PrintMenuHeader(title);

      break;
    }
  }
}

// Create a method named "CreatePlaylistNode" to add

// the new song details.

void CreatePlaylistNode(char *uniqueID, char *songName, char *artistName, int songLength, PlaylistNode *thisNode, PlaylistNode *nextLoc)

{

  strcpy(thisNode->uniqueID, uniqueID);

  strcpy(thisNode->songName, songName);

  strcpy(thisNode->artistName, artistName);

  thisNode->songLength = songLength;

  thisNode->nextNodePtr = nextLoc;

  return;
}

// Create a method named "InsertPlaylistNodeAfter" to insert

// the song in the next node.

void InsertPlaylistNodeAfter(PlaylistNode *thisNode, PlaylistNode *newNode)

{

  PlaylistNode *tmpNext = NULL;

  tmpNext = thisNode->nextNodePtr;

  thisNode->nextNodePtr = newNode;

  newNode->nextNodePtr = tmpNext;

  return;
}

// Create a method named "SetNextPlaylistNode" to set a new node to come after node.

void SetNextPlaylistNode(PlaylistNode *thisNode, PlaylistNode *newNode)

{

  thisNode->nextNodePtr = newNode;

  return;
}

// Create a method named "PrintPlaylistNode" to display the data

void PrintPlaylistNode(PlaylistNode *thisNode)
{

  printf("Unique ID: %s\n", thisNode->uniqueID);

  printf("Song Name: %s\n", thisNode->songName);

  printf("Artist Name: %s\n", thisNode->artistName);

  printf("Song Length (in seconds): %d\n", thisNode->songLength);

  printf("\n");

  return;
}

// Create a method named "GetNextPlaylistNode" to grab location pointed by nextNodePtr pointer.

PlaylistNode *GetNextPlaylistNode(PlaylistNode *thisNode)
{

  return thisNode->nextNodePtr;
}