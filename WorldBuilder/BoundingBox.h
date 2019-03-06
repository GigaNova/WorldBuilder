#pragma once
class BoundingBox
{
public:
	BoundingBox(int t_x, int t_y, int t_z, int t_width, int t_length, int t_height);
	~BoundingBox();

	int getX() const { return m_x; }
	int getY() const { return m_y; }
	int getZ() const { return m_z; }

	int getWidth() const { return m_width; }
	int getHeight() const { return m_height; }
	int getLength() const { return m_length; }

	bool intersect(BoundingBox b2);
private:
	int m_x;
	int m_y;
	int m_z;

	int m_width;
	int m_height;
	int m_length;
};

