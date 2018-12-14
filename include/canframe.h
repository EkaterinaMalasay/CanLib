#ifndef CANFRAME_H
#define	CANFRAME_H

#define MAX_LEN 8

class CanFrame
{
    unsigned int can_id;
    unsigned int dlc;
    unsigned char data[9];
public:
    CanFrame();
    CanFrame(unsigned int can_id, unsigned int new_dlc, unsigned char *new_data);
    CanFrame(unsigned int can_id, unsigned char *new_data);
    ~CanFrame();
    
    void print_frame();
    
    void set_can_id(unsigned int new_id);
    unsigned int get_can_id();
    
    void set_dlc(unsigned int new_dlc);
    unsigned int get_dlc();
    
    void set_data(unsigned char *new_data);
    void set_data(int i, unsigned char new_char);
    unsigned char *get_data();
    unsigned char get_data(int i);
};

#endif	/* CANFRAME_H */

