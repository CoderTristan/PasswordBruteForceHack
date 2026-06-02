#include <iostream>
#include <string>
#include <vector>

bool brute(const std::string& target, const std::string& charset, std::string& out, int maxLen) {
    int n = charset.size();
    std::vector<int> idx(maxLen, 0);

    while (true) {
        std::string guess;
        for (int i = 0; i < maxLen; i++)
            guess += charset[idx[i]];

        std::cout << "Trying: " << guess << "\n";   // <-- PRINT EVERY CHOICE

        if (guess == target) {
            out = guess;
            return true;
        }

        int pos = maxLen - 1;
        while (pos >= 0) {
            idx[pos]++;
            if (idx[pos] < n) break;
            idx[pos] = 0;
            pos--;
        }

        if (pos < 0) return false;
    }
}


int main() {
    std::string target = "tg12345ab29";
    std::string charset = "abcdefghijklmnopqrstuvwxyz1234567890";
    std::string result;
    

    if (brute(target, charset, result, target.size())) {
        std::cout << "Found: " << result << "\n";
    } else {
        std::cout << "Not found\n";
    }
}
