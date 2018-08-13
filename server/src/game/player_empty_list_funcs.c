#include "server.h"

/*
** Make and delete t_plist's.
**
** plist's are freed by the [ remove_player_from_waitlist ] fn.
*/

int				*new_plist(t_player *p, t_plist **head)
{
	t_plist		*new;
	t_plist		*tmp;

	tmp = *head;
	if ((new = malloc(sizeof(t_plist))) == NULL)
		ERR_OUT("new_plist; malloc");
	new->p = p;
	new->next = NULL;
	if (tmp != NULL)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new
	}
	else
		*head = new;
	return (0);
}



/*
** TODO: Adds player to empty avatar list for [ team ].
*/

int				add_player_to_team_waitlist(t_player *p)
{
	new_plist(p, &g_map->empty_avatars[p->team]);
	return (0);
}

/*
** Removes the first plist node from the list,
** frees the plist, and returns a pointer to the empty player
**
** Returns [ NULL ] if the list was empty.
*/

t_player		*remove_player_from_waitlist(int team)
{
	t_plist		*tmp;
	t_player	*new_avatar;

	if (g_map->empty_avatars[team] == NULL)
		return (NULL);
	tmp = g_map->empty_avatars[team];
	g_map->empty_avatars[team] = g_map->empty_avatars[team]->next;
	new_avatar = tmp->p;
	free(tmp);
	return (new_avatar);
}
