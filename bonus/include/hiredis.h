/*
** EPITECH PROJECT, 2018
** navy
** File description:
** hiredis functions (header file)
*/

# ifndef HIREDIS_EDIT_H
# define HIREDIS_EDIT_H

# include <stdio.h>

struct redisAsyncContext;
struct dict;

typedef void (redisCallbackFn)
(struct redisAsyncContext *con, void *one, void *two);
typedef void (redisDisconnectCallback)
(const struct redisAsyncContext *con, int st);
typedef void (redisConnectCallback)
(const struct redisAsyncContext *con, int st);

typedef struct redisCallback {
	redisCallbackFn			*fn;
	void 					*privdata;
	struct redisCallback 	*next;
} redisCallback;

typedef struct redisCallbackList {
	redisCallback 			*head;
	redisCallback 			*tail;
} redisCallbackList;

enum redisConnectionType {
	REDIS_CONN_TCP,
	REDIS_CONN_UNIX
};

typedef struct redisReadTask {
	int 					type;
	int 					elements;
	int 					idx;
	void 					*obj;
	void 					*privdata;
	struct redisReadTask 	*parent;
} redisReadTask;

typedef struct redisReplyObjectFunction {
	void *(*createString)(const redisReadTask *, char *, size_t);
	void *(*createArray)(const redisReadTask *, int);
	void *(*createInteger)(const redisReadTask *, long long);
	void *(*createNil)(const redisReadTask*);
	void (*freeObject)(void *);
} redisReplyObjectFunction;

typedef struct redisReader {
	int 					err;
	char 					errstr[128];
	char 					*buf;
	size_t 					pos;
	size_t 					len;
	size_t 					maxbuf;
	redisReadTask 			rstack[9];
	int 					ridx;
	void 					*reply;
	redisReplyObjectFunction *fn;
	void 					*privdata;
} redisReader;

typedef struct redisContext {
	int 					err;
	char 					errstr[128];
	int 					fd;
	int 					flags;
	char 					*obuf;
	redisReader 			*reader;
	enum redisConnectionType connection_type;
	struct timeval 			*timeout;
	struct {
		char 			*host;
		char 			*source_addr;
		int 			port;
	} tcp;
	struct {
		char 				*path;
	} unix_sock;
} redisContext;

typedef struct redisAsyncContext {
	redisContext 			*c;
	int 					err;
	char 					*errstr;
	void 					*data;
	struct 					data {
		void 				*data;
		void 			(*addRead)(void *privdata);
		void 			(*delRead)(void *privdata);
		void 			(*addWrite)(void *privdata);
		void 			(*delWrite)(void *privdata);
		void 			(*cleanup)(void *privdata);
	} ev;
	redisDisconnectCallback	*onDisconnect;
	redisConnectCallback 	*onConnect;
	redisCallbackList 		replies;
	struct {
		redisCallbackList	invalid;
		struct dict 		*channels;
		struct dict 		*patterns;
	} sub;
} redisAsyncContext;

int redisAsyncCommand(redisAsyncContext *ac, redisCallbackFn *fn,
void *privdata, const char *format, ...);

redisAsyncContext *redisAsyncConnect(const char *ip, int port);

# endif