/*
** EPITECH PROJECT, 2018
** R-Type
** File description:
** Music
*/

#ifndef MUSIC_HPP_
	#define MUSIC_HPP_

    #include <SFML/Audio.hpp>

class Music {
	public:
		Music(const std::string &path);
		~Music();
        inline void play() { _music.play(); };
        inline void isRepeatable(bool repeat) { _music.setLoop(repeat); };

	private:
        sf::Music _music;
};

#endif /* !MUSIC_HPP_ */