/*
** EPITECH PROJECT, 2018
** navy
** File description:
** redis connection
*/

# include "navy.h"

void initialize_connection(void)
{
	char *addr = "redis-19349.c15.us-east-1-4.ec2.cloud.redislabs.com";
	int port = 19349;
	event_t *base = event_base_new();

	signal(SIGPIPE, SIG_IGN);
	redis->con = redisAsyncConnect(addr, port);
}