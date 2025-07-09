#include <vector>
#include <iostream>
#include <map>
#include <memory>
#include <string>


class Note
{
	public:
		virtual void	show( void ) = 0;
};

class Image: public Note
{
	private:
		std::string	path;
		int			resolution;

	public:
		Image(std::string path, int resolution): path(path), resolution(resolution) {}
		virtual void	show( void ) override
		{
			std::cout << "Path: " << this->path << std::endl;
			std::cout << "Resolution: " << this->resolution << std::endl;
		}
};

class Video: public Note
{
	private:
		std::string	path;
		int			resolution;
		int			lenght;

	public:
		Video(std::string path, int resolution, int lenght): path(path), resolution(resolution), lenght(lenght) {}
		virtual void	show( void ) override
		{
			std::cout << "Path: " << this->path << std::endl;
			std::cout << "Resolution: " << this->resolution << std::endl;
			std::cout << "Lenght: " << this->lenght << std::endl;
		}
};

class Audio: public Note
{
	private:
		std::string	path;
		int			lenght;

	public:
		Audio(std::string path, int lenght): path(path), lenght(lenght) {}
		virtual void	show( void ) override
		{
			std::cout << "Path: " << this->path << std::endl;
			std::cout << "Lenght: " << this->lenght << std::endl;
		}
};

class NotePad {
private:
    std::map<std::string, std::unique_ptr<Note>> note;

public:
    void add(const std::string& titolo, std::unique_ptr<Note> nota) {
        note[titolo] = std::move(nota);
    }

    void remove(const std::string& titolo) {
        note.erase(titolo);
    }

    void show(const std::string& titolo) const {
        auto it = note.find(titolo);
        if (it != note.end()) {
            it->second->show();
        } else {
            std::cout << "Note non trovata\n";
        }
    }

    void showAll() const {
        for (const auto& pair : note) {
            std::cout << "[" << pair.first << "] ";
            pair.second->show();
        }
    }

    Note& operator[](const std::string& titolo) {
        return *(note.at(titolo));
    }
};

int main() {
	NotePad pad;
	std::unique_ptr<Video>	video(new Video("video.mp4", 100000, 7.30));
	std::unique_ptr<Image>	image(new Image("foto.jpg", 100000));
	std::unique_ptr<Audio>	audio(new Audio("audio.mp3", 3.42));

	pad.add("Video", std::move(video));
	pad.add("Immagine", std::move(image));
	pad.add("Audio", std::move(audio));

	pad.show("Video");
	pad.showAll();

	pad.remove("Immagine");
	pad.showAll();

	return 0;
}
