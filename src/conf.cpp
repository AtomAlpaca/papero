#include "conf.h"

namespace papero
{
	namespace conf
	{
			auto getPosts(const libconfig::Setting & postList) 
		->  std::vector <std::pair <std::string, std::string> > 
		{
			const int count = postList.getLength();
			std::vector <std::pair <std::string, std::string> > posts;
			for (int index = 0; index < count; ++index)
			{
				std::string postTitle, postLink;
				if (   !postList[index].lookupValue("title", postTitle)
					or !postList[index].lookupValue("link",  postLink ))
				{
					std::cerr << "Error: conf error in post list. Skipping..." << std::endl;
				}
				else
				{
					posts.push_back(std::make_pair(postTitle, postLink));
				}
			}

			return posts;
		}

		std::string getLang(const libconfig::Config & config)
		{
			return config.lookup("lang");
		}

		std::string getName(const libconfig::Config & config)
		{
			return config.lookup("name");
		}

		std::string getStyle(const libconfig::Config & config)
		{
			return config.lookup("style");
		}

		std::string getAuthor(const libconfig::Config & config)
		{
			return config.lookup("author");
		}

		std::string getTemple(const libconfig::Config & config)
		{
			return config.lookup("temple");
		}

		std::string getOutputPath(const libconfig::Config & config)
		{
			return config.lookup("output");
		}

		std::string getMainPageContent(const libconfig::Config & config)
		{
			return config.lookup("main");
		}
			
	}
}
