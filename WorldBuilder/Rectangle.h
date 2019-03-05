#pragma once

class Rectangle
{
public:
	Rectangle(int t_x, int t_y, int t_width, int t_height) : m_x(t_x), m_y(t_y), m_width(t_width), m_height(t_height) {};

	int getX() const { return m_x; }
	int getY() const { return m_y; }
	int getWidth() const { return m_width; }
	int getHeight() const { return m_height; }

	bool intersects(Rectangle* t_rectangle) const
	{
		return m_x < t_rectangle->getX() + t_rectangle->getWidth() && m_x + m_width > t_rectangle->getX() && m_y < t_rectangle->getY() + t_rectangle->getHeight() && m_y + m_height > t_rectangle->getY();
	}
private:
	int m_x;
	int m_y;
	int m_width;
	int m_height;
};