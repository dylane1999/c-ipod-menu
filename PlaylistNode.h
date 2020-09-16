#ifndef PLAYLISTNODE_H
#define PLAYLISTNODE_H

typedef struct struct_PlaylistNode

{

     char uniqueID[50];

     char songName[50];

     char artistName[50];

     int songLength;

     struct struct_PlaylistNode* nextNodePtr;

} PlaylistNode;

// The following statements are the required function declaration.

void PrintMenu(char* title);

void CreatePlaylistNode( char* uniqueID, char* songName, char* artistName, int songLength, PlaylistNode* thisNode, PlaylistNode* nextLoc);

void InsertPlaylistNodeAfter(PlaylistNode* thisNode, PlaylistNode* newNode);

void SetNextPlaylistNode(PlaylistNode* thisNode, PlaylistNode* newNode);

void PrintPlaylistNode(PlaylistNode* thisNode);

PlaylistNode* GetNextPlaylistNode(PlaylistNode* thisNode);

void PrintMenuHeader(char *title);


#endif // PLAYLISTNODE_H