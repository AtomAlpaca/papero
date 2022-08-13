#include "conf.h"
#include "gen.h"
#include "rss.h"

int main()
{
	libconfig::Config cfg;

	cfg.readFile("blog.conf");

	papero::conf::siteConfig config = papero::conf::getSiteConfig(cfg);	

	const std::string & path = config.outputPath.content;

	system((std::string("rm -rf ") + path).c_str());
	system((std::string("mkdir ") + path + " " + path + "/post").c_str());

	papero::gen::postGen(config.posts, path, config.temple.content);
	papero::gen::indexGen(config);

	if (bool(cfg.lookup("rss")))
	{
		papero::rss::RSSGen(path,
							config.name.content,
							config.domain.content,
							config.description.content,
							config.posts);
	}

	if (config.style.able)
	{
		system((std::string("cp ")
			  + config.style.content
			  + " "
  		 	  + path
		  	  + "/post/"
		  	  + papero::gen::getPureTitle(config.style.content)).c_str());
	}
	
	if (bool(cfg.lookup("cname")))
	{
		system((std::string("cp ./CNAME ")
			  + path).c_str());
	}
	return 0;
}
