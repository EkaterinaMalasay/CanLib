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
	unsigned char data2[8] = "0000000";
	unsigned char data3[9] = "ABCFABCF";

	CanInterface c(name);

	CanFrame a(555,8, data3);
	// CanFrame b(555,2, data2);
	 CanFrame f(111,8, data2);
	a.print_frame();
	cout<<"a dlc: "<< a.get_dlc()<< endl;
	cout<<"a data: "<<  a.get_data()<< endl;
	a.set_can_id(321);
	a.set_dlc(2);
	a.set_data(data3);
	a.print_frame();
	a.set_dlc(3);
	a.print_frame();
	a.set_data(2, data2[0]);
	a.print_frame();
	cout << "get_data : " << a.get_data() << endl;
	cout << "get_data[i] : "<< a.get_data(2) << endl;
	a.print_frame();
	a.set_dlc(6);
	a.set_data(data3);
	a.print_frame();

	c.connect();
	cout << "send: " << endl;
	a.print_frame();
	cout << "in: " << endl;
	f.print_frame();
	c.send(a);
	cout << "receive: " << endl;
	c.receive(f);
	f.print_frame();
	c.disconnect();
	return 0;
}

