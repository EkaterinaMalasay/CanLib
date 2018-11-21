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
    void set_can_id(unsigned int id)
    unsigned int get_can_id()
    
    void set_dlc(unsigned int dlc)
    unsigned int get_dlc()
    
    void set_data(unsigned char *data)
    unsigned char *get_data()

    
class SenderFrame 
---
#### закрытые типы:
    CanInterface *CanIntrf
    uint64_t time - время отправки CAN-пакета
#### открытые методы:
    int send(CanFrame *frame) - отправляет пакет, в случае удачной отправки возвращает 0, иначе -1

    double get_time()



class ReceiverFrame
---
#### закрытые типы:
    CanInterface *CanIntrf
    uint64_t time - время получения CAN-пакета
#### открытые функции:
    int receive(CanFrame *frame) - получение CAN-пакета
    double get_time()
    
    ?  void queue_building(CanFrame *frame) - построение очереди входящих пакетов

   
    
