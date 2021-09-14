//
// Created by carso on 12/3/2020.
//

#include <iostream>
#include "Playlist.h"

void Playlist::AddSongToPlaylist(Song* newSong) {
    playlist.push_back(newSong);
}

void Playlist::PlayPlaylist() {
    for (int i = 0; i < playlist.size(); i++) {
        playlist[i]->IncrementTimesPlayed();
        cout << playlist[i]->GetFirstLine() << endl;
    }
}

void Playlist::SetPlaylistName(string name) {
    playlistName = name;
}

string Playlist::GetPlaylistName() {
    return playlistName;
}

void Playlist::ListAllSongs() {
    for (int i = 0; i < playlist.size(); i++) {
        cout << i << ": " << playlist[i]->GetName() << endl;
    }
}

void Playlist::RemoveSongFromPlaylist(int songIndex) {
    playlist.erase(playlist.begin() + songIndex);
}
