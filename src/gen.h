#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <utility>

#include "conf.h"

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
		void langGen(std::string content, std::ofstream & file);
		void nameGen(std::string content, std::ofstream & file);
		void styleGen(std::string content, std::ofstream & file);
		void authorGen(std::string content, std::ofstream & file);
		void startGen(std::string content, std::ofstream & file);
		void endGen(std::string content, std::ofstream & file);
		void postListGen(std::vector <std::pair <std::string, std::string> > postList,
						 std::ofstream & file);
		void indexGen(papero::conf::siteConfig config);
	}
}
