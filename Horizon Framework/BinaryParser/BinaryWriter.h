#pragma once
#include <ostream>

class BinaryWriter final
{
public:
	BinaryWriter(const std::string& outputFile);
	~BinaryWriter();

	template<class T>
	void Write(T value) const
	{
		if (m_pWriter == nullptr)
			return;

		m_pWriter->write((char*)&value, sizeof(T));
	}

	void WriteString(const std::string& string);
	void WriteNullString(const std::string& string);

private:
	void Open(const std::string& outputFile);
	void Close();

	bool m_FileOpen;
	std::ostream* m_pWriter = nullptr;
};