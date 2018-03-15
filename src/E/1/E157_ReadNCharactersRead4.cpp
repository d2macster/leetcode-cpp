//
// Created by Andrii Cherniak on 3/15/18.
//

// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int read_len = 0;
        char buf4[4];
        int r4 = read4(buf4);
        while (read_len < n && r4){
            for(int i = 0; i < r4 && read_len < n; i++)
                buf[read_len++] = buf4[i];
            r4 = read4(buf4);
        }
        return read_len;
    }
};