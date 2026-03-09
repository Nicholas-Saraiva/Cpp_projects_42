#include <string>
#include <fstream>
#include <iostream>

int	main(int argc, char *argv[])
{
	std::ifstream	readFile;
	std::ofstream	replaceFile;
	std::string		replaceName;
	std::string		text;

	if (argc != 4)
	{
		std::cout << "./replace <filename> s1 s2" << std::endl;
		return (1);
	}
	readFile.open(argv[1]);
	if (!readFile)
	{
		std::cout << "Invalid File!" << std::endl;
		return (1);
	}
	replaceFile.open(std::string(argv[1]).append(".replace").c_str());
	while (std::getline(readFile, text))
	{
		if (!readFile.is_open())
		{
			std::cout << "Cannot open File" << std::endl;
			return (1);
		}
		size_t i = 1;
		while (i != std::string::npos)
		{
			i = text.find(argv[2]);
			if (i == std::string::npos)
				replaceFile << text;
			else
				replaceFile << text.substr(0, i) << argv[3];
			text = text.substr(i + std::string(argv[3]).size(), text.size()); 
		}
		replaceFile << std::endl;
	}
}