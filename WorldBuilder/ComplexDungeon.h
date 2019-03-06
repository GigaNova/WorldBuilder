#pragma once
#include "Dungeon.h"
#include "Component.h"

class ComplexDungeon : public Dungeon
{
public:
	static const int MAX_COMPONENTS = 10;
	static const int MAX_DISTANCE = 64;

	ComplexDungeon();
	~ComplexDungeon();

	std::vector<Solid*> getSolids() override;

private:
	void addComponent(Component* t_component);

	std::vector<Component*> m_components;
};

