#include "../include/caninterface.h"
#include "../include/canframe.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <linux/can.h>
#include <linux/can/raw.h>
#include <iostream>
using namespace std;


int main(int argc, char *argv[])
{
	char name[5] = "can0";
	unsigned char data[8] = {0};
	data[0]=1;
	data[1]=2;

	CanInterface c(name);
	CanFrame d(123,2, data);

	c.connect();
	cout<< c.get_socket_read();
	cout<< c.get_socket_write();
	c.disconnect();

	cout<< d.get_can_id();
	cout<< d.get_dlc();
	d.print_frame();
	d.set_can_id(321);
	d.print_frame();

	return 0;
}
