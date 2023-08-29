#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>
#include <ctime> //To retrieve system time
#include <fstream> //To handle files
#include <windows.h> //For OS based commands
#include <string>
#include <unistd.h> //Provides access to the POSIX operating system API

using namespace std;

class User
{
private:
    string name;
public:
    User();
    User(string);
    string get_name();
    void set_name();
    ~User();
};

class Clock
{
private:
    int hour;
    int minute;
    int second;
public:
    Clock();
    Clock(int h, int m, int s);
    void readTime();
    void findTime(string);
    void display();
    void get_alarm_time();
    void set_alarm();
    int getHour();
    int getMin();
    int getSec();
    ~Clock();
};
class MusicPlayer
{
private:
    string song_name;
public:
    MusicPlayer();
    MusicPlayer(string sname);
    void setSong_name(string nam);
    void play_song_online();
    void play_song_sys();
    ~MusicPlayer();
};
class VideoPlayer
{
private:
    string name;
public:
    void watch_videos();
    void set_name(string);
};
class Assistant
{
private:
    string name;
    Clock &c;
    User u;
    MusicPlayer m;
    VideoPlayer v;
public:
    Assistant(Clock& c1);
    void read();
    void speak(string);
    void introduce();
    void list_commands();
    void get_command();
    void command_responder();
    void display();
    void watch_videos(string);
    void my_ip();
    void list_songs();
    void open_browser();
    void help();
    ~Assistant();
};

#endif // HEADER_H_INCLUDED
