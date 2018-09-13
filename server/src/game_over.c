#include "server.h"

static void	gfx_eventmsg_game_end(int num_winners, int *team_ids)
{
	int		i;

	gfx_sendall("GAME_END %d\n", num_winners);
	i = 0;
	while (i < num_winners)
	{
		gfx_sendall("WINNING_TEAM %d\n", team_ids[i]);
		++i;
	}
}

void	handle_possible_gameover(void)
{
	int		*winning_team_ids;
	int		game_end_state;
	int		num_winners;

	winning_team_ids = NULL;
	game_end_state = get_winning_teams(&winning_team_ids);
	if (game_end_state != 0)
	{
		num_winners = (game_end_state == -1 ? 0 : game_end_state);
		gfx_eventmsg_game_end(num_winners, winning_team_ids);
		exit(0);
	}
	free(winning_team_ids);
}
