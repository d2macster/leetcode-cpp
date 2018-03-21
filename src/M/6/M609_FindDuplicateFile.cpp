//
// Created by Andrii Cherniak on 3/21/18.
//
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string> > findDuplicate(vector<string> &paths) {
        string fs, root, file_name, file_content;
        unordered_map<string, vector<string> > content_files;
        for (string &p: paths) {
            istringstream in(p);
            vector<string> file_data;
            while (in >> fs) file_data.push_back(fs);
            root = file_data[0];
            for (int i = 1; i < file_data.size(); i++) {
                int begin = file_data[i].find('(');
                file_name = root + '/' + file_data[i].substr(0, begin);
                file_content = file_data[i].substr(begin, file_data[i].size() - begin);
                content_files[file_content].push_back(file_name);
            }
        }
        vector<vector<string> > duplicates;
        for (auto it: content_files){
            if (it.second.size() > 1) duplicates.push_back(it.second);
        }
        return duplicates;
    }
};