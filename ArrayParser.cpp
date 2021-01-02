#include "ArrayParser.h"
#include "Parser.h"
#include "ArrayLiteral.h"
#include "ArrayRef.h"

NS_LAN_BEGIN

ArrayParser::ArrayParser()
	:_elements(nullptr)
{
	//elements: expr {"," expr}
	_elements = Parser::rule(ArrayLiteral::TREE_ID);
	_elements->retain();
	_elements->setLock(true);
	_elements->ast(_expr)->repeat(Parser::rule()->sep(1, ",")->ast(_expr));

	this->init();
}

ArrayParser::~ArrayParser()
{
	_elements->release(true);
}

bool ArrayParser::init()
{
	//Ìí¼Ó±£Áô×Ö
	_reserved->insert("]");

	//primary: ("[" [elements] "]" | "(" expr ")" | NUMBER | IDENTIFIER | STRING) {postfix}
	_primary->insertChoice(Parser::rule()->sep(1, "[")->maybe(_elements)->sep(1, "]"));

	//"(" [args] ")" | "[" expr "]"
	_postfix->insertChoice(Parser::rule(ArrayRef::TREE_ID)->sep(1, "[")->ast(_expr)->sep(1, "]"));
	return true;
}
NS_LAN_END