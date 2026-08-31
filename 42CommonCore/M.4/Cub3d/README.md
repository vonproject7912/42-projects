*This project has been created as part of the 42 curriculum by hadmessa, mosriji.*

# cub3D

## Description

cub3D is a raycasting engine written in C, inspired by the original Wolfenstein 3D.
The goal of the project is to build, from a simple 2D text map, a real-time
pseudo-3D first-person view rendered with MiniLibX.

The project is split into two complementary parts:

- **Parsing**: reading and validating the `.cub` scene description file
  (wall textures, floor/ceiling colors, map grid, player spawn), and turning it
  into a clean, structured data set.
- **Execution**: initializing MiniLibX, casting rays from the player's position
  to compute wall distances, rendering the scene column by column, and handling
  real-time player movement and rotation.

Both parts communicate through a single shared data structure (`t_game`),
which acts as the contract between parsing and rendering.

## Instructions

### Requirements

- Linux (X11) or macOS with MiniLibX installed
- `gcc` / `make`

### Compilation

```bash
make          # compiles the mandatory part
make bonus    # compiles the bonus part (if implemented)
make clean    # removes object files
make fclean   # removes object files and the binary
make re       # fclean + make
```

### Execution

```bash
./cub3D <path/to/map.cub>
```

The `.cub` file must describe, in any order (except the map, which must always
come last):

- `NO`, `SO`, `WE`, `EA`: paths to the north/south/west/east wall textures (`.xpm`)
- `F`: floor color, as `R,G,B`
- `C`: ceiling color, as `R,G,B`
- the map itself, using `0` (empty space), `1` (wall), and one of `N`/`S`/`E`/`W`
  for the player's starting position and orientation

The map must be closed by walls; any malformed configuration makes the program
print `Error\n` followed by an explicit message and exit.

## Resources

### Classic references

- [Lode's Computer Graphics Tutorial – Raycasting](https://lodev.org/cgtutor/raycasting.html):
  the reference algorithm used for the `dir`/`plane` vectors and the DDA
  wall-distance calculation.
- The 42 cub3D subject itself, for the exact file format and error-handling
  requirements.
- MiniLibX documentation (as provided by the school's internal resources) for
  window/image management and event hooks.
- id Software's *Wolfenstein 3D* as the historical/visual reference for the
  project's rendering style.

### AI usage

An AI assistant (Claude, Anthropic) was used during the parsing part of this
project as a learning and pair-programming aid:

- Explaining unfamiliar concepts step by step (e.g. dynamic memory management
  patterns, the flood fill algorithm for map closure, the meaning of the
  `dir`/`plane` vectors in raycasting) with diagrams and small animations.
- Reviewing hand-written code and pointing out concrete bugs (e.g. off-by-one
  errors in loop increments, incorrect separators in string splitting,
  mismatched function names between declaration and call sites, uninitialized
  variables) without rewriting the logic outright.
- Helping plan the file/function architecture (norm-compliant file splitting,
  bottom-up coding order) and reconcile two independently written headers
  between teammates into a single shared `t_game` structure.
- Assisting in drafting this README.

All AI-suggested code and explanations were read, tested, and understood by
the author before being integrated; the AI was not used to generate unreviewed
code wholesale.