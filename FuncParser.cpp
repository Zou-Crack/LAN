#include "FuncParser.h"
#include "Parser.h"
#include "ParameterList.h"
#include "DefStmnt.h"
#include "Arguments.h"

NS_LAN_BEGIN

FuncParser::FuncParser()
	:BasicParser()
	,_param(nullptr)
	,_params(nullptr)
	,_paramList(nullptr)
	,_def(nullptr)
	,_args(nullptr)
	,_postfix(nullptr)
{
	//param: IDENTIFIER
	_param = Parser::rule();
	_param->retain();
	_param->setLock(true);
	_param->identifier(_reserved);

	//params: param {"," param}
	_params = Parser::rule(ParameterList::TREE_ID);
	_params->retain();
	_params->setLock(true);
	_params->ast(_param)->repeat(Parser::rule()->sep(1, ",")->ast(_param));

	//param_list: "(" [params ] ")"
	_paramList = Parser::rule();
	_paramList->retain();
	_paramList->setLock(true);
	_paramList->sep(1, "(")->maybe(_params)->sep(1, ")");

	//def: "def" IDENTIFIER param_list block
	_def = Parser::rule(DefStmnt::TREE_ID);
	_def->retain();
	_def->setLock(true);
	_def->sep(1, "def")->identifier(_reserved)->ast(_paramList)->ast(_block);

	//----------------------函数调用----------------
	//args: expr {"," expr}
	_args = Parser::rule(Arguments::TREE_ID);
	_args->retain();
	_args->setLock(true);
	_args->ast(_expr)->repeat(Parser::rule()->sep(1, ",")->ast(_expr));

	//postfix: "(" [args] ")"
	_postfix = Parser::rule();
	_postfix->retain();
	_postfix->setLock(true);
	_postfix->sep(1, "(")->maybe(_args)->sep(1, ")");

	this->init();
}

FuncParser::~FuncParser()
{
	_param->release(true);
	_params->release(true);
	_paramList->release(true);
	_def->release(true);
	_args->release(true);
	_postfix->release(true);
}

bool FuncParser::init()
{
	//添加保留字符
	_reserved->insert(")");

	_primary->repeat(_postfix);
	_simple->option(_args);

	//program: [ def | statement] (";" | EOL)
	_program->insertChoice(_def);

	return true;
}

NS_LAN_END