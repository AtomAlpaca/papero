#pragma once

#include <iostream>
#include <vector>
#include <utility>

#include <libconfig.h++>

namespace papero
{
	namespace conf
	{           
		struct singleConfig
        {
			bool able;
			std::string content;
		};
		struct siteConfig
		{
			singleConfig lang, name, style, temple, author, outputPath, startContent, 
									 endContent, description, domain;
			std::vector <std::pair <std::string, std::string> > posts;
		};
		auto getPosts(const libconfig::Setting & postList) 
		-> std::vector <std::pair <std::string, std::string> >;
		singleConfig getLang(const libconfig::Config & config);
		singleConfig getName(const libconfig::Config & config);
		singleConfig getStyle(const libconfig::Config & config);
		singleConfig getTemple(const libconfig::Config & config);
		singleConfig getAuthor(const libconfig::Config & config);
		singleConfig getOutputPath(const libconfig::Config & config);
		singleConfig getMainPageContent(const libconfig::Config & config);
		singleConfig getSiteDescription(const libconfig::Config & config);
		singleConfig getSiteDomain(const libconfig::Config & config);
		singleConfig getMainPageEndContent(const libconfig::Config & config);
		siteConfig getSiteConfig(const libconfig::Config & config);
	}
}
