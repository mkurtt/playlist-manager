# Playlist Manager

A playlist manager written in C, using a doubly linked list to store and manage songs.

## What it does

- Add a song to the beginning, the end, or a specific position
- Delete a song by title
- Print the playlist forward and backward
- Calculate the total duration

## Why a doubly linked list

Each node keeps a pointer to both the next and the previous song, which makes it possible to traverse the playlist in either direction and to remove a node without walking the list from the start again.

## Build & run

```bash
gcc main.c -o main
./main
```
