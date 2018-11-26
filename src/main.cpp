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
	char data[8] = "12";
	char data2[8] = "ABCF";


	CanInterface c(name);
	CanFrame d(123,2, data);

	c.connect();
	cout<< c.get_socket_read()<< endl;
	cout<< c.get_socket_write()<< endl;
	c.disconnect();

	cout << data << endl;
	cout << data2 << endl;
	cout<< d.get_can_id()<< endl;
	cout<< d.get_dlc()<< endl;
	d.print_frame();
	d.set_can_id(321);
	d.print_frame();
	d.set_data(data2);
	d.print_frame();

	CanFrame s(555, data);
	s.print_frame();

	return 0;
}
