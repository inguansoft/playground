#include <stdio.h>
#include "tcp_socket_conn.h"

void log_server_message(const int me, const char *message)
{
    if (me == SERVER)
        printf("\tme [server]: %s", message);
    else
        printf("them [server]: %s", message);
}

void log_client_message(const int me, const char *message)
{
    if (me == CLIENT)
        printf("\tme [client]: %s", message);
    else
        printf("them [client]: %s", message);
}