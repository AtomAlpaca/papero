#include "gen.h"

namespace papero
{
	namespace gen
	{
		std::string getPureTitle(std::string title)
		{
				std::string pureTitle;
				if (title[title.size()] == '/')
				{
					title[title.size()] = ' ';
				}

				const int find = title.rfind('/');

				if (find == std::string::npos)
				{
					pureTitle = title;
				}
				else
				{
					pureTitle = title.substr(find);
				}
				return pureTitle;
		}

		void postGen(std::vector <std::pair <std::string, std::string> > postList, 
					 std::string outputPath,
					 std::string templatePath)
		{
			const int len = postList.size();


			for (int index = 0; index < len; ++index)
			{
				std::string title = postList.at(index).second;
				std::string pureTitle = getPureTitle(title);

				system
				(
					(std::string("pandoc ")
							  + title
							  + ".tex -f latex -t html5 --mathml --template="
							  + templatePath
							  + " --table-of-content -o "
							  + outputPath
							  + "/post"
							  + pureTitle
							  + ".html").c_str()
				);
			}
		}

		std::string getLangHTML(std::string lang)
		{
			return std::string("<html lang = \""
							 + lang
							 + "\">");
		}

		std::string getNameHTML(std::string name)
		{
			return std::string("<title>"
							 + name
							 + "</title>");
		}

		std::string getAuthorHTML(std::string author)
		{
			return std::string("<meta name = \"author\" content = \""
							 + author
							 + "\"/>");
		}

		std::string getStyleHTML(std::string style)
		{
			return std::string("<link rel = \"stylesheet\" href = \"./post"
							 + getPureTitle(style)
							 + "\" type = \"text/css\" />");
		}

		void indexGen(std::vector <std::pair <std::string, std::string> > postList,
					  std::string outputPath,
					  std::string lang,
					  std::string author,
					  std::string name,
					  std::string style,
					  std::string main)
		{
			std::ofstream indexFile;
			indexFile.open(outputPath + "/index.html");

			indexFile << std::string("<!DOCTYPE html>\n")
						   		   + getLangHTML(lang) + "\n\n"
						 		   + "<head>\n"
					 			   + "\t<meta charset = \"utf-8\"/>\n"
								   + '\t' + getAuthorHTML(author) + '\n'
								   + '\t' + getNameHTML(name) + '\n'
								   + '\t' + getStyleHTML(style) + '\n'
								   + "</head>\n";

			indexFile << std::string("<body>\n")
								   + main;

			const int len = postList.size();
			
			indexFile << "\n\t<ol>\n";

			for (int index = 0; index < len; ++index)
			{
				std::string pureTitle = getPureTitle(postList.at(index).second);
				indexFile << std::string("\t\t<li>\n")
									   + "\t\t\t<a href=\""
									   + "./post"
									   + pureTitle
									   + ".html\">"
									   + postList.at(index).first
									   + "</a>\n"
									   + "\t\t</li>\n";
			}

			indexFile << std::string("\t</ol>\n")
					   			   + "</body>";
			
			return ;
		}
	}
}
