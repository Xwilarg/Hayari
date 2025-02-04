#include "SearchEngine.hpp"

#include <curlpp/cURLpp.hpp>
#include <curlpp/Options.hpp>
#include <iostream>

namespace Hayari
{
	void SearchEngine::Search(const std::string& url) noexcept
	{
		std::cout << curlpp::options::Url(url);
	}
}