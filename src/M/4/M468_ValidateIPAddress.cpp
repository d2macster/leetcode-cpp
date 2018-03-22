//
// Created by Andrii Cherniak on 3/22/18.
//
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
    bool check_ipv4(vector<string> ip_data) {
        if (ip_data.size() != 4) return false;
        for (string &s: ip_data) {
            if (s.size() > 3) return false;
            istringstream in(s);
            int n = 0;
            in >> n;
            if (n < 0 || n > 255 || to_string(n) != s) return false;
        }
        return true;
    }

    bool check_ipv6(vector<string> ip_data){
        if (ip_data.size() != 8) return false;
        for (string &s: ip_data) {
            if (s.size() > 4) return false;
            for (char c : s) if (!(c >= '0' && c <= '9') && !(c >= 'a' && c <= 'f')) return false;
        }
        return true;
    }

public:
    string validIPAddress(string IP) {
        transform(IP.begin(), IP.end(), IP.begin(), ::tolower);
        int L = IP.size();
        string s = "";
        bool ipv4 = false, ipv6 = false;
        vector<string> ip_data;
        for (char c: IP) {
            if (c != '.' && c != ':') s += c;
            else {
                if (s == "")
                    return "Neither";
                ip_data.push_back(s);
                s = "";
                if (c == '.') ipv4 = true;
                else ipv6 = true;
            }
        }
        if (s == "")
            return "Neither";
        ip_data.push_back(s);

        if (!ipv4 && !ipv6) return "Neither";
        if (ipv4 && ipv6) return "Neither";
        if (ipv4 && check_ipv4(ip_data)) return "IPv4";
        if (ipv6 && check_ipv6(ip_data)) return "IPv6";
        return "Neither";
    }
};