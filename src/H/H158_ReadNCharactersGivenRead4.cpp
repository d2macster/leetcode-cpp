//
// Created by Andrii Cherniak on 4/19/18.
//

// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
    char read4_buff[4];
    int read4_n = 0;
    int read4_id = 0;
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int i = 0;
        while (i < n && (read4_id < read4_n || (read4_id = 0) < (read4_n = read4(read4_buff)))){
            buf[i++] = read4_buff[read4_id++];
        }
        return i;
    }
};