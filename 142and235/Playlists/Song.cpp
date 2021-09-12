//
// Created by carso on 12/3/2020.
//

#include "Song.h"

Song::Song(string firstName, string firstLine) {
    songName = firstName;
    this->firstLine = firstLine;
    numTimesPlayed = 0;
}

void Song::SetName(string nameOfSong) {
    songName = nameOfSong;
}

void Song::SetFirstLine(string firstLine) {
    this->firstLine = firstLine;
}

string Song::GetName() {
    return songName;
}

string Song::GetFirstLine() {
    return firstLine;
}

int Song::GetNumTimesPlayed() {
    return numTimesPlayed;
}

void Song::IncrementTimesPlayed() {
    numTimesPlayed++;
}


