#include "gen.h"

namespace papero
{
	namespace gen
	{
		std::string getPureTitle(std::string title)
		{
			
			int start, end = title.size();

			if (title[title.size()] == '/')
			{
				--end;
			}

			start = title.rfind('/');

			if (start == std::string::npos)
			{
				start = 0;
			}
			else
			{
				++start;
			}
			return title.substr(start, end);
		}

		void postGen(std::vector <std::pair <std::string, std::string> > postList, 
					 std::string outputPath,
					 std::string templatePath)
		{
			for (std::pair<std::string, std::string> index : postList)
			{
				const std::string title = index.second;
				const std::string pureTitle = getPureTitle(title);

				system
				(
					(std::string("pandoc ")
							  + title + ".tex "
							  + "-f latex -t html5 --mathml --template=" + templatePath 
							  + " --table-of-content -o "
							  + outputPath + "/post/" + pureTitle + ".html").c_str()
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
			return std::string("<link rel = \"stylesheet\" href = \"./post/"
							 + getPureTitle(style)
							 + "\" type = \"text/css\" />");
		}

		void langGen(std::string content, std::ofstream & file)
		{
			file << getLangHTML(content) << std::endl;
			return ;
		}

		void nameGen(std::string content, std::ofstream & file)
		{
			file << getNameHTML(content) << std::endl;
		}
		
		void styleGen(std::string content, std::ofstream & file)
		{
			file << getStyleHTML(content) << std::endl;
		}

		void authorGen(std::string content, std::ofstream & file)
		{
			file << getAuthorHTML(content) << std::endl;
		}

		void startGen(std::string path, std::ofstream & file)
		{
			std::ifstream input(path);
			std::string content((std::istreambuf_iterator<char>(input)),
								(std::istreambuf_iterator<char>()));
			input.close();
			file << content << std::endl;
			return ;
		}

		void endGen(std::string path, std::ofstream & file)
		{
			std::ifstream input(path);
			std::string content((std::istreambuf_iterator<char>(input)),
								(std::istreambuf_iterator<char>()));
			input.close();
			file << content << std::endl;
			return ;
		}

		void postListGen(std::vector <std::pair <std::string, std::string> > postList,
						 std::ofstream & file)
		{
			file << std::endl << "\t<ol>" << std::endl;

			for (std::pair <std::string, std::string> index : postList)
			{
				std::string pureTitle = getPureTitle(index.second);
				file << "\t\t<li>" << std::endl
						  << "\t\t\t<a href=\"./post/" << pureTitle << ".html\">" << std::endl
						  << index.first << std::endl
						  << "</a>"      << std::endl
						  << "\t\t</li>" << std::endl;
			}

			file << "\t</ol>" << std::endl;

		}

		void indexGen(papero::conf::siteConfig config)
		{
			std::ofstream indexFile;
			indexFile.open(config.outputPath.content + "/index.html");

			indexFile << "<!DOCTYPE html>" << std::endl;
			if (config.lang.able)
			{
				langGen(config.lang.content, indexFile);
			}
			indexFile << "<head>" << std::endl
					  << "\t<meta charset = \"utf-8\"/>" << std::endl;
			if (config.author.able)
			{
				authorGen(config.author.content, indexFile);
			}

			if (config.name.able)
			{
				nameGen(config.name.content, indexFile);
			}

			if (config.style.able)
			{
				styleGen(config.style.content, indexFile);
			}

			indexFile << "</head>" << std::endl
					  << "<body>"  << std::endl;
			
			if (config.startContent.able)
			{
				startGen(config.startContent.content, indexFile);
			}

			postListGen(config.posts, indexFile);

			if (config.endContent.able)
			{
				endGen(config.endContent.content, indexFile);
			}
			
			indexFile << "</body>";
			
			indexFile.close();
			return ;
		}
	}
}
