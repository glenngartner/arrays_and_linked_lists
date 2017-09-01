#include <string>

class Actor
{
public:
	std::string name;
	Actor(std::string);
	~Actor();

private:

};

Actor::Actor(std::string name)
{
	name = name;
}

Actor::~Actor()
{
}