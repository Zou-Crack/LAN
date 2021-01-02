#include "NullStmnt.h"

NS_LAN_BEGIN
const std::string NullStmnt::TREE_ID = "NullStmnt";
NullStmnt::NullStmnt()
{
	ASTree::init(TREE_ID);
}
NS_LAN_END