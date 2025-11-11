#include "play_sound.h"

void play_sound()
{
	std::string cmd = "afplay \"ttsout/generated.wav\"";
	system(cmd.c_str());
}