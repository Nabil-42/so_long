# Usage — so_long

```bash
./so_long maps/map.ber
```

## Controls

| Key | Action |
|-----|--------|
| `W` or `Arrow Up` | Move up |
| `S` or `Arrow Down` | Move down |
| `A` or `Arrow Left` | Move left |
| `D` or `Arrow Right` | Move right |
| `ESC` | Quit |

## Map Format

Maps use `.ber` extension. Rules:
- Must be rectangular
- Must be surrounded by walls (`1`)
- Must contain exactly one player (`P`), at least one collectible (`C`), and one exit (`E`)
- Must have at least one valid path from `P` to `E` passing through all `C`

Example map:

```
1111111
1P0C001
100E001
1111111
```

## Objective

Collect all `C` items and reach the exit `E`. Move count is printed to the terminal each step.