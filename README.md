# Horizon-Framework

## 1. Introduction
Horizon is a framework i made in the summer of 2021. The purpose of the framework was to help with math and parsing.
2. Development
2.1 Math Library
The first part of the horizon framework I made was the math library. I thought which geometry and formulas were used the most during programming. I implemented and ordered those in their own structs. 

The structs of the math library:

• CIrclef

• Rectf

• Point2f

• Vector2f

• Matrix3f

• MathUtilities

As you can see all the structs end on f. I do this to indicate the class is made with floats in mind. Sometime that also stands out is the lack of a Point3f or Matrix4f. The reason for this is primarily that this engine was made with 2D in mind.
 The last mentionable design decision I made is to make Point2f and Vector2f different structs. They could be one struct since the only difference is that Vector2f has more overloaded operators and custom functions, the data between them is the same. I still choice to separate them for clarity and readability. 
Lastly I also made a .h called include that includes all the structs, if the user wants to use all of them in a code file he doesn't need to include them all separately.
## 2.2 TextParser
A generally reusable textParser that exist out of a writer class and reader class seemed very useful to have. I stared again with thinking which base functionality would a textParser need. I started from there and during testing I figured out extra functionality for the class like being able to get the byte size of the reader file. 
The reader and writer also follow the RAII principle. For those who don't know RAII (resource acquisitions) is the technique of automatically destroying objects when they go out of scope. Local objects always get destroyed when they go out of scope but pointers do not. If RAII is applied pointers will also get destroyed.

## 2.3 BinaryParser
Binary parsing is something that can be very tricky. My goal was to make this process easier with a binaryReader class and binaryWriter class. The binaryParser also uses the RAII principle which has already been discussed. 
The user still has to know what information that he needs to parse or wants to write but with templated read and write functions the user should have an easier time with this task.
## 3. Conclusion
The framework was a project that kept my programming abilities fresh in my head during the summer break. It also expanded my math knowledge. Parsing was something I always struggled with and the textParser and BinaryParser drastically improved my parsing skills.
