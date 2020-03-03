#ifndef _TEXTQUERY_HPP_
#define _TEXTQUERY_HPP_

#include <set>
#include <map>
#include <memory>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>

namespace lb
{
	class QueryResult
	{
		friend std::ostream& print(std::ostream &os, const QueryResult &result);

	private:
		using LineNo = std::vector<std::string>::size_type;

		std::string m_word; // 查询的单词
		std::shared_ptr<std::set<LineNo>> m_lines; // 出现的行号
		std::shared_ptr<std::vector<std::string>> m_file; // 要查询的文件

	public:
		QueryResult(std::string word, std::shared_ptr<std::set<LineNo>> lines
			, std::shared_ptr<std::vector<std::string>> file)
			: m_word(word)
			, m_file(file)
			, m_lines(lines)
		{ }
	};

	class TextQuery
	{
	private:
		using LineNo = std::vector<std::string>::size_type;

		std::shared_ptr<std::vector<std::string>> m_file; // 保存的文件
		std::map<std::string, std::shared_ptr<std::set<LineNo>>> m_wordMap; // 每个单词到所存在行号的映射

	public:
		TextQuery(std::ifstream &fin) : m_file(new std::vector<std::string>)
		{
			LineNo lineNo;
			std::string line, word;

			while (getline(fin, line)) // 读取每行的文本
			{
				m_file->push_back(line); // 将读取的文本保存
				lineNo = m_file->size() - 1; // 获取当前行的编号
				std::istringstream text(line);

				while (text >> word) // 读取每行中的单词
				{
					if (!m_wordMap[word]) // 当shared_ptr<set<LineNo>>是空指针
						m_wordMap[word].reset(new std::set<LineNo>); // 分配一个set<LineNo>
					m_wordMap[word]->insert(lineNo); // 将行编号插入set
				}
			}
		}

		QueryResult query(const std::string &word) const
		{
			static std::shared_ptr<std::set<LineNo>> nodata(new std::set<LineNo>); // 找不到时的返回
			auto loc = m_wordMap.find(word); // 使用find查找是否有word出现

			if (loc == m_wordMap.end()) // 如果找不到，返回nodata
				return QueryResult(word, nodata, m_file);
			else// 找到了返回loc->second
				return QueryResult(word, loc->second, m_file);
		}
	};

	std::ostream& print(std::ostream &os, const QueryResult &result)
	{
		os << result.m_word << " 出现了 " << result.m_lines->size() << " 次: " << std::endl;
		for (auto num : *result.m_lines)
			os << "(line " << num + 1 << ") " << *(result.m_file->begin() + num) << std::endl;
		return os;
	}
}
#endif /* _TEXTQUERY_HPP_ */