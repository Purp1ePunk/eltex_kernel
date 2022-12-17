### hello.c
Тестовый модуль для проверки сборки.

Запуск:
1) make
2) insmod

### proc.c
Тестовый модуль для проверки взаимодействия с виртуальной файловой системой proc.
Модуль позволяет записать строку из 10 символов в создаваемый в proc каталог hello_proc.
Пример:

#sudo echo "test123456" > /proc/hello_proc

#cat /proc/hello_proc

test123456

Запуск:
1) make
2) sudo insmod
2) echo "текст"

### keyledmodule.c
Модуль с морганием световых индикаторов на клавиатуре, читающий двоичный код морганий (000 - не горит ни одна, 001 - одна, 111 - все лампочки) из sysfs. Моргание происходит за счет перевода из текущего состояния в 000 и обратно с таймером.

Запуск:
1) make
2) sudo insmod
2) sudo su
3) echo ${Значение от 0 до 7} > /sys/kernel/systest

### netlink_client.c netlink_main.c
Модуль взаимодействия userspace c kernelspace через netlink. Используется модификация интерфейса сокетов.

Запуск:
1) make
После запуска Makefile в директории появятся netlink_client и netlink_main.ko
2) sudo insmod netlink_main.ko
3) ./netlink_client

### test_chardev.c
Модуль для создания символьного драйвера. Работа драйвера заключается в выводе количества чтений dev-файла.

Запуск:
1) make
2) sudo insmod
3) sudo cat /dev/test_chardev
I already told you 12 times Hello world!
