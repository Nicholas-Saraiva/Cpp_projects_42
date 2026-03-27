#include <string>
#include <fstream>
#include <iostream>
#include <sys/stat.h>

bool	isDirectory(const char* path)
{
	struct stat s;
	if (stat(path, &s) == 0)
		return (S_ISDIR(s.st_mode));
	return false;
}

int	main(int argc, char *argv[])
{
	std::ifstream	readFile;
	std::ofstream	replaceFile;
	std::string		replaceName;
	std::string		text;

	if (argc != 4)
	{
		std::cerr << "Usage: ./replace <filename> s1 s2" << std::endl;
		return (1);
	}
	if (*argv[2] == '\0')
	{
		std::cerr << "Error: Search string (s1) cannot be empty." << std::endl;
		return (1);	
	}
	if (isDirectory(argv[1]))
	{
		std::cerr << "Error: " << argv[1] << " is a directory.!" << std::endl;
		return (1);
	}
	replaceName = std::string(argv[1]) + ".replace";
	readFile.open(argv[1]);
	if (!readFile.is_open())
	{
		std::cerr << "Error: " << argv[1] << " Could not open!" << std::endl;
		return (1);
	}
	replaceFile.open(replaceName.c_str());
	if (!replaceFile.is_open())
	{
		std::cerr << "Error: " << replaceName << " Cannot be open!" << std::endl;
		return (1);
	}
	while (std::getline(readFile, text))
	{
		size_t i = 1;
		while (i != std::string::npos)
		{
			i = text.find(argv[2]);
			if (i == std::string::npos)
				replaceFile << text;
			else
			{
				replaceFile << text.substr(0, i) << argv[3];
				text = text.substr(i + std::string(argv[2]).size(), text.size());	
			}
			if (text.empty())
				break;
		}
		replaceFile << std::endl;
	}
	return (0);
}