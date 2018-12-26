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

CanFrame::CanFrame(unsigned int new_can_id, unsigned int new_dlc, unsigned char*new_data)
{
	if ( new_data != NULL ) {
		if(new_can_id <= 0x1FFFFFFF) {
			can_id = new_can_id;
			if (new_dlc > 0 && new_dlc <= MAX_LEN) {
				if (strlen((char*)new_data) == new_dlc) {
					dlc = new_dlc;
					for(int i=0; i<=dlc; i++)
						data[i]=new_data[i];
				}
			}
			else {
				fprintf(stderr, "dlc data error\n");
			}
		}
	}
}

/*this constructor automatically fills the field dlc*/
CanFrame::CanFrame(unsigned int new_can_id, unsigned char *new_data)
{
	int size = 0;
	if ( new_data != NULL ) {
		if(new_can_id <= 0x1FFFFFFF) {
			can_id = new_can_id;
			dlc = strlen((char*)new_data);
			if ( dlc <= MAX_LEN && dlc > 0) {
				for(int i=0; i<=dlc; i++)
					data[i]=new_data[i];
			}
		}
	}
}

CanFrame::~CanFrame()
{
	//destructor
}

//////////////////////////////////*accessors*/////////////////////////////////////////////////


void CanFrame::print_frame()
{
	cout << can_id << " ["<< dlc << "] ";
	for(int i = 0; i<dlc; i++)
		cout << data[i];
	cout << '\n';
}

int CanFrame::set_can_id(unsigned int new_id)
{
	if(new_id <= 0x1FFFFFFF) {// 32 bit
		can_id = new_id;
		return 0;
	}
	else {
		fprintf(stderr, "can_id error\n");
		return -1;
	}
}

unsigned int CanFrame::get_can_id()
{
	return(can_id);
}

int CanFrame::set_dlc(unsigned int new_dlc)
{
	if (new_dlc <= 0) {
		fprintf(stderr,
			"dlc error: dlc cannot be less than or equal to 0\n");
		return -1;
	}
	else if (new_dlc > MAX_LEN) {
		fprintf(stderr,
			"dlc warning: dlc was more than MAX_LEN, but now it is 8\n");
		dlc = MAX_LEN;
	}
	else
		dlc = new_dlc;
	return 0;
}

unsigned int CanFrame::get_dlc()
{
	return(dlc);
}

int CanFrame::set_data(unsigned char *new_data)
{
	int i, size;
	if ( new_data != NULL) {
		memset((char*)data, 0, sizeof(data)); //cleaning array
		size = strlen((char*)new_data);

		if (size >= dlc) {
			for(i = 0; i < dlc; i++)
				data[i] = new_data[i];
		}
		else {
			fprintf(stderr, "len data error\n");
			return -1;
		}
		return 0;
	}
	else fprintf(stderr, "NULL data pointer error\n");
	return -1;
}

int CanFrame::set_data(int i, unsigned char new_char) //i this is place in the array
{
	if (i < dlc && i>=0) {
		data[i] = new_char;
		return 0;
	}
	else {
		fprintf(stderr, "set data error\n");
		return -1;
	}
}

unsigned char *CanFrame::get_data()
{
	return(data);
}

unsigned char CanFrame::get_data(int i)
{
	if (i < dlc && i>=0)
		return(data[i]);
	else 
		fprintf(stderr, "get data error\n");
	return -1;
}


