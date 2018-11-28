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
	unsigned char data[8] = "12";
	unsigned char data2[8] = "ABCF";


	CanInterface c(name);
	CanFrame a(555,2, data);
	CanFrame f(111,4, data2);

	c.connect();
	cout<< c.get_socket_read()<< endl;
	cout<< c.get_socket_write()<< endl;

	cout<< a.get_can_id()<< endl;
	cout<< a.get_dlc()<< endl;
	cout<< a.get_data()<< endl;
	a.print_frame();
	a.set_can_id(321);
	a.print_frame();
	a.set_data(data2);
	a.print_frame();
	cout << "send: " << endl;
	f.print_frame();
	c.send(f);
	cout << "receive: " << endl;
	c.receive(a);
	a.print_frame();
	c.disconnect();
	return 0;
}

