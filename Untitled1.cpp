#include"header.h"
#include<typeinfo>

User::User()
{
    name = "";
}

User::User(string nam)
{
    name = nam;
}

void User::set_name() //Sets the user name
{
    cout<<"\n\t\tEnter your Name: ";
    getline(cin, name);
}

string User::get_name() // Returns the user name
{
    return name;
}

User::~User()
{

}

Clock::Clock()
{
    hour = 0;
    minute = 0;
    second = 0;
}
Clock::Clock(int h, int m, int s)
{
    hour = h;
    minute = m;
    second = s;
}
void Clock::readTime() //Reads the system time
{
    time_t now = time(0);
    tm*ltm = localtime(&now);
    hour=(ltm->tm_hour);
    minute=(ltm->tm_min);
    second=(ltm->tm_sec);
}

void Clock::get_alarm_time() //Inputs the time to set alarm
{
    cout<<"\n\t\tEnter the time to set alarm (HH:MM:SS): ";
    cin>>hour;
    getchar();
    cin>>minute;
    getchar();
    cin>>second;
}

void Clock::set_alarm() //Sets the alarm at the specified time
{
    while(1)
    {
        Clock current;
        time_t now = time(0);
        tm*ltm = localtime(&now);
        current.hour = (ltm->tm_hour);
        current.minute = (ltm->tm_min);
        current.second = (ltm->tm_sec);
        if((current.hour == this->hour) && (current.minute == this->minute))
        {
            system("CLS");
            cout<<"\n\t\t\t-------------------"<<endl;
            cout<<"\n\t\t\t      WAKE UP !!     "<<endl;
            cout<<"\n\t\t\t-------------------"<<endl;
            Beep(523,8000);
            break;
        }
        else
        {
            system("CLS");
            current.display();
            cout<<endl;
            Sleep(1);
            system("CLS");
            continue;
            Sleep((60-current.second)*1000);
        }
    }
    system("CLS");
}
int Clock::getHour()
{
    return hour;
}
int Clock::getMin()
{
    return minute;
}
int Clock::getSec()
{
    return second;
}
Clock::~Clock()
{
}

void Assistant::my_ip() //Retrieves the ip address of the system
{
        system("ipconfig");
}
void Assistant::display() //Displays the welcome screen
{
    string quote = "High cohesion and low coupling is needed for good modeling";
    speak(quote);
    cout<<"\n\t\t\t\t\""<<quote<<"\""<<endl;
    speak("And that is how I am modeled.");
    cout<<"\n\t\t\t\t\t*************************************************"<<endl;
    cout<<"\t\t\t\t\tHey there! I'm ZOYA I am your personal assistant."<<endl;
    cout<<"\n\t\t\t\t\t*************************************************"<<endl;
    speak("Hey there I am ZOYA I'm your personal assistant");
    c.readTime();
    c.display();
}
void Assistant::read()
{
    speak("Hello user, your sweet name please");
    u.set_name();
}
void Assistant::introduce() //Assistant introduces itself
{
    string greet;
    if(c.getHour() < 12)
    {
        greet="Good morning ";
    }
    else if (c.getHour() >=12)
    {
        if(c.getHour() >16)
            greet="Good evening ";
        else
            greet="Good afternoon ";
    }
    speak(greet + u.get_name());
    cout<<"\n\t\t"<<greet<<", "<<u.get_name()<<endl;

    list_commands();
}

void Assistant::list_commands() //Lists out the commands the assistant can take
{
    int loopCounter = 0;
    ifstream file;
    file.open("README.txt", ios::in);
    string command, description, quote;
    speak("Here is a list of commands that I can handle");
    cout<<"\n\t\tHere's a list of commands that I can handle:-"<<endl;
    while(!file.eof())
    {
        loopCounter++;
        getline(file, command);
        getline(file, description);
        getline(file, quote);
        cout<<"\n\t\t\t"<<loopCounter<<". "<<command<<endl;
        cout<<"\t\t\t\t"<<description<<endl;
        cout<<"\n\t\t\t\t\t\""<<quote<<"\""<<endl;
    }
}

void Clock::display() //Displays the clock
{
    cout<<"\n\t\t\t\t\t";
    cout<<hour<<" hours "<<minute <<" minutes "<<second<<" seconds "<<endl;
}
void Assistant::speak(string s) //Speaks the string passed
{
    string phrase = s;
    string command = "espeak -v +f4 \""+phrase+"\"";
    const char *charCommand = command.c_str(); //Converting string object to character array
    system(charCommand);
}
void Assistant::list_songs() //Lists the songs available in the system
{
    fstream songfile;
    int loopCounter = 0;
    songfile.open("C:\\Users\\shine\\Music\\mysongs.txt",ios::in);
    string line;
    cout<<"\n\t\tSongs list:-"<<endl;
    while(!songfile.eof())
    {
        speak(line);
        getline(songfile,line);
        if (line == "")
            break;
        cout<<"\n\n\t\t"<<++loopCounter<<". "<<line<<endl;
    }
}
void Assistant::open_browser() //Opens the browser
{
    system("start chrome");
}

Assistant::Assistant(Clock& c1) :c(c1)
{
    name = "";
}
void Assistant::get_command() //Processes the command given by user
{
    system("cls");
    c.readTime();
    c.display();
    string str_inp;
    string name = u.get_name();
    string greet = "Good bye" + name;
    while(1)
    {
        speak("How would you like me to help you");
        string command = "";
        cout<<"\n\t\tType \"help\" for list of commands.";
        cout<<"\n\t\tYour command: ";
        getline(cin, str_inp);
        int posn = str_inp.find(" ");
        command = str_inp.substr(0, posn);
        int next_lineposn = str_inp.find('\n');
        string rest_word = str_inp.substr(posn+1, next_lineposn);

        if((command=="play" || command=="PLAY" ) && (rest_word != "" ||rest_word !=" " || rest_word !="  "))
        {
            string song = rest_word;
            m.setSong_name(song);
            fstream music;
            music.open("C:\\Users\\shine\\Music\\mysongs.txt", ios::in);
            string line;
            int flag=0;
            if(!music)
            {
                cout<<"file not open";
            }
            while(!music.eof())
            {
                getline(music, line);
                if(line == song)
                {
                    speak("Song found in your system.");
                    speak("Playing song" + song);
                    flag=1;
                    m.play_song_sys();
                }
            }
            if(flag!=1)
            {
                speak("Song not found in your system.");
                speak("Playing song online");
                m.play_song_online();
            }
            music.close();
        }
        else if(command=="alarm" || command=="ALARM")
        {
            Clock c2;
            speak("Enter the alarm time");
            c2.get_alarm_time();
            c2.set_alarm();
            command = "help";
        }
        else if(command=="watch")
        {
            v.set_name(rest_word);
            v.watch_videos();
        }
        else if(command=="find"||command=="myip" || command=="findmyip" || command=="FIND MY IP")
        {
            if (rest_word == "my ip" || rest_word == "myip" || rest_word == "MY IP")
            {
                speak("Retrieving your IP address");
                my_ip();
            }
        }
        else if((command=="list"||command=="LIST") && (rest_word=="songs"||rest_word=="song"))
        {
            speak("Here are the songs available in your system");
            list_songs();
        }
        else if(command=="browse")
        {
            open_browser();
        }
        else if(command=="exit")
        {
            speak(greet);
            speak("Hope you found me helpful");
            exit(0);
        }
        else if(command=="help")
        {
            list_commands();
        }
        else
        {
            speak("Sorry I was not able to recognise your command");
            list_commands();
        }
    }
}

Assistant::~Assistant()
{

}
MusicPlayer::MusicPlayer()
{
    song_name = "";
}
MusicPlayer::MusicPlayer(string sname)
{
    song_name = sname;
}
void MusicPlayer::setSong_name(string nam)
{
    song_name = nam;
}
void MusicPlayer::play_song_online() //To play songs online, if not available in system
{
    string path="start";
    path=path+" https://gaana.com/song/";
    path=path+song_name;
    const char *c=path.c_str();
    system(c);
}

void MusicPlayer::play_song_sys() //To play songs available offline
{
    string path = "C:\\Users\\shine\\Music\\";
    path = path + "\"" + song_name + ".mp3\"";
    const char *c = path.c_str();
    system(c);
}

MusicPlayer::~MusicPlayer()
{

}

void VideoPlayer::set_name(string s) // set the name of the video
{
    name=s;
}

void VideoPlayer::watch_videos() // goes to youtube
{
    string vid_name=this->name;
    for(int i=0; vid_name[i]!='\0'; i++) //Converting vid_name to pass to youtube url
    {
        if(vid_name[i]==' ')
        vid_name[i]='+';
    }
    string url;
    url = "start https://www.youtube.com/results?search_query=";
    url += vid_name;
    system(string(url).c_str());
    //speak("Choose the video you wish to watch");
}
