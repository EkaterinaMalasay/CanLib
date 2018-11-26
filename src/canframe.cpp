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


// CanFrame::CanFrame()
// {
// }

CanFrame::CanFrame(unsigned int can_id, unsigned int dlc, char* data)
{
	this->can_id = can_id;
	this->dlc = dlc;
	for(int i=0; i<8; i++)
		this->data[i]=data[i];
}

CanFrame::CanFrame(unsigned int can_id, char *data)
{
	this->can_id = can_id;
	for(int i=0; i<8; i++)
		this->data[i]=data[i];
	dlc = strlen(data);
}

CanFrame::~CanFrame()
{
	///
}


void CanFrame::print_frame()
{
	cout << can_id << " ["<< dlc << "] "<< data << endl;
}

 void CanFrame::set_can_id(unsigned int new_id)
{
	can_id = new_id;
}

unsigned int CanFrame::get_can_id()
{
	return(can_id);
}

unsigned int CanFrame::get_dlc()
{
	return(dlc);
}

void CanFrame::set_data(char *new_data)
{
	int i;
	for(i = 0; i < 8; i++)
		data[i] = new_data[i];
	dlc = strlen(new_data);
}

char* CanFrame::get_data()
{
	return(data);
}
