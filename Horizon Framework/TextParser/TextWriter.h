#pragma once
#include <ostream>
#include <fstream>

class TextWriter final
{
public:
	TextWriter(const std::string& outputFile);
	~TextWriter();

	template<class T>
	void Write(T value) const
	{
		if (m_pWriter == nullptr)
			return;

		*m_pWriter << value;
	}

	void WriteLine();
	template<class T>
	void WriteLine(T value) const
	{
		Write<T>(value);
		Write<char>('\n');
	}

private:
	void Open(const std::string& outputFile);
	void Close();

	bool m_FileOpen;
	std::ostream* m_pWriter = nullptr;
};
