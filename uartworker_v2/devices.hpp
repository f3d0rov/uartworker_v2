#pragma once

#include "interfaces.hpp"


#define MESSAGEFILE "123;456;789;"
#define MESSAGEUART "D some errors..."
#define MESSAGEUSB "123;456;789;"


class UART_ReaderWriter: public Interface_ReaderWriter {
	private:
		static std::string getMessageType (std::string &msg);
	public:
		virtual void readerInit () override;
		virtual void writerInit () override;


		virtual std::string readSome() override;
		virtual void write(std::string s) override;
};


class File_ReaderWriter: public Interface_ReaderWriter {
	public:
		virtual void readerInit() override;
		virtual void writerInit() override;


		virtual std::string readSome() override;
		virtual void write(std::string s) override;
};


class USB_ReaderWriter: public Interface_ReaderWriter {
	public:
		virtual void readerInit() override;
		virtual void writerInit() override;


		virtual std::string readSome() override;
		virtual void write(std::string s) override;
};



class Parser_Impl: public Parser_Interface {
	private:
		int _a, _b, _c;

		struct NumberParserResult {
			int value;
			int breakPos;
		} getNum (std::string &input, int pos = 0);
	public:
		virtual void parse(std::string input) override;

		int getA() override;
		int getB() override;
		int getC() override;
};
