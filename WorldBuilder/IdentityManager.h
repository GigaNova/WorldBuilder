#pragma once
class IdentityManager
{
public:
	static IdentityManager& getInstance()
	{
		static IdentityManager instance;
		return instance;
	}

	int getFaceId()
	{
		m_facecounter += 1;
		return m_facecounter;
	}

	int getSolidId()
	{
		m_solidcounter += 1;
		return m_solidcounter;
	}

private:
	int m_facecounter = 0;
	int m_solidcounter = 0;
};

