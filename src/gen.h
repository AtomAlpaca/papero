#include <iostream>
#include <fstream>
#include <vector>
#include <utility>

namespace papero
{
	namespace gen
	{
		std::string getPureTitle(std::string title);
		void postGen(std::vector <std::pair <std::string, std::string> > postList,
                     std::string outputPath,
                     std::string templatePath);
		std::string getLangHTML(std::string lang);
		std::string getNameHTML(std::string name);
		std::string getAuthorHTML(std::string author);
		std::string getStyleHTML(std::string style);
		void indexGen(std::vector <std::pair <std::string, std::string> > postList,
                                          std::string outputPath,
                                          std::string lang,
                                          std::string author,
                                          std::string name,
                                          std::string style,
                                          std::string main);
	}
}
