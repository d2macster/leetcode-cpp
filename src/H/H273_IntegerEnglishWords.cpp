//
// Created by Andrii Cherniak on 5/22/18.
//
#include <string>
#include <vector>

using namespace std;

class Solution {
    string number(int v) {
        string result = "";
        int a = v / 100;
        int b = (v % 100) / 10;
        int c = v % 10;
        if (a == 1) result += "One Hundred";
        else if (a == 2) result += "Two Hundred";
        else if (a == 3) result += "Three Hundred";
        else if (a == 4) result += "Four Hundred";
        else if (a == 5) result += "Five Hundred";
        else if (a == 6) result += "Six Hundred";
        else if (a == 7) result += "Seven Hundred";
        else if (a == 8) result += "Eight Hundred";
        else if (a == 9) result += "Nine Hundred";

        if (b == 1) {
            if (result != "") result += " ";
            if (c == 0) result += "Ten";
            else if (c == 1) result += "Eleven";
            else if (c == 2) result += "Twelve";
            else if (c == 3) result += "Thirteen";
            else if (c == 4) result += "Fourteen";
            else if (c == 5) result += "Fifteen";
            else if (c == 6) result += "Sixteen";
            else if (c == 7) result += "Seventeen";
            else if (c == 8) result += "Eighteen";
            else if (c == 9) result += "Nineteen";
        }
        if (b > 1 && result != "") result += " ";
        if (b == 2) result += "Twenty";
        else if (b == 3) result += "Thirty";
        else if (b == 4) result += "Forty";
        else if (b == 5) result += "Fifty";
        else if (b == 6) result += "Sixty";
        else if (b == 7) result += "Seventy";
        else if (b == 8) result += "Eighty";
        else if (b == 9) result += "Ninety";

        if (b != 1) {
            if (c != 0 && result != "") result += " ";
            if (c == 1) result += "One";
            else if (c == 2) result += "Two";
            else if (c == 3) result += "Three";
            else if (c == 4) result += "Four";
            else if (c == 5) result += "Five";
            else if (c == 6) result += "Six";
            else if (c == 7) result += "Seven";
            else if (c == 8) result += "Eight";
            else if (c == 9) result += "Nine";
        }

        return result;
    }

public:
    string numberToWords(int num) {
        string result = "";
        int v1 = num % 1000;
        int v2 = (num % 1000000) / 1000;
        int v3 = (num % 1000000000) / 1000000;
        int v4 = (num % 1000000000000) / 1000000000;

        if (v4 > 0) {
            if (result != "") result += " ";
            result += number(v4) + " Billion";
        }
        if (v3 > 0) {
            if (result != "") result += " ";
            result += number(v3) + " Million";
        }
        if (v2 > 0) {
            if (result != "") result += " ";
            result += number(v2) + " Thousand";
        }
        if (v1 > 0) {
            if (result != "") result += " ";
            result += number(v1);
        }

        if (result == "") result = "Zero";

        return result;
    }
};