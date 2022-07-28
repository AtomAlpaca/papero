#include "conf.h"
#include "gen.h"

int main()
{
	libconfig::Config cfg;

		cfg.readFile("blog.conf");


	std::vector <std::pair <std::string, std::string> > postList;
	std::string lang,
				name,
				style,
				templatePath,
				author,
				outputPath,
				mainPageContent;

	try
	{
		postList		= papero::conf::getPosts(cfg.lookup("posts"));
		lang 			= papero::conf::getLang (cfg);
		name			= papero::conf::getName (cfg);
		style 			= papero::conf::getStyle (cfg);
		templatePath	= papero::conf::getTemple (cfg);
		author			= papero::conf::getAuthor (cfg);
		outputPath  	= papero::conf::getOutputPath (cfg);
		mainPageContent = papero::conf::getMainPageContent(cfg);
	}
	catch(...)
	{
		std::cerr << "Error: Error while reading config file" << std::endl;
		return -1;
	}

	system((std::string("rm -rf ")
		  + outputPath).c_str());

	system((std::string("mkdir ")
		  + outputPath
		  + " "
		  + outputPath
		  + "/post").c_str());

	papero::gen::postGen(postList, outputPath, templatePath);
	papero::gen::indexGen(postList, outputPath, lang, author, name, style, mainPageContent);

	system((std::string("cp ")
		  + style
		  + " "
		  + outputPath
		  + "/post"
		  + papero::gen::getPureTitle(style)).c_str());

	system((std::string("cp ./CNAME ")
		  + outputPath).c_str());
	return 0;
}