#include <fstream>
#include <iostream>
#include <string>
#include <Windows.h>

#include "Token.h"
#include "Environment.h"
#include "STAutoreleasePool.h"
#include "StoneState.h"

using namespace std;
USING_NS_LAN;

void ADD(string& need);
std::unique_ptr<char> getUniqueDataFromFile(const std::string& filename);
Value print(Environment* env);

int main() 
{
	string path;
	printf("������·��[.txt]��");
	cin >> path;
	//ADD(path);
	auto uniquePtr = std::move(getUniqueDataFromFile(path));
	system("cls");
	//��ʧ��
	if (uniquePtr == nullptr)
	{
		printf("�ļ���ʧ��");
		return 1;
	}
	StoneState* stone = new StoneState();
	stone->init(uniquePtr.get());
	uniquePtr.reset();
	//���뷽��
	const char* params[] = { "value" };
	stone->putNative("print", print, params, 1);

	while (stone->hasNext())
	{
		stone->execute();
	}

	delete stone;
	AutoreleasePool::purge();
	delete Token::TOKEN_EOF;
	printf("\n");
	system("pause");

	return 0;
}
void ADD(string& need)
{
	char temp[5];
	for (int i = size(need) - 4,n=0; n <= 4; ++n)
	{
		temp[n] = need[i];
	}
	if (temp == ".txt")
	{

	}
	else
		need += ".txt";
}

std::unique_ptr<char> getUniqueDataFromFile(const std::string& filename) 
{
	std::unique_ptr<char> points;
	std::ifstream in;
	in.open(filename);

	//���ļ�ʧ��
	if (!in.is_open())
	{
		return points;
	}
	//��λ���ļ���ĩβ
	in.seekg(0, std::ios::end);
	//��ȡ�ܳ���
	int size = (int)in.tellg();

	char* buffer = new char[size + 1];
	memset(buffer, '\0', size + 1);
	
	//��ȡ
	in.seekg(0, std::ios::beg);
	in.read(buffer, size);
	//�ر��ļ�
	in.close();

	points = std::unique_ptr<char>(buffer);
	return points;
}

Value print(Environment* env)
{
	//��ȡ����
	const Value* value = env->get("value");
	std::cout << value->asString() << std::endl;

	return *value;
}
