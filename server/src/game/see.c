#include "server.h"
#include "tile_type.h"
#include "player_type.h"

int		player_relative_direction(t_player *player, enum e_directions d)
{
	d += player->facing - MIN_DIRECTION * 2;
	return (d % NUM_DIRECTIONS + MIN_DIRECTION);
}

char	*add_next_tile(char *format, t_tile *temp, int *first)
{
	if (*first == 1)
		format = strjoin_free(format, strnew(","));
	else
	{
		format = strnew("");
		*first = 1;	
	}
	format = strjoin_free(format, existing_player_count(temp));
	format = strjoin_free(format, existing_food_count(temp));
	format = strjoin_free(format, existing_stone_count(temp));
	return (format);
}

char	*first_tile(char *format, t_tile *temp)
{
	format = strjoin_free(format, existing_player_count(temp));
	format = strjoin_free(format, existing_food_count(temp));
	format = strjoin_free(format, existing_stone_count(temp));
	return (format);
}

char	*get_format_string(t_player *player, t_tile *tile)
{
	char	*format;
	t_tile	*temp;
	int		vision_distance;
	int		amount_per_row;
	int		first;

	first = 0;
	vision_distance = 0;
	while (vision_distance <= player->level)
	{
		temp = tile;
		amount_per_row = 0;
		while (amount_per_row <= vision_distance * 2)
		{
			format = add_next_tile(format, temp, &first);
			temp = get_adj_tile(temp, player_relative_direction(player, EAST));
			amount_per_row++;
		}
		tile = get_adj_tile(tile, player_relative_direction(player, NORTHWEST));
		vision_distance++;
	}
	format = wrap("{", format, " }\n");
	return (format);
}

char	*see_tiles(int pid)
{
	char		*str;
	t_player	*player;

	player = get_player(pid);
	player->tile->num_players -= 1;
	str = get_format_string(player, player->tile);
	player->tile->num_players += 1;
	return (str);
}
