#ifndef __Stone_Parser_H__
#define __Stone_Parser_H__

#include <vector>
#include <string>
#include <typeinfo>
#include <cstdarg>
#include <unordered_set>
#include <unordered_map>

#include "STObject.h"

NS_LAN_BEGIN
class ASTree;
class Lexer;
class Token;

//----------------------------------Precedence--------------------------
//运算符的优先级和结合性
class Precedence {
public:
	Precedence(int v, bool a) {
		this->value = v;
		this->leftAssoc = a;
	}
public:
	int value;
	//是否是左结合
	bool leftAssoc;
};
//----------------------------------Operators--------------------------
//运算符
class Operators: public Object
{
public:
	static bool LEFT;
	static bool RIGHT;
public:
	Operators();
	~Operators();
	//添加操作符 优先级和结合性
	void add(const std::string& name, int prec, bool leftAssoc);
	//根据名称获取对应的优先级
	Precedence* get(const std::string& name);
private:
	std::unordered_map<std::string, Precedence*> _mapping;
};

class Parser: public Object
{
protected:
	//----------------------------------Element--------------------------
	class Element
	{
	public:
		virtual ~Element() {}
	public:
		virtual void parse(Lexer* lexer, std::vector<ASTree*>& result) = 0;
		virtual bool match(Lexer* lexer) const = 0;
	};
	//----------------------------------Tree--------------------------
	class Tree : public Element
	{
	public:
		Tree(Parser* parser);
		virtual ~Tree();
	public:
		virtual void parse(Lexer* lexer, std::vector<ASTree*>& result);
		virtual bool match(Lexer* lexer) const;
	protected:
		Parser* _parser;
	};
	//----------------------------------OrTree--------------------------
	class OrTree : public Element
	{
	public:
		OrTree(Parser* parsers[], unsigned n);
		OrTree(Parser* p1, Parser* p2);
		virtual ~OrTree();
		//前插入？
		void insert(Parser* parser);
	public:
		virtual void parse(Lexer* lexer, std::vector<ASTree*>& result);
		virtual bool match(Lexer* lexer) const;
	protected:
		Parser* choose(Lexer* lexer) const;
	protected:
		std::vector<Parser*> _parsers;
	};
	//----------------------------------Repeat--------------------------
	class Repeat : public Element
	{
	public:
		Repeat(Parser* parser, bool once);
		virtual ~Repeat();
	public:
		virtual void parse(Lexer* lexer, std::vector<ASTree*>& result);
		virtual bool match(Lexer* lexer) const;
	protected:
		Parser* _parser;
		bool _onlyOnce;
	};
	//----------------------------------AToken--------------------------
	class AToken : public Element
	{
	public:
		AToken(const std::string& factoryName);
		virtual ~AToken();
		virtual void parse(Lexer* lexer, std::vector<ASTree*>& result);
		virtual bool match(Lexer* lexer) const;
	protected:
		virtual bool test(Token* token) const = 0;
	protected:
		std::string _factoryName;
	};
	//----------------------------------IdToken--------------------------
	class IdToken : public AToken
	{
	public:
		IdToken(const std::string& factoryName, const std::unordered_set<std::string>* set);
	protected:
		virtual bool test(Token* token) const;
	private:
		const std::unordered_set<std::string>* _reserved;
	};
	//----------------------------------NumToken--------------------------
	class NumToken : public AToken
	{
	public:
		NumToken(const std::string& factoryName);
	protected:
		virtual bool test(Token* token) const;
	};
	//----------------------------------StrToken--------------------------
	class StrToken : public AToken
	{
	public:
		StrToken(const std::string& factoryName);
	protected:
		virtual bool test(Token* token) const;
	};
	//----------------------------------Leaf--------------------------
	class Leaf : public Element
	{
	public:
		Leaf(char* tokens[], unsigned n);
		virtual void parse(Lexer* lexer, std::vector<ASTree*>& result);
		virtual bool match(Lexer* lexer) const;

		virtual void find(std::vector<ASTree*>& result, Token* token);
	protected:
		std::vector<std::string> _tokens;
	};
	//----------------------------------Skip--------------------------
	class Skip : public Leaf
	{
	public:
		Skip(char* tokens[], unsigned n);
		virtual void find(std::vector<ASTree*>& result, Token* token);
	};
	//----------------------------------Expr--------------------------
	class Expr : public Element
	{
	public:
		Expr(const std::string& factoryName, Parser* exp, Operators* map);
		virtual ~Expr();

		virtual void parse(Lexer* lexer, std::vector<ASTree*>& result);
		virtual bool match(Lexer* lexer) const;
	protected:
		ASTree* doShift(Lexer* lexer, ASTree* left, int prec);
		Precedence* nextOperator(Lexer* lexer);
		//判断右侧是一个表达式
		static bool rightIsExpr(int prec, Precedence* nextPrec);
	private:
		std::string _factoryName;
		Parser* _factor;
		Operators* _operators;
	};
//----------------------------------Parser--------------------------
public:
	Parser();
	Parser(const std::string& factoryName);
	Parser(const Parser* parser);
	virtual ~Parser();

	//执行语法分析
	ASTree* parse(Lexer* lexer);

	//清空语法规则
	void reset();
	void reset(const std::string& factoryName);

	//创建Parser对象
	static Parser* rule();
	static Parser* rule(const std::string& factoryName);

	//添加终结字符 (整型)
	Parser* number();
	Parser* number(const std::string& factoryName);

	//添加终结符 （标识符）
	Parser* identifier(const std::unordered_set<std::string>* reserved);
	Parser* identifier(const std::string& factoryName, const std::unordered_set<std::string>* reserved);

	//添加终结符（字符串）
	Parser* string();
	Parser* string(const std::string& factoryName);

	//添加终结符？？？
	Parser* token(unsigned n, ...);

	//添加未包含于抽象语法树的终结符（与pat匹配的标识符）
	Parser* sep(unsigned n, ...);

	//添加非终结符p
	Parser* ast(Parser* p);

	//添加若干个由or关系链接的非终结符
	Parser* orTree(unsigned n, ...);

	//添加可省略的非终结符（如果省略，则作为一颗仅有根节点的抽象语法树处理）
	Parser* maybe(Parser* p);

	//添加非终结的可省略的非终结符p
	Parser* option(Parser* p);

	//添加至少重复0次的非终结符p
	Parser* repeat(Parser* p);

	//添加双目运算符 subexp时因子，operators时运算符表
	Parser* expression(Parser* subexp, Operators* operators);
	Parser* expression(const std::string& factoryName, Parser* subexp, Operators* operators);

	//位语法规则起始处的or添加新的分支选项
	Parser* insertChoice(Parser* p);
protected:
	bool match(Lexer* lexer) const;
protected:
	std::vector<Element*> _elements;
	std::string _factoryName;
};
NS_LAN_END
#endif