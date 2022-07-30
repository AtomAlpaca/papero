#pragma once

#include <iostream>
#include <vector>
#include <utility>

#include <libconfig.h++>

namespace papero
{
	namespace conf
	{
		auto getPosts(const libconfig::Setting & postList) 
		-> std::vector <std::pair <std::string, std::string> >;
		std::string getLang(const libconfig::Config & config);
		std::string getName(const libconfig::Config & config);
		std::string getStyle(const libconfig::Config & config);
		std::string getTemple(const libconfig::Config & config);
		std::string getAuthor(const libconfig::Config & config);
		std::string getOutputPath(const libconfig::Config & config);
		std::string getMainPageContent(const libconfig::Config & config);
		std::string getSiteDescription(const libconfig::Config & config);
		std::string getSiteDomain(const libconfig::Config & config);
		std::string getMainPageEndContent(const libconfig::Config & config);
	}
}
