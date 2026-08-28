#ifndef CUBE3D_H
# define CUBE3D_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
//#include <time/sys.h>
// # include "../Libft/libft.h"

# define MAX_MAP_LINES 1000


/* PROTOTYPES-------- parsing -------- */
void parse_error(t_game *game, char *msg);
void    parse_file(char *path, t_game *game);
void     dispatch_line(char *line, t_game *game);
void    parse_texture(char *line, t_texture *tex, t_game *game);
void    parse_color(char *line, t_color *color, t_game *game);
int     is_map_line(char *line);
void normalize_map(t_game *game);
void    map_filler(int fd, char *first_line, t_game *game);
void free_split(char **parts);
void free_game(t_game *game);
void    check_map_closed(t_game *game);
void    init_player_direction(t_game *game);


/* -------- Couleurs -------- */
typedef struct s_color
{
    int r;
    int g;
    int b;
}   t_color;

/* -------- Une texture (mur) -------- */
typedef struct s_texture
{
    char    *path;      // chemin donné dans le .cub
    void    *img;        // image chargée via mlx (rempli par l'exec)
    char    *addr;        // adresse des pixels (rempli par l'exec)
    int     width;
    int     height;
    int     line_len;
    int     bpp;
    int     endian;
}   t_texture;

/* -------- Le joueur -------- */
typedef struct s_player
{
    double  x;           // position en coordonnées "case" (ex 3.5)
    double  y;
    double  dir_x;       // vecteur direction (pour raycasting)
    double  dir_y;
    double  plane_x;     // plan caméra (FOV)
    double  plane_y;
    char    start_dir;   // 'N','S','E','W' brut, avant conversion
}   t_player;

/* -------- La carte -------- */
typedef struct s_map
{
    char    **grid;      // tableau 2D de caractères, rectangulaire
    int     width;
    int     height;
}   t_map;

/* -------- Tout le jeu : le tiroir maître -------- */
typedef struct s_game
{
    void        *mlx;
    void        *win;
    t_map       map;
    t_player    player;
    t_texture   north;
    t_texture   south;
    t_texture   west;
    t_texture   east;
    t_color     floor;
    t_color     ceiling;

    /* --- zone bonus, vide au départ --- */
    // t_door   *doors;
    // t_sprite *sprites;
    // t_minimap minimap;
}   t_game;

#endif