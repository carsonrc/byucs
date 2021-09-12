//
// Created by carso on 12/3/2020.
//

#ifndef PLAYLISTS_PLAYLIST_H
#define PLAYLISTS_PLAYLIST_H

#include <vector>
#include "Song.h"
using namespace std;


class Playlist {
private:
    vector<Song*> playlist;
    string playlistName = "none";
public:
    void AddSongToPlaylist(Song* newSong);
    void RemoveSongFromPlaylist(int songIndex);
    void PlayPlaylist();
    void SetPlaylistName(string name);
    string GetPlaylistName();
    void ListAllSongs();
};


#endif //PLAYLISTS_PLAYLIST_H
