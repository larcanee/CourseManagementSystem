/* Header file for CMSLogger - Assignment 4 by Emma Giacometti (CSS343B)*/
#ifndef CMSLOGGER_H_
#define CMSLOGGER_H_

#include <iostream>
#include <fstream>

using namespace std;

class CMSLogger
{
    private:
        static CMSLogger instance;
        vector<string> logs;

        CMSLogger() {}
        ~CMSLogger() {}
    
    public:
        //Returns an instance of CMSLogger
        static CMSLogger& getInstance() 
        {
            static CMSLogger instance;
            return instance;
        }

        //Adds a log message and outputs it to a txt file
        //PRE: message describes an action made by the CMS
        //POST: message is added to CMSLog.txt
        void log(string message)
        {
            logs.push_back(message);
            updateFile();
        }

        //Updates the log file
        void updateFile()
        {
            fstream logFile;
            logFile.open("CMSLog.txt", ios::out);
            if (!logFile.is_open()) {
                cerr << "Failed to open log file" << endl;
            } else {
                for (int i = 0; i < logs.size(); i++) {
                    logFile << logs[i] << endl;
                }
            }
            logFile.close();
        }
};

#endif