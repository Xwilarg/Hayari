#pragma once

#include <string>

namespace Hayari
{
	class SearchEngine
	{
	public:
		void Search(const std::string& url) noexcept;
	};
}