#pragma once

#include<iostream>

class Tv
{
private:
	int m_state;
	int m_volume;
	int m_maxChannel;
	int m_channel;
	int m_mode;
	int m_input;
public:
	friend class Remote;
	enum { Off, On };
	enum { MinVolume, MaxVolume = 20 };
	enum { Antenna, Cable };
	enum { TV, VCR };

	Tv(int s = Off, int mc = 100) : m_state(s), m_volume(5), m_maxChannel(mc), m_channel(2), m_mode(Cable), m_input(TV) {}
	void OnOff() { m_state = (m_state == On) ? Off : On; }
	bool IsOn()const { return m_state == On; }
	bool VolumeUp();
	bool VolumeDown();
	void ChannelUp();
	void ChannelDown();
	void SetMode() { m_mode = (m_mode == Antenna) ? Cable : Antenna; }
	void SetInput() { m_input = (m_input == TV) ? VCR : TV; }
	void Settings()const;
};

class Remote
{
private:
	int m_mode;
public:
	Remote(int m = Tv::TV) : m_mode(m) {}
	bool VolumeUp(Tv& tv) { return tv.VolumeUp(); }
	bool VolumeDown(Tv& tv) { return tv.VolumeDown(); }
	void OnOff(Tv& tv) { tv.OnOff(); }
	void ChannelUp(Tv& tv) { tv.ChannelUp(); }
	void ChannelDown(Tv& tv) { tv.ChannelDown(); }
	void SetChannel(Tv& tv, int channel) { tv.m_channel = channel; }
	void SetMode(Tv& tv) { tv.SetMode(); }
	void SetInput(Tv& tv) { tv.SetInput(); }
};

