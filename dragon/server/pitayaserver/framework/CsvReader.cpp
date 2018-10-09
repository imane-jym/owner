/*
 * =====================================================================================
 *
 *       Filename:  CsvReader.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年08月22日 10时23分42秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  imane (), imanecr@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "CsvReader.h"
#include "Util.h"

using namespace std;

bool CCsvReader::Init(std::string content)
{
	m_table.clear();
	m_ErrorStr = "";
	stringstream ss(content);
	string line;
	while(getline(ss, line))
	{
		vector<string> oneline;
		CUtil::StrSplit(line, ",", oneline);
		m_table.push_back(oneline);
	}	
	return true;
}

bool CCsvReader::InitByFile(std::string path)
{
	m_table.clear();
	m_ErrorStr = "";
	fstream fs(path.c_str());
	string line;
	while(getline(fs, line))
	{
		vector<string> oneline;
		CUtil::StrSplit(line, ",", oneline);
		m_table.push_back(oneline);
	}	
	return true;
}

std::string CCsvReader::GetCell(int line, int row)
{
	if ((size_t)line < m_table.size() && (size_t)row < m_table[line].size())
	{
		return m_table[line][row];
	}
	m_ErrorStr = CUtil::FormatError("unvalid line %u row %u", line, row);
	return "";
}

std::string CCsvReader::GetErrorStr()
{
	return m_ErrorStr;
}

int CCsvReader::GetLineCount()
{
	return m_table.size();
}
