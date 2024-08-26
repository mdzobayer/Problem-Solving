class Solution {
    vector<string> abbreviations;
    string word;
public:
    vector<string> generateAbbreviations(string word) {
        this->word = word;

        StoreAbbreviation("", 0, 0);

        return abbreviations;
    }

    void StoreAbbreviation(string currWord, int index, int abbreviationCount) {
        if (index == word.size()) {
            currWord += abbreviationCount == 0 ? "" : to_string(abbreviationCount);

            abbreviations.push_back(currWord);
            return;
        }

        string abbreviationString = abbreviationCount == 0 ? "" : to_string(abbreviationCount);

        StoreAbbreviation(currWord + abbreviationString + word[index], index + 1, 0);
        StoreAbbreviation(currWord, index + 1, abbreviationCount + 1);
    }
};