#include "ASTLeaf.h"
#include "Token.h"
#include "Visitor.h"

NS_LAN_BEGIN

const std::string ASTLeaf::TREE_ID = "ASTLeaf";
std::vector<ASTree*> ASTLeaf::empty = std::vector<ASTree*>();

ASTLeaf::ASTLeaf(Token* token) 
	:_token(token)
{
	ASTree::init(TREE_ID);
}

ASTLeaf::~ASTLeaf()
{
	delete _token;
}

Token* ASTLeaf::getToken() const
{
	return _token;
}

void ASTLeaf::accept(Visitor* v, Environment* env)
{
	v->visit(this, env);
}

ASTree* ASTLeaf::getChild(unsigned int i) const
{
	return nullptr;
}

int ASTLeaf::getNumChildren() const
{
	return 0;
}

std::string ASTLeaf::getLocation() const
{
	return "at line " + std::to_string(_token->getLineNumber());
}

std::vector<ASTree*>::iterator ASTLeaf::begin()
{
	return ASTLeaf::empty.begin();
}

std::vector<ASTree*>::iterator ASTLeaf::end()
{
	return ASTLeaf::empty.end();
}

std::string ASTLeaf::toString() const
{
	return _token->asString();
}
NS_LAN_END