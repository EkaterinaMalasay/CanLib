#ifndef CANINTERFACE_H
#define	CANINTERFACE_H


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
};



#endif	/* CANINTERFACE_H */

