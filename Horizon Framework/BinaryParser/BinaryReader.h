#pragma once
#include <istream>

class BinaryReader final
{
public:
	BinaryReader(const std::string& binaryFile);
	~BinaryReader();

	template<class T>
	T Read() const
	{
		if (m_pReader == nullptr)
			return T();

		T value;
		m_pReader->read((char*)&value, sizeof(T));
		return value;
	}

	std::string ReadString() const;
	std::string ReadNullString() const;

	int GetFilePosition() const;
	bool SetFilePosition(int newPos);
	void MoveFilePosition(int moveDistance);
	bool IsFileValid() const;
private:
	void Open(const std::string& binaryFile);
	void Close();

	bool m_FileValid;
	std::istream* m_pReader = nullptr;
};