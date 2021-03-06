//
// Created by Andrii Cherniak on 2/6/18.
//
#include <string>
#include <unordered_map>
using std::string;
using std::unordered_map;

class Logger {
    unordered_map<string, int> log;
public:
    /** Initialize your data structure here. */
    Logger() {

    }

    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        if (log.find(message) == log.end()){
            log[message] = timestamp;
            return true;
        }else{
            if (timestamp - log[message] >= 10){
                log[message] = timestamp;
                return true;
            }else return false;
        }
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger obj = new Logger();
 * bool param_1 = obj.shouldPrintMessage(timestamp,message);
 */