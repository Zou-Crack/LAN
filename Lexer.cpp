#include "Lexer.h"
#include "Token.h"
#include "ParseException.h"
#pragma warning(disable : 4996)
NS_LAN_BEGIN

std::string Lexer::REGEX_POT = "\\s*((//.*)|([0-9]+)|(\"(\\\\\"|\\\\\\\\|\\\\n|[^\"])*\")|[A-Z_a-z][A-Z_a-z0-9]*|==|!=|<=|>=|[\\{\\}<>=;+\\-\\*/%()\\,\\[\\]])?";


Lexer::Lexer(const char* buffer)
	:_reader(buffer)
	,_lineNo(1)
	,_hasMore(true)
{
	_pattern = std::regex(REGEX_POT);
}

Lexer::~Lexer()
{
}

Token* Lexer::read() {
	//获取单词
	if (fillQueue(0)) {
		auto token = _queue.front();
		_queue.erase(_queue.begin());
		return token;
	}
	else {
		return Token::TOKEN_EOF;
	}
}

Token* Lexer::peek(int i) {
	if (fillQueue(i))
		return _queue.at(i);
	else
		return Token::TOKEN_EOF;
}

void Lexer::readLine() {
	char line[MAX_LENGTH];
	//读取一行成功
	if (_reader.getline(line, MAX_LENGTH)) {
		std::cmatch match;

		while (strlen(line) > 0) {
			std::regex_search(line, match, _pattern);
			//匹配失败,抛出异常
			if (match[0] == "") {
				std::string msg = "bad token at line " + std::to_string(_lineNo);
				throw ParseException(msg);
				return;
			}
			else {
				//添加单词
				this->addToken(_lineNo, match);
				//继续向下解析
				strcpy(line, match.suffix().str().c_str());
			}
		}
		//添加换行符
		_queue.push_back(new IdToken(_lineNo++, Token::TOKEN_EOL));
	}
	else
		_hasMore = false;
}

void Lexer::addToken(int lineNo, std::cmatch& matcher) {
	std::string m = matcher[1];

	if (!m.empty()) {
		//匹配的不是注释
		if (matcher[2] != m) {
			Token* token = nullptr;
			//数字
			if (matcher[3] == m)
				token = new NumToken(lineNo, std::stoi(m));
			//字符串
			else if (matcher[4] == m)
				token = new StrToken(lineNo, this->toStringLiteral(m));
			//标识符
			else
				token = new IdToken(lineNo, m);

			//add
			_queue.push_back(token);
		}//end if
	}//end if
}

std::string Lexer::toStringLiteral(const std::string& s) {
	int len = s.length();
	std::stringstream buffer;
	int index = 1;

	//去掉两边的双引号
	while (index < len - 1) {
		char c = s.at(index);

		if (c == '\\' && index + 1 < len) {
			int c2 = s.at(index + 1);

			if (c2 == '"' || c2 == '\\')
				c = s.at(++index);
			else if (c2 == 'n') {
				++index;
				c = '\n';
			}
		}
		buffer << c;
		index++;
	}

	return buffer.str();
}

bool Lexer::fillQueue(unsigned int i) {
	//读取
	while (i >= _queue.size()) {
		if (_hasMore)
			this->readLine();
		else
			return false;
	}
	return true;
}
NS_LAN_END
