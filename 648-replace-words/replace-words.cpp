class Solution{
public:
bool startsWith(const string &word, const string &prefix) {
    if (word.size() < prefix.size()) return false;
    return word.substr(0, prefix.size()) == prefix;
}

string replaceWords(vector<string>& dictionary, string sentence) {
    // Sort the dictionary by the length of the roots
    sort(dictionary.begin(), dictionary.end(), [](const string &a, const string &b) {
        return a.size() < b.size();
    });

    // Split the sentence into words
    istringstream iss(sentence);
    string word;
    vector<string> words;
    while (iss >> word) {
        words.push_back(word);
    }

    // Iterate over each word and replace it with the appropriate root if possible
    for (auto &word : words) {
        for (const auto &root : dictionary) {
            if (startsWith(word, root)) {
                word = root;
                break; // Once a root is found, no need to check further
            }
        }
    }

    // Join the words back into a sentence
    ostringstream oss;
    for (size_t i = 0; i < words.size(); ++i) {
        if (i != 0) oss << " ";
        oss << words[i];
    }

    return oss.str();
}
};