/*
** EPITECH PROJECT, 2018
** navy
** File description:
** connector functions
*/

# include "navy.h"

void reset_receivement(void)
{
	data->received = false;
	data->data = 0;
}

void publish(data_e type, int data, char *to)
{
	char *cmd = NULL;

	if (type == dataResponse) {
		cmd = "PUBLISH p1:resp:%";
		cmd[9] = to[1];
		cmd[16] = ((data == 1) ? '1' : '2');
		redisAsyncCommand(data->redis->con, NULL, NULL, cmd);
	} else {
		cmd = "PUBLISH p1:data:%";
		cmd[16] = ((data == 1) ? '1' : '2');
		redisAsyncCommand(data->redis->con, NULL, NULL, cmd);
	}

	printf(" => SENDED COMMAND: %s\n", cmd);
}

bool configure_redis_connection(void)
{
	event_t *base = event_base_new();
	char *address = "redis-19349.c15.us-east-1-4.ec2.cloud.redislabs.com";
	redisAsyncContext *con = NULL;
	int port = 19349;

	signal(SIGPIPE, SIG_IGN); // ignored signal
	con = redisAsyncContext(address, port);

	if (con->err) {
		write(2, "Error: ", 7);
		write(2, con->errstr, strlen(con->errstr));
		data->status = 84;
		return (false);
	}

	redisLibeventAttach(con, base);
	redisAsyncCommand(con, onMessage, NULL, "SUBSCRIBE psu_navy");
	event_dispatch_base(base);
	data->redis->con = con;
	return (true);
}

bool connector(void)
{
	if (!configure_redis_connection())
		return (false);

	if (data->type == playerOne) {
		my_putstr("waiting for enemy connection...\n");
		while (!data->connected);
	} else {
		if (!send_signal(data->pid2, SIGUSR1)) {
			write(2, "Unable to send signal.\n", 23);
			return (false);
		}
		my_putstr("successfully connected\n\n");
	}
	return (true);
}