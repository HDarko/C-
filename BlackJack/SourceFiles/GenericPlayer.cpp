#include "GenericPlayer.h"



GenericPlayer::GenericPlayer(std::string name )
	:m_Name{ name }
{
}





bool GenericPlayer::isBusted()
{
	return ((m_Hand->GetTotal())>21);
}

void GenericPlayer::Burst()
{
	std::cout << m_Name << " bursts\n";

}

std::string GenericPlayer::getName()
{
	return m_Name;
}