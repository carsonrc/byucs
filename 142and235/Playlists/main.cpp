//A Note regarding 'using namespace std':
// The author of this code prefers to not have the line 'using namespace std;'
// Instead, you will see 'std::' in front of string, cout, and other identifiers
// You could put 'using namespace std;' at the top of your code and not need 'std::' in front of these words,
// but many people consider it better practice to not have 'using namespace std;'


#include <iostream>
#include <string>
#include <vector>
#include "Song.h"
#include "Playlist.h"

std::string GetUserString(const std::string& prompt);

void AddSongsMenuOption(vector<Song*> &songLibrary);
void ListSongsMenuOption(vector<Song*> songLibrary);
void AddPlaylistMenuOption(vector<Playlist*> &playlistLibrary);
void AddSongToPlaylistMenuOption(vector<Playlist*> &playlistLibrary, vector<Song*> songLibrary);
void ListPlaylistsMenuOption(vector<Playlist*> playlistLibrary);
void PlayPlaylistMenuOption(vector<Playlist*> playlistLibrary);
void RemovePlaylistMenuOption(vector<Playlist*> &playlistLibrary);
void RemoveSongFromPlaylistMenuOption(vector<Playlist*> &playlistLibrary, vector<Song*> songLibrary);
void RemoveSongFromLibraryMenuOption(vector<Song*> &songLibrary);
void OptionsMenuOption();
void QuitMenuOption(vector<Playlist*> playlistLibrary, vector<Song*> songLibrary);

int main() {
    std::cout << "Welcome to the Firstline Player!  Enter options to see menu options." << std::endl << std::endl;

    vector<Song*> library;
    vector<Playlist*> playlistLibrary;

    std::string userMenuChoice = "none";
    bool continueMenuLoop = true;

    while (continueMenuLoop) {
        userMenuChoice = GetUserString("Enter your selection now: ");

        if (userMenuChoice == "add") {
            AddSongsMenuOption(library);
        }
        else if (userMenuChoice == "list") {
            ListSongsMenuOption(library);
        }
        else if (userMenuChoice == "addp") {
            AddPlaylistMenuOption(playlistLibrary);
        }
        else if (userMenuChoice == "addsp") {
            AddSongToPlaylistMenuOption(playlistLibrary, library);
        }
        else if (userMenuChoice == "listp") {
            ListPlaylistsMenuOption(playlistLibrary);
        }
        else if (userMenuChoice == "play") {
            PlayPlaylistMenuOption(playlistLibrary);
        }
        else if (userMenuChoice == "remp") {
            RemovePlaylistMenuOption(playlistLibrary);
        }
        else if (userMenuChoice == "remsp") {
            RemoveSongFromPlaylistMenuOption(playlistLibrary, library);
        }
        else if (userMenuChoice == "remsl") {
            RemoveSongFromLibraryMenuOption(library);
        }
        else if (userMenuChoice == "options") {
            OptionsMenuOption();
        }
        else if (userMenuChoice == "quit") {
            QuitMenuOption(playlistLibrary, library);
            continueMenuLoop = false;
        }
        else {
            OptionsMenuOption();
        }
    }

    return 0;
}


std::string GetUserString(const std::string& prompt) {
    std::string userAnswer = "none";

    std::cout << prompt;
    std::getline(std::cin, userAnswer);
    std::cout << std::endl;
    return userAnswer;
}
int GetUserInt(const std::string& prompt) {
    int userAnswer = 0;

    std::cout << prompt;
    std::cin >> userAnswer;
    std::cin.ignore();
    std::cout << std::endl;
    return userAnswer;
}

void AddSongsMenuOption(vector<Song*> &songLibrary) {
    const std::string DONE_KEYWORD = "DONE";
    std::cout << "Enter songs' names and first lines"
              << " (type \"" << DONE_KEYWORD << "\" when done):" << std::endl;

    std::string songName = "none";
    std::string firstLine = "none";
    int it = 0;

    songName = GetUserString("Song Name: ");
    while (songName != DONE_KEYWORD) {
        firstLine = GetUserString("Song's first line: ");

        songLibrary.push_back(new Song);
        songLibrary[it]-> SetName(songName);
        songLibrary[it]->SetFirstLine(firstLine);

        it++;
        songName = GetUserString("Song Name: ");
    }
}

void ListSongsMenuOption(vector<Song*> songLibrary) {
    for (int i = 0; i < songLibrary.size(); i++) {
        cout << songLibrary[i]->GetName() << ": \"" << songLibrary[i]->GetFirstLine() << "\", "
             << songLibrary[i]->GetNumTimesPlayed() << " play(s)." << endl;
    }
}

void AddPlaylistMenuOption(vector<Playlist*> &playlistLibrary) {
    string playlistName = "none";
    playlistName = GetUserString("Playlist name: ");
    playlistLibrary.push_back(new Playlist);
    playlistLibrary[playlistLibrary.size() - 1]->SetPlaylistName(playlistName);

}

void AddSongToPlaylistMenuOption(vector<Playlist*> &playlistLibrary, vector<Song*> songLibrary) {
    int indexNumberPlaylist;
    int indexNumberSong;

    ListPlaylistsMenuOption(playlistLibrary);
    indexNumberPlaylist = GetUserInt("Pick a playlist index number: ");

    for (int i = 0; i < songLibrary.size(); i++) {
        cout << i << ": " << songLibrary[i]->GetName() << endl;
    }
    indexNumberSong = GetUserInt("Pick a song index number: ");
    playlistLibrary[indexNumberPlaylist]->AddSongToPlaylist(songLibrary[indexNumberSong]);
}

void ListPlaylistsMenuOption(vector<Playlist*> playlistLibrary) {
    for (int i = 0; i < playlistLibrary.size(); i++) {
        cout << i << ": " << playlistLibrary[i]->GetPlaylistName() << endl;
    }
}

void PlayPlaylistMenuOption(vector<Playlist*> playlistLibrary) {
    int indexNumberPlaylist = 0;

    ListPlaylistsMenuOption(playlistLibrary);
    indexNumberPlaylist = GetUserInt("Pick a playlist index number: ");

    cout << "Playing songs from playlist: " << playlistLibrary[indexNumberPlaylist]->GetPlaylistName() << endl;
    playlistLibrary[indexNumberPlaylist]->PlayPlaylist();

}

void RemovePlaylistMenuOption(vector<Playlist*> &playlistLibrary) {
    int indexNumberPlaylist = 0;
    Playlist* tempPtr;
    ListPlaylistsMenuOption(playlistLibrary);
    indexNumberPlaylist = GetUserInt("Pick a playlist index number to remove: ");
    tempPtr = playlistLibrary[indexNumberPlaylist];
    playlistLibrary.erase(playlistLibrary.begin() + indexNumberPlaylist);
    delete tempPtr;                                                                          //memory dealloc

}

void RemoveSongFromPlaylistMenuOption(vector<Playlist*> &playlistLibrary, vector<Song*> songLibrary) {
    int indexNumberPlaylist = 0;
    int indexNumberSong = 0;

    ListPlaylistsMenuOption(playlistLibrary);
    indexNumberPlaylist = GetUserInt("Pick a playlist index number: ");

    playlistLibrary[indexNumberPlaylist]->ListAllSongs();
    indexNumberSong = GetUserInt("Pick a song index number to remove: ");
    playlistLibrary[indexNumberPlaylist]->RemoveSongFromPlaylist(indexNumberSong);
}

void RemoveSongFromLibraryMenuOption(vector<Song*> &songLibrary) {
    Song* tempPtr;
    int indexNumberSong = 0;
    for (int i = 0; i < songLibrary.size(); i++) {
        cout << i << ": " << songLibrary[i]->GetName() << endl;
    }
    indexNumberSong = GetUserInt("Pick a song index number to remove: ");
    tempPtr = songLibrary[indexNumberSong];
    songLibrary.erase(songLibrary.begin() + indexNumberSong);
    delete tempPtr;                                                                     //memory dealloc
}

void OptionsMenuOption() {
    std::cout << "add      Adds a list of songs to the library" << std::endl
              << "list     Lists all the songs in the library" << std::endl
              << "addp     Adds a new playlist" << std::endl
              << "addsp    Adds a song to a playlist" << std::endl
              << "listp    Lists all the playlists" << std::endl
              << "play     Plays a playlist" << std::endl
              << "remp     Removes a playlist" << std::endl
              << "remsp    Removes a song from a playlist" << std::endl
              << "remsl    Removes a song from the library (and all playlists)" << std::endl
              << "options  Prints this options menu" << std::endl
              << "quit     Quits the program" << std::endl << std::endl;
}

void QuitMenuOption(vector<Playlist*> playlistLibrary, vector<Song*> songLibrary) {        //last memory dealloc
    std::cout << "Goodbye!" << std::endl;
    for (int i = 0; i < playlistLibrary.size(); i++) {
        delete playlistLibrary[i];
    }
    for (int i = 0; i < songLibrary.size(); i++) {
        delete songLibrary[i];
    }
}

