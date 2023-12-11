class Solution {
    int maxWidth;
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        vector<string> line;
        int i, available = maxWidth - words[0].size();
        line.push_back(words[0]);

        this->maxWidth = maxWidth;

        for (i = 1; i < words.size(); ++i) {
            if (words[i].size() + 1 > available) {
                ans.push_back(adjustLine(line, false));

                line.clear();
                line.push_back(words[i]);
                available = maxWidth - words[i].size();
            }
            else {
                line.push_back(words[i]);
                available -= words[i].size() + 1;
            }
        }

        ans.push_back(adjustLine(line, true));

        return ans;
    }

    string adjustLine(vector<string>& line, bool lastLine) {
        int space, i, total = 0, cnt = line.size();
        if (cnt == 1) {
            string spaceChar(maxWidth - line[0].size(), ' ');
            return line[0] + spaceChar;
        }

        for (i = 0; i < line.size(); ++i) total += line[i].size();
        int reminder, available = maxWidth - total;
        if (lastLine) {
            space = 1;
            reminder = 0;
        }
        else {
            space = available / (cnt - 1);
            reminder = available % (cnt - 1);
        }
        
        string spaceChar(space, ' ');
        string str = line[0];

        for (i = 1; i < line.size(); ++i) {
            str += spaceChar;
            if (reminder > 0) {
                str += " ";
                -- reminder;
            }
            str += line[i];
        }

        if (lastLine && maxWidth - str.size() > 0) {
            int need = maxWidth - str.size();
            string extraSpace(need, ' ');
            str += extraSpace;
        }

        return str;
    }
};