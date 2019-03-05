#pragma once
#include <map>

typedef std::pair<std::string, std::string> Attribute;

class Entity
{
public:
	Entity(std::string t_classname, int t_x, int t_y, int t_z);
	~Entity();

	int getId() const { return m_id; }
	std::string getClassName() const { return m_classname; }

	double getX() const { return m_x; }
	double getY() const { return m_y; }
	double getZ() const { return m_z; }
	
	std::map<std::string, std::string> getAttributes() const { return m_attributes; };
protected:
	int m_id;
	std::string m_classname;

	double m_x;
	double m_y;
	double m_z;

	std::map<std::string, std::string> m_attributes;
};

