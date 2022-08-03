#include "TextWriter.h"

TextWriter::TextWriter(const std::string& outputFile)
{
	Open(outputFile);
}

TextWriter::~TextWriter()
{
	Close();
}

void TextWriter::WriteLine()
{
	Write<char>('\n');
}

void TextWriter::Open(const std::string& outputFile)
{
	std::ofstream* const ofstream = new std::ofstream();
	ofstream->open(outputFile, std::ios::out);
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

void TextWriter::Close()
{
	delete m_pWriter;
	m_pWriter = nullptr;
	m_FileOpen = false;
}
