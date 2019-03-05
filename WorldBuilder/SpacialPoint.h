#pragma once
class SpacialPoint
{
public:
	SpacialPoint(int t_x, int t_y, int t_z) : m_x(t_x), m_y(t_y), m_z(t_z) {};

	int getX() const { return m_x; }
	int getY() const { return m_y; }
	int getZ() const { return m_z; }

	std::string toString()
	{
		return "(" +
			std::to_string(m_x) + ' ' +
			std::to_string(m_y) + ' ' +
			std::to_string(m_z) +
		")";
	}
private:
	int m_x;
	int m_y;
	int m_z;
};
