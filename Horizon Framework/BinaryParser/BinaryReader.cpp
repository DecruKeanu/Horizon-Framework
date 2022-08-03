#include "BinaryReader.h"
#include <fstream>
#include <sstream>

BinaryReader::BinaryReader(const std::string& binaryFile) :
	m_FileValid{false}
{
	Open(binaryFile);
}

BinaryReader::~BinaryReader()
{
	Close();
}

std::string BinaryReader::ReadString() const
{
	if (!m_FileValid)
		return "";

	const int stringLength = (int)Read<char>();

	std::stringstream ss;
	for (int i = 0; i < stringLength; ++i)
	{
		ss << Read<char>();
	}
	
	return ss.str();
}

std::string BinaryReader::ReadNullString() const
{
	if (!m_FileValid)
		return "";

	std::string line;
	std::getline(*m_pReader, line, '\0');

	return line;
}

int BinaryReader::GetFilePosition() const
{
	if (m_FileValid)
		return static_cast<int>(m_pReader->tellg());

	return -1;
}

bool BinaryReader::SetFilePosition(int newPos)
{
	if (m_pReader)
	{
		m_pReader->seekg(newPos);
		return true;
	}

	return false;
}

void BinaryReader::MoveFilePosition(int moveDistance)
{
	SetFilePosition(GetFilePosition() + moveDistance);
}

bool BinaryReader::IsFileValid() const
{
	return m_FileValid;
}

void BinaryReader::Open(const std::string& binaryFile)
{
	std::ifstream* const ifstream = new std::ifstream();
	ifstream->open(binaryFile, std::ios::in | std::ios::binary);
	if (ifstream->is_open())
	{
		m_pReader = ifstream;
		m_FileValid = true;
	}
	else
	{
		Close();
	}
}

void BinaryReader::Close()
{
	delete m_pReader;
	m_pReader = nullptr;
	m_FileValid = false;
}