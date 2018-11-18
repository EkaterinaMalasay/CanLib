class CanFrame
---
#### закрытые типы:
    unsigned int can_id
    unsigned char data[8]
#### открытые методы:
    CanFrame()
    ~CanFrame()
    
    int generate() - создает случайный CAN-пакет
    
    методы аксессоры:
    void set_CanId(unsigned int id)
    unsigned int get_CanId()
    void set_data(unsigned char *data)
    unsigned char *get_data()

    
class SendFrame 
---
#### закрытые типы:
    frame - обьект класса CanFrame
    double time - время отправки CAN-пакета
#### открытые методы:
    int send(CanFrame frame) - отправляет пакет, в случае удачной отправки возвращает 0, иначе -1
    int input_frame() - создание CAN-пакета
    int get_time()



class ReceiveFrame
---
#### закрытые типы:
    frame - обьект класса CanFrame
    double time - время получения CAN-пакета
#### открытые функции:
    void reading() - чтение с шины CAN-пакетов
    int receive() - получение CAN-пакета
    void print_frame() - вывод полученного CAN-пакета
    int get_time()
    
