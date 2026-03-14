*This project has been created as part of the 42 curriculum by zsonie, dderny.*

# cub3D — A RayCaster

## Description

cub3D is a 42 school project inspired by the legendary **Wolfenstein 3D** (Id Software, 1992), widely considered the first true First Person Shooter in video game history. The goal is to build a "realistic" 3D graphical representation of the inside of a maze from a first-person perspective using **ray-casting** principles.

The project is implemented in C using the miniLibX graphics library. It renders a navigable 3D maze with textured walls (varying by cardinal direction), configurable floor and ceiling colors, and smooth window management — all driven by a `.cub` scene description file.

## Instructions

### Requirements

- A Unix-based system (Linux or macOS)
- The miniLibX library (included or available on your system)
- `make`

### Cloning

```bash
git clone https://github.com/Equoo/42-cub3d.git --recursive
```

### Compilation

```bash
make
```

To compile in release mode (optimized, no debug flags):

```bash
make MODE="release"
```

To compile with bonus features:

```bash
make bonus
```

To clean object files:

```bash
make clean
```

To fully clean the project:

```bash
make fclean && make re
```

### Execution

```bash
./cub3D path/to/map.cub
```

**Example:**

```bash
./cub3D maps/example.cub
```

### Scene File Format (`.cub`)

The scene file must define the following elements (in any order, except the map which must come last):

```
NO ./path_to_north_texture.xpm
SO ./path_to_south_texture.xpm
WE ./path_to_west_texture.xpm
EA ./path_to_east_texture.xpm

F 220,100,0
C 225,30,0

1111111
1000N01
1111111
```

Map characters: `1` = wall, `0` = empty space, `N/S/E/W` = player start position and orientation.

**Bonus map characters:**

| Character | Description |
|-----------|-------------|
| `D` | Door (can open and close) |
| `B` | Animated sprite |

**Bonus scene file identifiers:**

| Identifier | Description |
|------------|-------------|
| `DO` | Path to the door texture (e.g. `DO ./path_to_door_texture.xpm`) |

### Controls

| Input | Action |
|-------|--------|
| `W` | Move forward |
| `S` | Move backward |
| `A` | Strafe left |
| `D` | Strafe right |
| `←` / `→` | Rotate view left / right |
| `Mouse move` | Rotate view |
| `Scroll up` | Zoom in |
| `Scroll down` | Zoom out |
| `LMB` | Increase mouse sensitivity |
| `RMB` | Decrease mouse sensitivity |
| `ESC` | Quit the program |
| Red cross | Quit the program |

## Resources

### Ray-Casting & Graphics

- [miniLibX documentation](https://harm-smits.github.io/42docs/libs/minilibx) — Unofficial but detailed miniLibX reference

### AI Usage

AI (Claude by Anthropic) was used to write this README file. All code in the project was written by the authors and reviewed without direct AI code generation.
