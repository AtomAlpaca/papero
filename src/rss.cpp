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

			RSS << std::string("<?xml version=\"1.0\" encoding=\"UTF-8\" ?>\n")
							 + "<rss version=\"2.0\">\n"
							 + "<channel>\n"
							 + getChannelXML(title, link, description);
			
			const int len = postList.size();
			for (int index = 0; index < len; ++index)
			{
				RSS << getItemXML(postList.at(index).first,
								  link + "post/" + papero::gen::getPureTitle(postList.at(index).second));
			}

			RSS << std::string("</channel>\n")
							 + "</rss>";
			
			RSS.close();
			return ;
		}
	}
}
