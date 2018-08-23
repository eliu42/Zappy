#include "server.h"
#include "test.h"

int		test_map_creation(void);
int		test_map_movement(void);
int		test_player_creation(void);
int		test_player_movement(void);

void	test_client_connection_listener(void);
void	test_socket_iteration(void);
void	test_handshake(void);
void	test_parse_command_line_options(void);
void	test_client_lookup(void);
void	test_receive_user_message(void);

int		main(int argc, char **argv)
{
	srandomdev();
	puts("hello world");
	test_parse_command_line_options();
	test_client_connection_listener();
	test_handshake();
	test_client_lookup();
	test_receive_user_message();
	test_map_creation();
	test_map_movement();
	/* test_player_creation(); */
	/* test_player_movement(); */
	return (0);
}
