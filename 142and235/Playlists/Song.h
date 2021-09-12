//
// Created by carso on 12/3/2020.
//

#ifndef PLAYLISTS_SONG_H
#define PLAYLISTS_SONG_H
#include <string>
using namespace std;


class Song {
private:
    string songName;
    string firstLine;
    int numTimesPlayed;

public:
    explicit Song(string firstName = "null", string firstLine = "null");
    void SetName(string nameOfSong);
    string GetName();
    void SetFirstLine(string firstLine);
    string GetFirstLine();
    int GetNumTimesPlayed();
    void IncrementTimesPlayed();



};


#endif //PLAYLISTS_SONG_H
