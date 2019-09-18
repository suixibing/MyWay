#include "Tv.h"

bool Tv::VolumeUp()
{
	if (m_volume < MaxVolume)
	{
		m_volume++;
		return true;
	}
	return false;
}

bool Tv::VolumeDown()
{
	if (m_volume > MinVolume)
	{
		m_volume--;
		return true;
	}
	return false;
}

void Tv::ChannelUp()
{
	m_channel++;
	if (m_channel < 0)
	{
		m_channel = m_maxChannel;
	}
}

void Tv::ChannelDown()
{
	m_channel--;
	if (m_channel > m_maxChannel)
	{
		m_channel = 0;
	}
}

void Tv::Settings()const
{
	std::cout << "Tv = " << (m_state == On ? "On" : "Off") << std::endl;
	if (m_state == On)
	{
		std::cout << "Volume = " << m_volume << std::endl;
		std::cout << "Channel = " << m_channel << std::endl;
		std::cout << "Mode = " << (m_mode == Antenna ? "Antenna" : "Cable") << std::endl;
		std::cout << "Input = " << (m_input == TV ? "TV" : "VCR") << std::endl;
	}
}