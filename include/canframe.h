#ifndef CANFRAME_H
#define	CANFRAME_H

class CanFrame
{
    unsigned int can_id;
    unsigned int dlc;
    char data[8];
public:
    CanFrame();
    CanFrame(unsigned int can_id, unsigned int dlc, char *data);
    CanFrame(unsigned int can_id, char *data);
    ~CanFrame();
    
    void print_frame();
    
    void set_can_id(unsigned int new_id);
    unsigned int get_can_id();
    
    unsigned int get_dlc();
    
    void set_data(char *new_data);
    char *get_data();
};

#endif	/* CANFRAME_H */

