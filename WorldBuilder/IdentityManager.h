#pragma once
class IdentityManager
{
public:
	static IdentityManager& getInstance()
	{
		static IdentityManager instance;
		return instance;
	}

	int getEntityId()
	{
		m_idcounter += 1;
		return m_idcounter;
	}

	int getFaceId()
	{
		m_idcounter += 1;
		return m_idcounter;
	}

	int getSolidId()
	{
		m_idcounter += 1;
		return m_idcounter;
	}

private:
	int m_idcounter = 0;
};

