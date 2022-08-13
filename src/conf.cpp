#include "conf.h"

namespace papero
{
	namespace conf
	{
		siteConfig getSiteConfig(const libconfig::Config & config)
		{
			return
			{
				getLang(config),
				getName(config),
				getStyle(config),
				getTemple(config),
				getAuthor(config),
				getOutputPath(config),
				getMainPageContent(config),
				getMainPageEndContent(config),
				getSiteDescription(config),
				getSiteDomain(config),
				getPosts(config.lookup("posts"))
			};
		}

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

		singleConfig getLang(const libconfig::Config & config)
		{
			if (config.exists("lang"))
			{
				return singleConfig{true, config.lookup("lang")};
			}
			return singleConfig{false, ""};
		}

		singleConfig getName(const libconfig::Config & config)
		{
			if (config.exists("name"))
			{
				return singleConfig{true, config.lookup("name")};
			}
			return singleConfig{false, ""};
		}

		singleConfig getStyle(const libconfig::Config & config)
		{
			if (config.exists("style"))
			{
				return singleConfig{true, config.lookup("style")};
			}
			return singleConfig{false, ""};
		}

		singleConfig getAuthor(const libconfig::Config & config)
		{
			if (config.exists("author"))
			{
				return singleConfig{true, config.lookup("author")};
			}
			return singleConfig{false, ""};
		}

		singleConfig getTemple(const libconfig::Config & config)
		{
			if (config.exists("temple"))
			{
				return singleConfig{true, config.lookup("temple")};
			}
			return singleConfig{false, ""};
		}

		singleConfig getOutputPath(const libconfig::Config & config)
		{
			if (config.exists("output"))
			{
				return singleConfig{true, config.lookup("output")};
			}
			return singleConfig{false, ""};
		}

		singleConfig getMainPageContent(const libconfig::Config & config)
		{
			if (config.exists("main"))
			{
				return singleConfig{true, config.lookup("main")};
			}
			return singleConfig{false, ""};
		}

		singleConfig getSiteDescription(const libconfig::Config & config)
		{
			if (config.exists("description"))
			{
				return singleConfig{true, config.lookup("description")};
			}
			return singleConfig{false, ""};
		}

		singleConfig getSiteDomain(const libconfig::Config & config)
		{
			if (config.exists("domain"))
			{
				return singleConfig{true, config.lookup("domain")};
			}
			return singleConfig{false, ""};
		}
		
		singleConfig getMainPageEndContent(const libconfig::Config & config)
		{
			if (config.exists("end"))
			{
				return singleConfig{true, config.lookup("end")};
			}
			return singleConfig{false, ""};
		}
	}
}
