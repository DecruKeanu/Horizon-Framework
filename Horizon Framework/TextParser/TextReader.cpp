#include "TextReader.h"
#include <iostream>
#include <string>
#include <filesystem>

TextReader::TextReader(const std::string& textFile) :
	m_FileName{ textFile },
	m_FileValid{ false }
{
	Open(textFile);
}

TextReader::~TextReader()
{
	Close();
}

char TextReader::ReadCharacter()
{
	char character;
	m_pReader->get(character);
	return character;
}

std::string TextReader::Read(int size)
{
	std::string line;
	line.resize(size);
	m_pReader->read(&line[0], size);

	return line;
}

std::string TextReader::ReadLine()
{
	std::string line;
	const int bit = m_pReader->peek();
	if (bit == -1)
	{
		m_pReader->setstate(std::ios_base::eofbit);
		return "";
	}

	std::getline(*m_pReader, line);
	return line;
}

bool TextReader::CheckIfLineIsNotEof()
{
	std::string line;
	const int bit = m_pReader->peek();
	if (bit == -1)
	{
		m_pReader->setstate(std::ios_base::eofbit);
		return false;
	}

	std::getline(*m_pReader, line);
	return true;
}

RegexMatch TextReader::RegexMatchLine(const std::string& regex)
{
	RegexMatch regexMatch;
	const std::string line = ReadLine();
	const std::regex searchRegex(regex);

	std::smatch smatch;
	std::regex_match(line, smatch, searchRegex);

	for (int idx{}; idx < smatch.size(); idx++)
	{
		if (idx == 0)
			regexMatch.match = (smatch[idx].str());
		else
			regexMatch.captureGroupsVector.push_back(smatch[idx].str());
	}

	return regexMatch;
}

std::vector<RegexMatch> TextReader::RegexMatchFile(const std::string& regex)
{
	std::vector<RegexMatch> regexMatches;
	const int filePos = GetFilePosition();
	const std::regex searchRegex(regex);

	SetFilePosition(0);

	std::vector<std::smatch> smatches;
	while (m_pReader->eof() == false)
	{
		std::smatch smatch;
		const std::string line = ReadLine();
		std::regex_match(line, smatch, searchRegex);

		if (smatch.empty() == false)
		{
			RegexMatch regexMatch;

			for (int idx{}; idx < smatch.size(); idx++)
			{
				if (idx == 0)
					regexMatch.match = (smatch[idx].str());
				else
					regexMatch.captureGroupsVector.push_back(smatch[idx].str());
			}

			regexMatches.push_back(regexMatch);
		}
	}

	SetFilePosition(filePos);
	return regexMatches;
}

int TextReader::GetFilePosition() const
{
	if (m_FileValid)
		return static_cast<int>(m_pReader->tellg());

	return -1;
}

bool TextReader::SetFilePosition(int newPos)
{
	if (m_pReader)
	{
		m_pReader->seekg(newPos);

		return true;
	}

	return false;
}

void TextReader::MoveFilePosition(int moveDistance)
{
	SetFilePosition(GetFilePosition() + moveDistance);
}

int TextReader::GetCurrentLine() const
{
	return int(std::count(std::istream_iterator<char>(*m_pReader), std::istream_iterator<char>(), '\n'));
}

int TextReader::GetAmountOfLines()
{
	int amountOfLines{};
	const int filePos = GetFilePosition();
	SetFilePosition(0);

	std::string line;
	while (CheckIfLineIsNotEof())
	{
		amountOfLines++;
	}
	SetFilePosition(filePos);
	return amountOfLines;
}

bool TextReader::SetCurrentLine(int newLine)
{
	SetFilePosition(0);
	std::string line;

	for (int idx{}; idx < newLine; idx++)
	{
		std::getline(*m_pReader, line);
		return true;
	}
	return false;
}

void TextReader::MoveCurrentLine(int moveDistance)
{
	SetCurrentLine(GetCurrentLine() + moveDistance);
}

uintmax_t TextReader::GetFileByteSize() const
{
	return std::filesystem::file_size(m_FileName);
}

bool TextReader::IsFileValid() const
{
	return m_FileValid;
}

void TextReader::LogFileInformation()
{
	std::cout << "Name of file: " << m_FileName << std::endl;
	std::cout << "Amount of filled lines: " << std::to_string(GetAmountOfLines()) << std::endl;
	std::cout << "Bytesize of file: " << std::to_string(GetFileByteSize()) << std::endl;
}

void TextReader::Open(const std::string& textFile)
{
	std::ifstream* const ifstream = new std::ifstream();
	ifstream->open(textFile, std::ios::in);
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

void TextReader::Close()
{
	delete m_pReader;
	m_pReader = nullptr;
	m_FileValid = false;
}
