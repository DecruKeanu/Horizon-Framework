#include <filesystem>
#include <iostream>
#include "Math/Includes.h"
#include "TextParser/Includes.h"
#define CATCH_CONFIG_MAIN
#include "Catch/catch.hpp"
#include <string_view>
#pragma warning (disable: 6262)

constexpr std::string_view TEMP_FILES_PATH = "TempFiles/";

TEST_CASE("Math EQUAL")
{
	const float value1{ 500.f };
	const float value2{ 200.f * 2.5f };
	REQUIRE(Math::Equal(value1, value2));
}

TEST_CASE("Point in rect")
{
	{
		const Math::Point2f testPoint = Math::Point2f{ 50,50 };
		const Math::Rectf testRect = { Math::Point2f{20,20},{20,20} };
		REQUIRE(Math::IsPointInRect(testRect, testPoint) == false);
	}

	{
		const Math::Point2f testPoint = Math::Point2f{ 30,30 };
		const Math::Rectf testRect = { Math::Point2f{20,20},{20,20} };
		REQUIRE(Math::IsPointInRect(testRect, testPoint) == true);
	}
}

TEST_CASE("Rect overlap with rect")
{
	{
		const Math::Rectf firstRect = Math::Rectf{ Math::Point2f{-20,-20},Math::Vector2f{20,20} };
		const Math::Rectf secondRect = Math::Rectf{ Math::Point2f{20,20},Math::Vector2f{20,20} };
		REQUIRE(Math::DoesRectOverlapWithRect(firstRect, secondRect) == false);
	}

	{
		const Math::Rectf firstRect = Math::Rectf{ Math::Point2f{0,0},Math::Vector2f{20,20} };
		const Math::Rectf secondRect = Math::Rectf{ Math::Point2f{20,20},Math::Vector2f{20,20} };
		REQUIRE(Math::DoesRectOverlapWithRect(firstRect, secondRect) == true);
	}

	{
		const Math::Rectf firstRect = Math::Rectf{ Math::Point2f{10,10},Math::Vector2f{20,20} };
		const Math::Rectf secondRect = Math::Rectf{ Math::Point2f{20,20},Math::Vector2f{20,20} };
		REQUIRE(Math::DoesRectOverlapWithRect(firstRect, secondRect) == true);
	}
}

TEST_CASE("Point in Circle")
{
	{
		const Math::Point2f testPoint = Math::Point2f{ 50,50 };
		const Math::Circlef testCircle = { Math::Point2f{20,20},20 };
		REQUIRE(Math::IsPointInCircle(testCircle, testPoint) == false);
	}

	{
		const Math::Point2f testPoint = Math::Point2f{ 30,30 };
		const Math::Circlef testCircle = { Math::Point2f{20,20},20 };
		REQUIRE(Math::IsPointInCircle(testCircle, testPoint) == true);
	}
}

TEST_CASE("Circle overlap with Circle")
{
	{
		const Math::Circlef firstCircle = { Math::Point2f{-30,-30},20 };
		const Math::Circlef secondCircle = { Math::Point2f{20,20},20 };
		REQUIRE(Math::DoesCircleOverlapWithCircle(firstCircle, secondCircle) == false);
	}

	{
		const Math::Circlef firstCircle = { Math::Point2f{0,0},20 };
		const Math::Circlef secondCircle = { Math::Point2f{20,20},20 };
		REQUIRE(Math::DoesCircleOverlapWithCircle(firstCircle, secondCircle) == true);
	}

	{
		const Math::Circlef firstCircle = { Math::Point2f{10,10},20 };
		const Math::Circlef secondCircle = { Math::Point2f{20,20},20 };
		REQUIRE(Math::DoesCircleOverlapWithCircle(firstCircle, secondCircle) == true);
	}
}

TEST_CASE("Vector magnitude")
{
	{
		const Math::Vector2f testVector = Math::Vector2f{ 4.f,0.f };
		const float magnitude = Math::Magnitude(testVector);
		REQUIRE(magnitude == 4.0f);
	}

	{
		const Math::Vector2f testVector = Math::Vector2f{ 0.f,6.f };
		const float magnitude = Math::Magnitude(testVector);
		REQUIRE(magnitude == 6.0f);
	}
}

TEST_CASE("Vector squared magnitude")
{
	{
		const Math::Vector2f testVector = Math::Vector2f{ 4.f,0.f };
		const float magnitude = Math::SquaredMagnitude(testVector);
		REQUIRE(magnitude == Math::Square(4.f));
	}

	{
		const Math::Vector2f testVector = Math::Vector2f{ 0.f,6.f };
		const float magnitude = Math::SquaredMagnitude(testVector);
		REQUIRE(magnitude == Math::Square(6.f));
	}
}

TEST_CASE("Vector normalize")
{
	{
		const Math::Vector2f testVector = Math::Vector2f{ 4.f,0.f };
		const Math::Vector2f normalizedVector = Math::Normalize(testVector);
		REQUIRE((normalizedVector.x == 1.f && normalizedVector.y == 0.f));
	}

	{
		const Math::Vector2f testVector = Math::Vector2f{ 0.f,4.f };
		const Math::Vector2f normalizedVector = Math::Normalize(testVector);
		REQUIRE((normalizedVector.x == 0.f && normalizedVector.y == 1.f));
	}
}

TEST_CASE("Vector dot")
{
	{
		const Math::Vector2f firstVector = Math::Vector2f{ 2.f,4.f };
		const Math::Vector2f secondVector = Math::Vector2f{ 4.f,2.f };
		const float dotValue = Math::Dot(firstVector, secondVector);
		REQUIRE(dotValue == 16.f);
	}

	{
		const Math::Vector2f firstVector = Math::Vector2f{ 20.f,36.f };
		const Math::Vector2f secondVector = Math::Vector2f{ 69.f,420.f };
		const float dotValue = Math::Dot(firstVector, secondVector);
		REQUIRE(dotValue == 16500.f);
	}
}

TEST_CASE("Vector cross")
{
	{
		const Math::Vector2f firstVector = Math::Vector2f{ 47.f,-110.f };
		const Math::Vector2f secondVector = Math::Vector2f{ 169.f,-88.f };
		const float crossValue = Math::Cross(firstVector, secondVector);
		REQUIRE(crossValue == 14454.f);
	}

	{
		const Math::Vector2f firstVector = Math::Vector2f{ 102.f,-103.f };
		const Math::Vector2f secondVector = Math::Vector2f{ 0.f,-128.f };
		const float crossValue = Math::Cross(firstVector, secondVector);
		REQUIRE(crossValue == -13056.f);
	}
}

TEST_CASE("Matrix equals")
{
	const Math::Matrix3f firstMatrix = Math::MakeTranslationMatrix(Math::Point2f{ 10.f,20.f }) * Math::MakeRotationMatrix(40.f);
	const Math::Matrix3f secondMatrix = firstMatrix;

	REQUIRE(firstMatrix == secondMatrix);
}

TEST_CASE("Matrix Determinant")
{
	const Math::Matrix3f testMatrix = Math::Matrix3f(25.f, 14.f, 32.f, 50.f, 59.f, 420.f, 78.f, 98.f, 64.f);
	const float determinant = Math::Determinant(testMatrix);

	REQUIRE(determinant == -511224.f);
}

TEST_CASE("Matrix Multiplication")
{
	const Math::Matrix3f firstMatrix = Math::Matrix3f(10.f, 20.f, 30.f, 40.f, 50.f, 60.f, 70.f, 80.f, 90.f);
	const Math::Matrix3f secondMatrix = Math::Matrix3f(100.f, 110.f, 120.f, 130.f, 140.f, 150.f, 160.f, 170.f, 180.f);
	const Math::Matrix3f productMatrix = firstMatrix * secondMatrix;

	REQUIRE(productMatrix.data[0][0] == 8400.f);
	REQUIRE(productMatrix.data[0][1] == 9000.f);
	REQUIRE(productMatrix.data[0][2] == 9600.f);
	REQUIRE(productMatrix.data[1][0] == 20100.f);
	REQUIRE(productMatrix.data[1][1] == 21600.f);
	REQUIRE(productMatrix.data[1][2] == 23100.f);
	REQUIRE(productMatrix.data[2][0] == 31800.f);
	REQUIRE(productMatrix.data[2][1] == 34200.f);
	REQUIRE(productMatrix.data[2][2] == 36600.f);
}

TEST_CASE("Basic reading and writing")
{
	std::filesystem::create_directory( TEMP_FILES_PATH );
	std::string filePath{std::string(TEMP_FILES_PATH.data()) + "BasicFile.txt"};
	{
		TextWriter basicWriter(filePath);
		basicWriter.WriteLine<std::string>("Example");
		basicWriter.WriteLine<std::string>("Exam");
		basicWriter.Write<char>('E');
		basicWriter.Write<char>('x');
		basicWriter.Write<std::string>("ogol");
		basicWriter.Write<char>('\n');
	}

	{
		TextReader basicReader(filePath);
		const std::string firstLine = basicReader.ReadLine();
		const std::string secondLine = basicReader.ReadLine();

		basicReader.SetFilePosition(0);
		const std::string thirdLine = basicReader.ReadLine();

		const char ECharacter = basicReader.ReadCharacter();
		const char XCharacter = basicReader.ReadCharacter();
		const char ACharacter = basicReader.ReadCharacter();
		const char MCharacter = basicReader.ReadCharacter();
		const char EndCharacter = basicReader.ReadCharacter();

		basicReader.SetFilePosition(0);
		const std::string EXString = basicReader.Read(2);
		const std::string AMString = basicReader.Read(2);
		const std::string PLEString = basicReader.Read(4);
		basicReader.SetFilePosition(15);
		const std::string ExogolString = basicReader.ReadLine();

		REQUIRE(firstLine == "Example");
		REQUIRE(secondLine == "Exam");
		REQUIRE(thirdLine == "Example");
		REQUIRE(ECharacter == 'E');
		REQUIRE(XCharacter == 'x');
		REQUIRE(ACharacter == 'a');
		REQUIRE(MCharacter == 'm');
		REQUIRE(EndCharacter == '\n');

		REQUIRE(EXString == "Ex");
		REQUIRE(AMString == "am");
		REQUIRE(PLEString == "ple\n");
		REQUIRE(ExogolString == "Exogol");
	}
}

TEST_CASE("Lesson 1: An Introduction, and the ABCs")
{
	std::filesystem::create_directory( TEMP_FILES_PATH );
	std::string filePath{std::string(TEMP_FILES_PATH.data()) + "Lesson1.txt"};
	{
		TextWriter regexWriter(filePath);
		regexWriter.WriteLine<std::string>("abcdefg");
		regexWriter.WriteLine<std::string>("abcde");
		regexWriter.WriteLine<std::string>("");
		regexWriter.WriteLine<std::string>("abc");
	}

	{
		TextReader regexReader(filePath);
		regexReader.LogFileInformation();
		auto test = regexReader.RegexMatchFile("abc.*");

		for (RegexMatch match : test)
		{
			std::cout << "line that matches: " << match.match << "\n";
		}

		regexReader.SetCurrentLine(1);
		const std::string line = regexReader.ReadLine();
		REQUIRE(line == "abcde");
	}
}
