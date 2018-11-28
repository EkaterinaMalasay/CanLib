#include "../include/caninterface.h"
#include "../include/canframe.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <linux/can.h>
#include <linux/can/raw.h>

CanInterface::CanInterface(char *interface)
{
	strcpy(intrf_name, interface);
}

int CanInterface::get_socket_write()
{
	return(socket_write);
}

int CanInterface::get_socket_read()
{
	return(socket_read);
}

int CanInterface::connect()
{
	struct sockaddr_can addr;
	struct ifreq ifr;

	socket_write = socket(PF_CAN, SOCK_RAW, CAN_RAW);
		if( socket_write == -1 ) {
			printf("%s\n", "socket error");
		}

	strcpy(ifr.ifr_name, intrf_name);
	ioctl(socket_write, SIOCGIFINDEX, &ifr);

	addr.can_family = AF_CAN;
	addr.can_ifindex = ifr.ifr_ifindex;

	bind(socket_write, (struct sockaddr *)&addr, sizeof(addr));

	///////////////////////////////////////////////

	socket_read = socket(PF_CAN, SOCK_RAW, CAN_RAW);
		if( socket_read == -1 ) {
			printf("%s\n", "socket error");
		}

	strcpy(ifr.ifr_name, intrf_name);
	ioctl(socket_read, SIOCGIFINDEX, &ifr);

	addr.can_family = AF_CAN;
	addr.can_ifindex = ifr.ifr_ifindex;

	bind(socket_read, (struct sockaddr *)&addr, sizeof(addr));
	return 0;
}

int CanInterface::disconnect()
{
	close(socket_write);
	close(socket_read);
	return 0;
}

int CanInterface::receive(CanFrame &CanFr)
{
	struct can_frame frame;
	int nbytes;
	int i;

	nbytes = read(socket_read, &frame, CANFD_MTU);
	CanFr.set_can_id(frame.can_id);
	CanFr.set_dlc(frame.can_dlc);
	CanFr.set_data(frame.data);
}

int CanInterface::send(CanFrame &CanFr)
{
	struct can_frame frame;
    int nbytes;
    int i;

    frame.can_id = CanFr.get_can_id();
    frame.can_dlc = CanFr.get_dlc();
    for(i = 0; i < frame.can_dlc; i++)
		frame.data[i] = CanFr.get_data(i);

    nbytes = write(socket_write, &frame, sizeof(struct can_frame));
}



