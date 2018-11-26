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
// 	can_id = 
// }

CanFrame::CanFrame(unsigned int can_id, unsigned int dlc, unsigned char* data)
{
	printf("in %s\n", data);
	this->can_id = can_id;
	this->dlc = dlc;
	for(int i=0;i<dlc;i++)
	{
		this->data[i]=data[i];
		printf("%c\n", data[i]);
	}
	printf("in %s\n", data);
}

CanFrame::CanFrame(unsigned int can_id, unsigned char *data)
{
	this->can_id = can_id;
	//this->data=data;
}

CanFrame::~CanFrame()
{
	///
}


void CanFrame::print_frame()
{
	cout << can_id << " ["<< dlc << "] "<< data << endl;
}

 void CanFrame::set_can_id(unsigned int id)
{
	can_id = id;
}

unsigned int CanFrame::get_can_id()
{
	return(can_id);
}


unsigned int CanFrame::get_dlc()
{
	return(dlc);
}
    
// void CanFrame::set_data(unsigned char *data)
// {
// 	this->dlc = dlc;
// }

unsigned char* CanFrame::get_data()
{
	return(data);
}
