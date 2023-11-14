
#include "interfaces.hpp"

void Interface_Reader::readerInit () {}

void Interface_Writer::writerInit () {}


void Parser_Interface::parseFrom(Interface_Reader& reader) {
	this->parse (reader.readSome());
}
