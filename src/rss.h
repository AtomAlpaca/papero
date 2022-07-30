#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <utility>

namespace papero
{
	namespace rss
	{
		std::string getItemXML(std::string title,
							   std::string link);
		std::string getChannelXML(std::string title,
								  std::string link,
								  std::string description);
		void RSSGen(std::string outputPath,
					std::string title,
					std::string link,
					std::string description,
					std::vector <std::pair <std::string, std::string> > postList);
	}
}
