#pragma once
#include <istream>
#include <fstream>
#include <sstream>
#include <regex>
#include <vector>

//returning std::smatch results into an internal dangling pointer (string goes out of scope)
//RegexMatch is a workaround to that problem
//https://stackoverflow.com/a/51709911
struct RegexMatch
{
	std::string match;
	std::vector<std::string> captureGroupsVector;
};

class TextReader final
{
public:
	TextReader(const std::string& textFile);
	~TextReader();

	template<class T>
	T Read() const
	{
		if (m_pReader == nullptr)
			return T();

		T value;
		*m_pReader >> value;
		return value;
	}

	char ReadCharacter();
	std::string Read(int size);
	std::string ReadLine();
	bool CheckIfLineIsNotEof();

	RegexMatch RegexMatchLine(const std::string& regex);
	std::vector<RegexMatch> RegexMatchFile(const std::string& regex);

	int GetFilePosition() const;
	bool SetFilePosition(int newPos);
	void MoveFilePosition(int moveDistance);
	
	int GetCurrentLine() const;
	int GetAmountOfLines();
	bool SetCurrentLine(int newLine);
	void MoveCurrentLine(int moveDistance);

	uintmax_t GetFileByteSize() const;
	bool IsFileValid() const;

	void LogFileInformation();

private:
	void Open(const std::string& textFile);
	void Close();

	bool m_FileValid;
	std::string m_FileName;
	std::istream* m_pReader = nullptr;
};