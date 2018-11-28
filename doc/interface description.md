class CanInterface
---
#### закрытые типы:
    char intrf_name[15] - имя интерфейса (например: can0)
    int  socket_write   - дескриптор сокета
    int  socket_read    
#### открытые методы:
    CanInterface(unsigned char *name)
    
    int connect() 
    int disconnect()
    
    int get_socket_write()
    int get_socket_read()

    int receive(CanFrame &CanFr) - получение CAN-пакета
    int send(CanFrame &CanFr) - отправляет пакет


class CanFrame
---
#### закрытые типы:
    unsigned int can_id    - уникальный идентификатор
    unsigned int dlc       - длина поля данных в байтах (0-8)
    unsigned char data[8]  - передаваемые данные (длина в поле dlc)

#### открытые методы:
    CanFrame() - создает CAN-пакет со случайными данными
    CanFrame(unsigned int can_id, unsigned int dlc, unsigned char *data)
    CanFrame(unsigned int can_id, unsigned char *data)
    ~CanFrame()
    
    void print_frame() - вывод CAN-пакета
    
    методы аксессоры:
    void set_can_id(unsigned int new_id)
    unsigned int get_can_id()
    
    void set_dlc(unsigned int new_dlc)
    unsigned int get_dlc()
    
    void set_data(unsigned char *new_data)
    unsigned char *get_data()
    void set_data(int i, unsigned char new_char)
    unsigned char get_data(int i)



   
    
