#ifndef CANFRAME_H
#define	CANFRAME_H

class CanFrame
{
    unsigned int can_id;
    unsigned int dlc;
    unsigned char data[8];
public:
    CanFrame();
    CanFrame(unsigned int can_id, unsigned int dlc, unsigned char *data);
    CanFrame(unsigned int can_id, unsigned char *data);
    ~CanFrame();
    
    void print_frame();
    
    void set_can_id(unsigned int new_id);
    unsigned int get_can_id();
    
    unsigned int get_dlc();
    
    void set_data(unsigned char *new_data);
    unsigned char *get_data();
};

#endif	/* CANFRAME_H */

