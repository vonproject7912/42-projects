#include "cub.h"

void free_game(t_game *game)
{
    int i;

    i = 0;
    if(!game)
        return;
    if(game->map.grid)
    {
        i = -1;
        while(game->map.grid[++i])
            free(game->map.grid[i]);
        free(game->map.grid);
        game->map.grid = NULL;
    }
    i = 0;
	while (i < 4)
	{
		if (game->textures[i].path)
			free(game->textures[i].path);
		i++;
	}
    //A AJOUTER DESTROY IMAGE ET TOUT DE MLX
}
void free_split(char **parts)
{
    int i;

    if(!parts)
        return;
    i = 0;
    while(parts[i])
    {
        free(parts[i]);
        i++;
    }
    free(parts);
}