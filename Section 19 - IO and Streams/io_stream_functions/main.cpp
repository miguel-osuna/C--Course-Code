#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

std::string checkExtension(std::string fileName);
bool readFile(std::string fileName);
bool writeFile(std::string fileName, std::string str);
bool copyFile(std::string oldFile, std::string newFile);
int findWord(std::string fileName, std::string word);
int countWords(std::string fileName);

int main()
{
	std::string oldFile;
	std::string newFile;

	std::cout << "Please enter the name of the you want to copy: ";
	std::cin >> oldFile;

	std::cout << "Please enter the name of the file copy: ";
	std::cin >> newFile; 

	copyFile(oldFile, newFile);

	// readFile(newFile);
	// writeFile(newFile);

	std::string searchWord;
	std::cout << "What word do you want to look for?: ";
	std::cin >> searchWord;

	std::cout << "The word \'" << searchWord << "\' is repeated: " << findWord(newFile, searchWord) << std::endl;
	std::cout << "The file has: " << countWords(newFile) << " words" << std::endl;

	return 0;
}

std::string checkExtension(std::string fileName)
{
	if(fileName.substr(fileName.length() - 4) != ".txt")
		fileName += ".txt";
	return fileName;
}

bool readFile(std::string fileName)
{
	fileName = checkExtension(fileName);
	std::fstream inFile{fileName, std::ios::in};

	if(!inFile)
	{
		std::cerr << "Error opening read file" << std::endl; 
		return false;
	}

	char c;
	while(inFile.get(c))
		std::cout << c;

	inFile.close();
	return true;
}

bool writeFile(std::string fileName, std::string str)
{
	fileName = checkExtension(fileName);
	std::fstream outFile{fileName, std::ios::out};

	if(!outFile)
	{
		std::cerr << "Error opening write file" << std::endl; 
		return false;
	}

	outFile << str;
	outFile.close();
	return true;
}

bool copyFile(std::string oldFile, std::string newFile)
{
	oldFile = checkExtension(oldFile);
	newFile = checkExtension(newFile);

	std::fstream inFile{oldFile, std::ios::in};
	std::fstream outFile{newFile, std::ios::out};

	if(!inFile)
	{
		std::cerr << "Error opening read file" << std::endl;
		return false;
	}

	if(!outFile)
	{
		std::cerr << "Error opening write file" << std::endl;
		return false;
	}

	std::string line;
	int lineNumber{0};
	while(std::getline(inFile, line))
	{
		if(line == "")
			outFile << std::endl;
		else
		{
			lineNumber++;
			outFile << std::setw(10) << std::left << lineNumber << line << std::endl;
		}
	}

	std::cout << "File copied" << std::endl;
	inFile.close();
	outFile.close();
	return true;
}

int findWord(std::string fileName, std::string searchWord)
{
	int wordRep{0};
	std::string currentWord;

	fileName = checkExtension(fileName);
	std::fstream inFile{fileName, std::ios::in};

	if(inFile)
	{
		while(inFile >> currentWord)
		if(currentWord.find(searchWord) != std::string::npos) 
			wordRep++;
	}
	
	inFile.close();
	return wordRep;
}

int countWords(std::string fileName)
{
	int wordNum{};
	std::string wordRead;

	fileName = checkExtension(fileName);
	std::fstream inFile{fileName, std::ios::in};

	if(inFile)
	{
		while(inFile >> wordRead) 
			wordNum++;
	}
	
	inFile.close();
	return wordNum;
}