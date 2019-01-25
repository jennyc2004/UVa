#include <bits/stdc++.h>
using namespace std;
const int maxn = 200 + 10;

char bin[256][5], line[maxn];
int H, W, pic[maxn][maxn], color[maxn][maxn];
vector<set<int> > neighbor;

const int dir_row[] = {-1, 1, 0, 0};
const int dir_col[] = {0, 0, -1, 1};

void dfs(int row, int col, int num) {
    color[row][col] = num;
    for(int i = 0; i < 4; i++) {
        int row2 = row + dir_row[i];
        int col2 = col + dir_col[i];
        if(row2 >= 0 && row2 < H && col2 >= 0 && col2 < W && pic[row2][col2] == pic[row][col] && color[row2][col2] == 0)
            dfs(row2, col2, num);
    }
}

void decode(char c, int row, int col) {
    for(int i = 0; i < 4; i++)
        pic[row][col+i] = bin[c][i] - '0';
}

void check_neighbor(int r, int c) {
    for(int i = 0; i < 4; i++) {
        int r2 = r + dir_row[i];
        int c2 = c + dir_row[i];
        if(r2 >= 0 && r2 < H && c2 >= 0 && c2 < W && pic[r2][c2] == 0 && color[r2][c2] != 1)
            neighbor[color[r][c]].insert(color[r2][c2]);
    }
}

const char *s = "WAKJSD";
char recognize(int num) {
    int c = neighbor[num].size();
    return s[c];
}

int main()
{
    strcpy(bin['0'], "0000");
    strcpy(bin['1'], "0001");
    strcpy(bin['2'], "0010");
    strcpy(bin['3'], "0011");
    strcpy(bin['4'], "0100");
    strcpy(bin['5'], "0101");
    strcpy(bin['6'], "0110");
    strcpy(bin['7'], "0111");
    strcpy(bin['8'], "1000");
    strcpy(bin['9'], "1001");
    strcpy(bin['a'], "1010");
    strcpy(bin['b'], "1011");
    strcpy(bin['c'], "1100");
    strcpy(bin['d'], "1101");
    strcpy(bin['e'], "1110");
    strcpy(bin['f'], "1111");

    int kase = 0;
    while(scanf("%d%d", &H, &W) == 2 && H && W) {
        memset(pic, 0, sizeof(pic));
        memset(color, 0, sizeof(color));

        for(int i = 0; i < H; i++) {
            scanf("%s", line);
            for(int j = 0; j < W ;j++)
                decode(line[j], i + 1, j * 4 + 1);
        }

        H += 5;
        W = W * 4 + 5;

        int cnt = 0;
        vector<int> vec;
        for(int i = 0; i < H; i++)
        for(int j = 0; j < W; j++) {
            if(!color[i][j]) {
                dfs(i, j, ++cnt);
                if(pic[i][j] == 1)  vec.push_back(cnt);
            }
        }

        neighbor.clear();
        neighbor.resize(cnt + 5);
        for(int i = 0; i < H; i++)
        for(int j = 0; j < W; j++)
            if(pic[i][j] == 1)  check_neighbor(i, j);

        vector<char> ans;
        for(int i = 0; i < vec.size(); i++)
            ans.push_back(recognize(vec[i]));

        sort(ans.begin(), ans.end());

        printf("Case %d: ", ++kase);
        for(int j = 0; j < ans.size(); j++)
            printf("%c", ans[j]);
        printf("\n");
    }
    return 0;
}
/*
Input
The input consists of several test cases, each of which describes an image containing one or more
hieroglyphs chosen from among those shown in Figure C.1. The image is given in the form of a series
of horizontal scan lines consisting of black pixels (represented by 1) and white pixels (represented by
0). In the input data, each scan line is encoded in hexadecimal notation. For example, the sequence of
eight pixels 10011100 (one black pixel, followed by two white pixels, and so on) would be represented in
hexadecimal notation as 9c. Only digits and lowercase letters a through f are used in the hexadecimal
encoding. The first line of each test case contains two integers, H and W. H (0 < H ≤ 200) is the
number of scan lines in the image. W (0 < W ≤ 50) is the number of hexadecimal characters in each
line. The next H lines contain the hexadecimal characters of the image, working from top to bottom.
Input images conform to the following rules:
• The image contains only hieroglyphs shown in Figure C.1.
• Each image contains at least one valid hieroglyph.
• Each black pixel in the image is part of a valid hieroglyph.
• Each hieroglyph consists of a connected set of black pixels and each black pixel has at least one
other black pixel on its top, bottom, left, or right side.
• The hieroglyphs do not touch and no hieroglyph is inside another hieroglyph.
• Two black pixels that touch diagonally will always have a common touching black pixel.
• The hieroglyphs may be distorted but each has a shape that is topologically equivalent to one of
the symbols in Figure C.1. (Two figures are topologically equivalent if each can be transformed
into the other by stretching without tearing.)
The last test case is followed by a line containing two zeros.
Output
For each test case, display its case number followed by a string containing one character for each
hieroglyph recognized in the image, using the following code:
Ankh: A
Wedjat: J
Djed: D
Scarab: S
Was: W
Akhet: K
In each output string, print the codes in alphabetic order. Follow the format of the sample output.
The sample input contains descriptions of test cases shown in Figures C.2 and C.3. Due to space
constraints not all of the sample input can be shown on this page.
Figure C.2: AKW Figure C.3: AAAAA
Sample Input
100 25
0000000000000000000000000
0000000000000000000000000
...(50 lines omitted)...
00001fe0000000000007c0000
00003fe0000000000007c0000
...(44 lines omitted)...
0000000000000000000000000
0000000000000000000000000
150 38
00000000000000000000000000000000000000
00000000000000000000000000000000000000
...(75 lines omitted)...
0000000003fffffffffffffffff00000000000
0000000003fffffffffffffffff00000000000
...(69 lines omitted)...
00000000000000000000000000000000000000
00000000000000000000000000000000000000
0 0
Sample Output
Case 1: AKW
Case 2: AAAAA
*/
