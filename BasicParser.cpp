#include "BasicParser.h"
#include "Parser.h"
#include "PrimaryExpr.h"
#include "NumberLiteral.h"
#include "Name.h"
#include "StringLiteral.h"
#include "NegativeExpr.h"
#include "BinaryExpr.h"
#include "Token.h"
#include "BlockStmnt.h"
#include "IfStmnt.h"
#include "WhileStmnt.h"
#include "NullStmnt.h"

NS_LAN_BEGIN
BasicParser::BasicParser()
	:_operators(nullptr)
	,_reserved(nullptr)
	,_primary(nullptr)
	,_factor(nullptr)
	,_expr(nullptr)
	,_statement(nullptr)
	,_block(nullptr)
	,_simple(nullptr)
	,_program(nullptr)
{
	_operators = new Operators();
	_reserved = new std::unordered_set<std::string>();

	Parser* expr0 = Parser::rule();
	expr0->retain();
	expr0->setLock(true);

	//primary: "(" expr ")" | NUMBER | IDENTIFIER | STRING
	_primary = Parser::rule(PrimaryExpr::TREE_ID);
	_primary->retain();
	_primary->setLock(true);

	_primary->orTree(4, 
		Parser::rule()->sep(1, "(")->ast(expr0)->sep(1, ")"),
		Parser::rule()->number(NumberLiteral::TREE_ID),
		Parser::rule()->identifier(Name::TREE_ID, _reserved),
		Parser::rule()->string(StringLiteral::TREE_ID));

	//factor: "-" primary | primary
	_factor = Parser::rule();
	_factor->retain();
	_factor->setLock(true);

	_factor->orTree(2,
		Parser::rule(NegativeExpr::TREE_ID)->sep(1, "-")->ast(_primary),
		_primary);

	//expr: factor {OP factor}
	_expr = expr0->expression(BinaryExpr::TREE_ID, _factor, _operators);

	Parser* statement0 = Parser::rule();
	statement0->retain();
	statement0->setLock(true);

	//block: "{" [statement] { (";" | EOL) [statement] } "}"
	_block = Parser::rule(BlockStmnt::TREE_ID);
	_block->retain();
	_block->setLock(true);

	_block->sep(1, "{")->option(statement0)
		->repeat(Parser::rule()->sep(2, ";", Token::TOKEN_EOL)->option(statement0))
		->sep(1, "}");

	//simple: expr
	_simple = Parser::rule(PrimaryExpr::TREE_ID)->ast(_expr);
	_simple->retain();
	_simple->setLock(true);

	/* statement: "if" expr block {"elif" expr block} ["else" block]
				  | "while" expr block
				  | simple
	*/
	//条件判断语句elif 在创建IfStmnt会对elif的数据项进行解包
	_statement = statement0->orTree(3,
		Parser::rule(IfStmnt::TREE_ID)
			->sep(1, "if")->ast(_expr)->ast(_block)
			->repeat(Parser::rule()->sep(1, "elif")->ast(_expr)->ast(_block))
			->option(Parser::rule()->sep(1, "else")->ast(_block)),
		//while
		Parser::rule(WhileStmnt::TREE_ID)->sep(1, "while")->ast(_expr)->ast(_block),
		_simple
	);

	//program: [statement] (";" | EOL)
	_program = Parser::rule();
	_program->retain();
	_program->setLock(true);

	_program->orTree(2, _statement, Parser::rule(NullStmnt::TREE_ID))->sep(2, ";", Token::TOKEN_EOL);

	this->init();
}

BasicParser::~BasicParser()
{
	_program->release(true);
	_statement->release(true);
	_simple->release(true);
	_block->release(true);
	_expr->release(true);
	_factor->release(true);
	_primary->release(true);

	_operators->release();
	delete _reserved;
}

ASTree* BasicParser::parse(Lexer* lexer)
{
	return _program->parse(lexer);
}

bool BasicParser::init()
{
	//添加保留字符
	_reserved->insert(";");
	_reserved->insert("}");
	_reserved->insert(Token::TOKEN_EOL);

	_operators->add("=", 1, Operators::RIGHT);

	_operators->add("==", 2, Operators::LEFT);
	_operators->add(">", 2, Operators::LEFT);
	_operators->add("<", 2, Operators::LEFT);
	
	_operators->add("+", 3, Operators::LEFT);
	_operators->add("-", 3, Operators::LEFT);
	_operators->add("*", 4, Operators::LEFT);
	_operators->add("/", 4, Operators::LEFT);
	_operators->add("%", 4, Operators::LEFT);

	return true;
}

NS_LAN_END