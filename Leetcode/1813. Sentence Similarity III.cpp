class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        istringstream iss1(sentence1), iss2(sentence2);
        deque<string> deque1((istream_iterator<string>(iss1)), istream_iterator<string>()), deque2((istream_iterator<string>(iss2)), istream_iterator<string>());

        while(!deque1.empty() && !deque2.empty() && deque1.front() == deque2.front()) {
            deque1.pop_front();
            deque2.pop_front();
        }

        while(!deque1.empty() && !deque2.empty() && deque1.back() == deque2.back()) {
            deque1.pop_back();
            deque2.pop_back();
        }

        return deque1.empty() || deque2.empty();
    }
};