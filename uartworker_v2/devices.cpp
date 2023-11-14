
#include "devices.hpp"

#include <iostream>

std::string UART_ReaderWriter::getMessageType(std::string &msg) {
	switch (msg[0]) {
		case 'D': return "debug";
		case 'I': return "info";
		default: return "mistyped";
	}
}


void UART_ReaderWriter::readerInit () {
	std::cout << "UART_ReaderWriter::readerInit ()" << std::endl;
}

void UART_ReaderWriter::writerInit () {
	std::cout << "UART_ReaderWriter::writerInit ()" << std::endl;
}

std::string UART_ReaderWriter::readSome() {
	std::string msg = MESSAGEUART;
	std::string type = UART_ReaderWriter::getMessageType (msg);
	std::cout << "reading from UART " << type << " message: '" << msg << "'" << std::endl;
	return msg;
}

void UART_ReaderWriter::write(std::string s) {
	std::cout << "Writing to UART '" << s << "'" << std::endl;
}





void File_ReaderWriter::readerInit() {
	std::cout << "File_ReaderWriter::readerInit ()" << std::endl;
}

void File_ReaderWriter::writerInit() {
	std::cout << "File_ReaderWriter::writerInit ()" << std::endl;
}

std::string File_ReaderWriter::readSome() {
	std::cout << "Reading from file: '" << MESSAGEFILE << "'" << std::endl;
	return MESSAGEFILE;
}

void File_ReaderWriter::write(std::string s) {
	std::cout << "Writing to file: '" << s << "'" << std::endl;
}




void USB_ReaderWriter::readerInit () {
	std::cout << "USB_ReaderWriter::readerInit ()" << std::endl;
}

void USB_ReaderWriter::writerInit () {
	std::cout << "USB_ReaderWriter::writerInit ()" << std::endl;
}

std::string USB_ReaderWriter::readSome() {
	std::cout << "Reading from USB: '" << MESSAGEUSB << "'" << std::endl;
	return MESSAGEUSB;
}

void USB_ReaderWriter::write(std::string s) {
	std::cout << "Writing to USB: '" << s << "'" << std::endl;
}



struct Parser_Impl::NumberParserResult Parser_Impl::getNum (std::string &input, int pos) {
	if (pos >= input.length()) throw std::runtime_error ("Parser_Impl::getNum получил pos >= input.length()");

	int nextBreak = input.find (';', pos);
	if (nextBreak == input.npos) nextBreak = input.length();

	Parser_Impl::NumberParserResult result{};
	result.breakPos = nextBreak;
	result.value = 0;

	for (int i = pos; i < nextBreak; i++) {
		int digit = static_cast <int> (input[i] - '0');
		if (digit < 0 || digit > 9) throw std::runtime_error (std::string("Невозможно преобразовать символ '") + input[i] + "' в число");
		result.value = result.value * 10 + digit;
	}
	
	return result;
}

void Parser_Impl::parse(std::string input) {
	auto result = this->getNum (input, 0);
	this->_a = result.value;
	result = this->getNum (input, result.breakPos + 1);
	this->_b = result.value;
	result = this->getNum (input, result.breakPos + 1);
	this->_c = result.value;
}

int Parser_Impl::getA() {
	return this->_a;
}

int Parser_Impl::getB() {
	return this->_b;
}

int Parser_Impl::getC() {
	return this->_c;
}

