#include <iostream>
#include <stdlib.h>
#include <vector>

class Track
{
public:
    std::string name;
    std::string date ;
    int duration;

};

class Player
{
    std::vector<Track*> playlist;
    Track* track1 = new Track {"Track1", "12/05/1982", 150};
    Track* track2 = new Track {"Track2", "15/12/2015", 250};
    Track* track3 = new Track {"Track3", "18/10/2020", 351};

    public:
    void trackTemplate()
    {
        playlist.push_back(track1);
        playlist.push_back(track2);
        playlist.push_back(track3);
    }

    void add()
    {
        playlist.push_back(new Track());

        std::cout << "Enter record name: ";
        std::cin >> playlist[playlist.size() - 1]->name;
        std::cout << "Enter date of creation: ";
        std::cin >> playlist[playlist.size() - 1]->date;
        std::cout << "Enter duration: ";
        std::cin >> playlist[playlist.size() - 1]->duration;
    }

    void del()
    {
        std::string input;
        std::cout << "Enter the name of the track you want to delete: ";
        std::cin >> input;

        for (int i = 0; i < playlist.size(); ++i)
        {
            if (input == playlist[i]->name)
            {
                auto iter = playlist.cbegin();
                playlist.erase(iter + i);
            }
        }
    }


    void play()
    {
        trackTemplate();
        std::string record_name;
        Track* track;
        bool found = false;

        while (!found)
        {
            std::cout << "Enter the name of the entry: ";
            std::cin >> record_name;

            for (int i = 0; i < playlist.size(); ++i)
            {
                if (record_name == playlist[i]->name)
                {
                    track = playlist[i];
                    found = true;
                    break;
                }
            }

            if (found)
                std::cout << "Record name: " << track->name << ", date of creation: " << track->date << ", duration: "
                          << track->duration << " seconds." << std::endl;
            else std::cout << "Track with given name not found!!!" << std::endl;
        }
    }

    void pause()
    {
        std::cout << "PAUSE!!!" << std::endl;
    }

    void next()
    {
        Track* track = playlist[rand() % playlist.size()];

        std::cout << "Record name: " << track->name << ", date of creation: " << track->date << ", duration: "
                  << track->duration << " seconds." << std::endl;
    }

    void stop()
    {
        std::cout << "STOP!!!" << std::endl;
    }
};


int main() {
    Player player;
    std::string command;
    bool plays = false;
    bool pause_track = false;
    bool stop_track = false;
    bool playlist = false;

    while (command != "exit")
    {
        std::cout << "Enter command (add, delete, play, pause, next, stop, exit): ";
        std::cin >> command;

        if (command == "add")
        {
            if (!playlist)
            {
                player.trackTemplate();
                playlist = true;
            }
            player.add();
        }

        if (command == "delete") player.del();

        if (command == "play" && !plays)
        {
            plays = true;
            stop_track = false;
            player.play();
        }

        if (command == "pause" && plays && !pause_track)
        {
            pause_track = true;
            player.pause();
        }

        if (command == "next")
        {
            plays = true;
            player.next();
        }

        if (command == "stop" && plays && !stop_track)
        {
            stop_track = true;
            plays = false;
            player.stop();
        }
    }


}
