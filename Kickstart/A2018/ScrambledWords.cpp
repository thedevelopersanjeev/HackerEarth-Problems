
#include <bits/stdc++.h>

using namespace std;

namespace {

struct Key {
    char first, last;
    array<int, 26> freq;
};


bool operator== (const Key &a, const Key &b) {
    return a.first == b.first && a.last == b.last && a.freq == b.freq;
}

struct KeyHash {
    size_t operator()(const Key &k) const {
        size_t res = k.first + 31*k.last;
        for (int i : k.freq) res = 31*res + i;
        return res;
    }
};

Key MakeKey(const string &word) {
    Key key{word.front(), word.back(), {}};
    for (char ch : word) key.freq[ch - 'a']++;
    return key;
}

int Solve(const vector<string> &dictionary, const string &text) {
    unordered_map<Key, int, KeyHash> groups;
    unordered_set<int> word_lengths;
    for (const string &word : dictionary) {
        word_lengths.insert(word.size());
        groups[MakeKey(word)]++;
    }
    int answer = 0;
    for (int length : word_lengths) {
        if (length > text.size()) continue;
        Key key = {};
        int i = 0;
        for (; i < length - 1; ++i) {
            key.freq[text[i] - 'a']++;
        }
        for (; i < text.size(); ++i) {
            key.first = text[i - (length - 1)];
            key.last = text[i];
            key.freq[key.last - 'a']++;
            auto it = groups.find(key);
            if (it != groups.end()) {
                answer += it->second;
                groups.erase(it);
            }
            key.freq[key.first - 'a']--;
        }
    }
    return answer;
}

}  // namespace

int main() {
    int T = 0;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int L = 0;
        cin >> L;
        vector<string> dictionary(L);
        for (string &word : dictionary) cin >> word;
        char S1 = 0, S2 = 0;
        int N = 0, A = 0, B = 0, C = 0, D = 0;
        cin >> S1 >> S2 >> N >> A >> B >> C >> D;
        vector<int> X(N);
        X[0] = S1;
        X[1] = S2;
        for (int i = 2; i < N; ++i) X[i] = ((long long)A*X[i - 1] + (long long)B*X[i - 2] + C)%D;
        string S;
        S.resize(N);
        S[0] = S1;
        S[1] = S2;
        for (int i = 2; i < N; ++i) S[i] = char('a' + X[i]%26);
        cout << "Case #" << t << ": " << Solve(dictionary, S) << endl;
     }
}