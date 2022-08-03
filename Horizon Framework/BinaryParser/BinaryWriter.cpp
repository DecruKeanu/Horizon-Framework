#include "BinaryWriter.h"
#include <fstream>

BinaryWriter::BinaryWriter(const std::string& outputFile) :
	m_FileOpen{false}
{
	Open(outputFile);
}

BinaryWriter::~BinaryWriter()
{
	Close();
}

void BinaryWriter::WriteString(const std::string& string)
{
	const int stringSize = string.size();

	m_pWriter->write((const char*)&stringSize, sizeof(stringSize));
	m_pWriter->write(string.c_str(), stringSize);
}

void BinaryWriter::WriteNullString(const std::string& string)
{
	m_pWriter->write(string.c_str(), string.size());
	m_pWriter->write((const char*)'\0', sizeof(char));
}

void BinaryWriter::Open(const std::string& outputFile)
{
	std::ofstream* const ofstream = new std::ofstream();
	ofstream->open(outputFile, std::ios::out | std::ios::binary);
	if (ofstream->is_open())
	{
		m_pWriter = ofstream;
		m_FileOpen = true;
	}
	else
	{
		Close();
	}
}

void BinaryWriter::Close()
{
	delete m_pWriter;
	m_pWriter = nullptr;
	m_FileOpen = false;
}
