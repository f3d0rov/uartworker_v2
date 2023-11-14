#pragma once

#include <string>

class Interface_Reader {
public:
	virtual void readerInit();
	virtual std::string readSome() = 0;
};


class Interface_Writer {
public:
	virtual void writerInit();
	virtual void write(std::string s) = 0;
};


class Interface_ReaderWriter : public Interface_Reader, public Interface_Writer {};


class Parser_Interface {
	public:
		virtual void parse (std::string input) = 0;
		void parseFrom (Interface_Reader &reader);

		virtual int getA () = 0;
		virtual int getB () = 0;
		virtual int getC () = 0;
};
