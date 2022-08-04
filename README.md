<p align="center">
<img src="https://www.digitalartsandentertainment.be/dae/images/DAE_headerLogo.png" length=20% width=20%>
</p>
<h1 align="center">Horizon Framework</h1>
<p align="center">A c++ framework containing a small math library and file parser.<br>
<sub>By <a href="https://keanudecru.myportfolio.com/">Keanu Decru</a></sub></p>
<p align="center">
    <a href="https://github.com/DecruKeanu/Horizon-Framework/actions/workflows/msbuild.yml">
        <img src="https://github.com/DecruKeanu/Horizon-Framework/actions/workflows/msbuild.yml/badge.svg">
    </a>
</p>

***

# 1 Introduction
Horizon is a file parsing + math framework i made in the summer of 2021. The main goal of this project was to gain more experience creating reusable frameworks while providing the unit tests to show that the framework works as intended.
# 2 Development
## 2.1 Math Library
The first part of the horizon framework that was made is the math library. I thought which geometry and formulas were used the most during programming. I implemented and ordered those in their own structs. 

The structs of the math library:
 * Ciclef
 * Rectf
 * Point2f
 * Vector2f
 * Matrix3f

There's a consistent naming convention in the structs following the format, indicating what it is, a number to indicate the kind of structure (if needed) and f, to indicate the structs are float-based.

Note that a Vector and a Point are represented with 2 different structs, even though it's technically possible to just use a Vector everywhere. This is done to make the code more explicit. They are 2 different mathematical concepts, and thus are represented with 2 different structs.

Besides these structs, there's also a Math namespace containing general usefull mathematical constant like *pi*, *to_radians* and *to_degrees*. And some usefull functions like *Equal* (for float comparisons) and *FLerp*.

## 2.2 Parsing
The library contains functionality to read and write both text based and binary files, resulting in 4 classes in total. All these follow the [RAII](https://en.cppreference.com/w/cpp/language/raii) principle, to make the code less prone to errors. The parsers use templates to make them easilly usable with different forms of input.

### 2.2.1 Text
The text parsers are relatively simple. All the basic expected functionality (read, readline, write, writeline) is ther. On top of that, there's a function to display useful information about the file to the console. But perhaps more important, the parsers are capable of using regex expressions to search through the files and find matching text, this makes parsing files in a certain format very easy.

Example of writing to a file:
```c++
TextWriter basicWriter(filePath);
basicWriter.WriteLine<std::string>("Example");
basicWriter.Write<char>('E');
```

Example of reading from a file:
```c++
TextReader basicReader(filePath);
const std::string firstLine = basicReader.ReadLine();
const char ECharacter = basicReader.ReadCharacter();
```

### 2.2.2 Binary
The binary reader and writer use templates to automatically write the correct amount of bytes to a certain file. On top of that, there's functionality to store strings, this is done by writing the length of the string, followed by all the characters.

## 2.3 Unit tests
[Catch 2](https://github.com/catchorg/Catch2) was used to test the code in the framework. Using unit tests has a lot of advantages, the main ones being:
 * Bugs are faster to find
 * The programmers are forced to think about edge-cases
 * If a change unexpectedly alters previously correct behavior, it's instantly noticed
 See below for an example of a unit test, testing if the `IsPointInCircle` function works as expected.
```c++
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
```
# 3 Conclusion
The framework was a project that kept my programming abilities fresh during the summer break. It also expanded my math knowledge. Parsing was something I always struggled with and the TextParser and BinaryParser drastically improved my parsing skills.
