#pragma once

#include<iostream>

class Tv;

class Remote
{
private:
	int m_mode;
public:
	enum { Off, On };
	enum { MinVolume, MaxVolume = 20 };
	enum { Antenna, Cable };
	enum { TV, VCR };

	Remote(int m = TV) : m_mode(m) {}
	bool VolumeUp(Tv& tv);
	bool VolumeDown(Tv& tv);
	void OnOff(Tv& tv);
	void ChannelUp(Tv& tv);
	void ChannelDown(Tv& tv);
	void SetChannel(Tv& tv, int channel);
	void SetMode(Tv& tv);
	void SetInput(Tv& tv);
};

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
	friend void Remote::SetChannel(Tv& tv, int channel);
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

inline bool Remote::VolumeUp(Tv& tv) { return tv.VolumeUp(); }
inline bool Remote::VolumeDown(Tv& tv) { return tv.VolumeDown(); }
inline void Remote::OnOff(Tv& tv) { tv.OnOff(); }
inline void Remote::ChannelUp(Tv& tv) { tv.ChannelUp(); }
inline void Remote::ChannelDown(Tv& tv) { tv.ChannelDown(); }
inline void Remote::SetChannel(Tv& tv, int channel) { tv.m_channel = channel; }
inline void Remote::SetMode(Tv& tv) { tv.SetMode(); }
inline void Remote::SetInput(Tv& tv) { tv.SetInput(); }
