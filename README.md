# so_long

[![Language](https://img.shields.io/badge/Language-C-A8B9CC?style=flat&logo=c)](https://github.com/Nabil-42/so_long)
[![School](https://img.shields.io/badge/%C3%89cole_42-Paris-00babc?style=flat)](https://42.fr)
[![Norminette](https://img.shields.io/badge/Norminette-compliant-brightgreen?style=flat)](https://github.com/42School/norminette)

A small 2D tile-based game built in C using the MiniLibX graphics library.

## Description

`so_long` is a simple 2D game where the player must collect all collectibles on the map and reach the exit. The map is loaded from a `.ber` file and rendered tile by tile using MiniLibX. The project introduces graphical programming concepts in C without using any game engine.

## Gameplay

- Move the player with `W`, `A`, `S`, `D` or arrow keys
- Collect all items (`C`) before reaching the exit (`E`)
- The map is validated at startup (valid path, surrounded by walls, at least one player, one exit, one collectible)
- Move count is displayed in the terminal

## Map Format (`.ber`)

```
1111111111
1000000001
1C0001E001
1000P00001
1111111111
```

| Symbol | Meaning |
|--------|---------|
| `1` | Wall |
| `0` | Empty space |
| `P` | Player start |
| `C` | Collectible |
| `E` | Exit |

## Stack

- **Language**: C
- **Library**: MiniLibX (X11 / macOS)
- **Key concepts**: event loop, sprite rendering, 2D map parsing, flood-fill validation

## Architecture

```
main → parse .ber file → validate map (flood-fill)
     → init MiniLibX window
     → render all tiles from map array
     → hook keyboard events → update player position → re-render
```

## 42 Project Info

| Field | Value |
|-------|-------|
| **Project** | so_long |
| **Circle** | 2 |
| **Norminette** | Compliant |

## What I Learned

- Graphical programming with MiniLibX (window, image, events)
- 2D map parsing and validation with flood-fill
- Game loop design: event handling → state update → render