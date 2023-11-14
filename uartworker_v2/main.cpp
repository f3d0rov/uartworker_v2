/*
Задача:
Приходят данные с трех источников - текстовый файл, USB, UART. Задача программы - принять данные и обработать их в соответствии с правилами
Текстовый файл содержит настройки устройства (3 числовых данных, записанных через символ ';'. Первое число - скорость передачи UART)
По USB приходят данные для обработки
По UART происходит отладка устройства и сообщения о его состоянии
	На UART приходят только два типа сообщений - D (Debug) и I (Info)

*/

#include <iostream>

#include "devices.hpp"

int main() {

	/*reader R;
	writer W;
	parser p;
	R.reader_init();
	p.reader(R.readfromfile());
	R.readFromUART();
	std::cout << "a = " << p.get_a() << " b = " << p.get_b() << " c = " << p.get_c() << std::endl;*/


	std::unique_ptr <Interface_Reader> configSource = std::make_unique <File_ReaderWriter> ();
	configSource->readerInit();

	std::unique_ptr <Interface_Reader> statusReader = std::make_unique <UART_ReaderWriter> ();
	statusReader->readerInit();

	std::unique_ptr <Parser_Interface> parser = std::make_unique <Parser_Impl> ();
	parser->parseFrom (*configSource);

	std::cout << "Status: '" << statusReader->readSome() << "'" << std::endl;
	std::cout << "a = " << parser->getA() << "; b = " << parser->getB() << "; c = " << parser->getC() << std::endl;

	return 0;
}

