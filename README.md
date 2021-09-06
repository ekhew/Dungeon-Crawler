# Dungeon Crawler

This is a dungeon crawler game build in C++. The 'dungeons' are actually graph data structures, where each 'room' is a vertex of a graph. The player's goal in this game is to traverse the dungeon and find three keys, which are hidden in random rooms, and then reach the 'end' room to escape. A dungeon is randomly generated every time the game is started (random paths/graph edges, randomly placed keys, and random 'end' room).

## Motivation

My main motivation for creating this game was to practice working with the graph data structure in C++ in a fun way.

## Features

- Randomly generated dungeon (undirected graph).
- Player traverses the dungeon by traveling between adjacent rooms.
- Keys can be 'picked up' by the player.
- Game ends when the player has all three keys and enters the 'end' room.
