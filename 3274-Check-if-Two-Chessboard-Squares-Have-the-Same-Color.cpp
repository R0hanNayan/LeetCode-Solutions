class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        int c1 = coordinate1[0] - 'a' + 1;
        int r1 = coordinate1[1] - '0';
        int c2 = coordinate2[0] - 'a' + 1;
        int r2 = coordinate2[1] - '0';
    
        bool color1 = (c1 + r1) % 2 == 0;
        bool color2 = (c2 + r2) % 2 == 0;

        return color1 == color2;
    }
};