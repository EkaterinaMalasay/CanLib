#ifndef CANINTERFACE_H
#define	CANINTERFACE_H
#include "../include/canframe.h"

class CanInterface
{
    char intrf_name[15];
    int socket_write;
    int socket_read;
public:
    CanInterface(char *name);
    
    int connect(); 
    int disconnect();
    int get_socket_write();
    int get_socket_read();
    int receive(CanFrame &CanFr);
    int send(CanFrame &CanFr);
};



#endif	/* CANINTERFACE_H */

