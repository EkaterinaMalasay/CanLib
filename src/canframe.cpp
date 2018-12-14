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

/*constructors*/

CanFrame::CanFrame() //will generate random Can Frame (later..)
{ }

CanFrame::CanFrame(unsigned int can_id, unsigned int new_dlc, unsigned char*new_data)
{
	this->can_id = can_id;
	dlc = new_dlc;
	if (dlc <= MAX_LEN) {
		for(int i=0; i<=dlc; i++)
			data[i]=new_data[i];
	}
}

/*this constructor automatically fills the field dlc*/
CanFrame::CanFrame(unsigned int can_id, unsigned char *new_data)
{
	this->can_id = can_id;
	dlc = strlen((char*)new_data);
	if (dlc <= MAX_LEN) {
		for(int i=0; i<=dlc; i++)
			data[i]=new_data[i];
	}
}

CanFrame::~CanFrame()
{
	//destructor
}

//////////////////////////////////*accessors*/////////////////////////////////////////////////


void CanFrame::print_frame()
{
	cout << can_id << " ["<< dlc << "] "<< data << endl;
}

 void CanFrame::set_can_id(unsigned int new_id)
{
	if(new_id <= 0x1FFFFFFF)
		can_id = new_id;
	else
		fprintf(stderr, "can_id error\n");
}

unsigned int CanFrame::get_can_id()
{
	return(can_id);
}

void CanFrame::set_dlc(unsigned int new_dlc)
{
	if (new_dlc > 8)
		dlc = 8;
	else
		dlc = new_dlc;
}

unsigned int CanFrame::get_dlc()
{
	return(dlc);
}

void CanFrame::set_data(unsigned char *new_data)
{
	int i, size;
	memset((char*)data, 0, sizeof(data)); //cleaning array
	size = strlen((char*)new_data);

	if (size >= dlc) {
		for(i = 0; i < dlc; i++)
			data[i] = new_data[i];
	}
	else {
		fprintf(stderr, "len data error\n");
	}
}

void CanFrame::set_data(int i, unsigned char new_char) //i this is place in the array
{
	if (i < dlc)
		data[i] = new_char;
	else
		fprintf(stderr, "set data error\n");
}

unsigned char *CanFrame::get_data()
{
	return(data);
}

unsigned char CanFrame::get_data(int i)
{
	if (i < dlc)
		return(data[i]);
	else 
		fprintf(stderr, "get data error\n");
}
