#include "rss.h"
#include "gen.h"

namespace papero
{
	namespace rss
	{
		std::string getItemXML(std::string title,
							   std::string link)
		{
			return (std::string("\t<item>\n") + 
					    		"\t\t<title>" + title + "</title>\n"
							    "\t\t<link>" + link + "</link>\n"
							    "\t</item>\n");
		}

		std::string getChannelXML(std::string title,
								  std::string link,
								  std::string description)
		{
			return (std::string("\t<title>") 	  + title 		+ "</title>\n"
							  + "\t<link>"   	  + link  		+ "</link>\n"
							  + "\t<description>" + description + "</description>\n");
		}

		void RSSGen(std::string outputPath,
					std::string title,
					std::string link,
					std::string description,
					std::vector <std::pair <std::string, std::string> > postList)
		{
			if (link[link.size()] != '/')
			{
				link += '/';
			}

			std::ofstream RSS;
			RSS.open(outputPath + "/rss.xml");

			RSS << "<?xml version=\"1.0\" encoding=\"UTF-8\" ?>" << std::endl
				<< "<rss version=\"2.0\">" << std::endl
				<< "<channel>" << std::endl
				<< getChannelXML(title, link, description);
			
			const int len = postList.size();
			for (std::pair <std::string, std::string> index : postList)
			{
				RSS << getItemXML(index.first,
								  link + "post/" + papero::gen::getPureTitle(index.second));
			}

			RSS << "</channel>" << std::endl
				<< "</rss>";
			
			RSS.close();
			return ;
		}
	}
}
