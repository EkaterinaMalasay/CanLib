class CanFrame
---
#### закрытые типы:
    unsigned int can_id
    unsigned char data[8]
#### открытые методы:
    CanFrame()
    ~CanFrame
    
    set_can_id()
    get_can_id()
    set_data()
    get_data()

    generate() - создает случайный CAN-пакет

class SendFrame 
---
#### закрытые типы:
    frame - обьект класса CanFrame
    struct timeval timestamp - время отправки CAN-пакета
#### открытые методы:
    int send(CanFrame frame) - отправляет пакет, в случае удачной отправки возвращает 0, иначе -1
    int input_frame() - создание CAN-пакета
    int get_time()



class ReceiveFrame
---
#### закрытые типы:
    frame - обьект класса CanFrame
    struct timeval timestamp - время получения CAN-пакета
#### открытые функции:
    void reading() - чтение с шины CAN-пакетов
    int receive() - получение CAN-пакета
    void print_frame() - вывод полученного CAN-пакета
    int get_time()
    
