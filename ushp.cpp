#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <string> 
#include <ctime>
using namespace std;

list<string> division(string text) {
    list<string> all_words;
    vector <char> word;
    for (char symbol : text) {
        //cout << symbol;
        if ((symbol >= '0' && symbol <= '9') || (symbol >= 'А' && symbol <= 'я')) {
            word.push_back(symbol);
        }
        else if (!word.empty()) {
            string fword(word.begin(), word.end());
            //cout << fword<<" : ";
            all_words.push_back(fword);
            word.clear();
        }
    }
    return all_words;
}

vector <string> bubble(vector<string> &all_words) {
    for (unsigned int i = 0; i < all_words.size(); i++) {
        for (unsigned int j = 0; j < all_words.size() - 1; j++) {
            if (all_words[j][0] >= 'А' && all_words[j][0] <= 'Я') {
                all_words[j][0] = all_words[j][0] + ('а' - 'А');
            }
            if (all_words[j][0] > all_words[j + 1][0]) {
                string buff = all_words[j];
                all_words[j] = all_words[j + 1];
                all_words[j + 1] = buff;
            }
        }
    }
    return all_words;
}

void f_statistic(int *statistic, vector<string> &all_words, int k, int i) {
    if (all_words[k][i] >= '0' && all_words[k][0] <= '9') {
        statistic[int(all_words[k][i])] += 1;
    }
    else if (all_words[k][i] >= 'А' && all_words[k][i] <= 'Я') {
        statistic[10 + int(all_words[k][i] - 'А')] += 1;
    }
    else {
        statistic[10 + int(all_words[k][i] - 'а')] += 1;
    }
}

int main()
{
    setlocale(LC_ALL, "RUS");
    ifstream files("ish.txt");
    string ended;
    vector <string> all_words;
    int statistics[42];
    list <string> buf;
    while (getline(files, ended)) {
        buf = division(ended);
        int size = buf.size();
        while(size>0) {
            all_words.push_back(buf.front());
            buf.pop_front();
            size -= 1;
        }
    }
    cout << "Введенный текст: " << endl;
    for (int i = 0; i < all_words.size(); i++) {
        cout << all_words[i] << " ";
    }
    files.close();
    ofstream exit;
    exit.open("exit.txt");
    for (int s = 0; s < 42; s++) {
        statistics[s] = 0;
    }
    unsigned int start_time = clock();
    bubble(all_words);
    unsigned int end_time = clock();
    cout << endl << "Вариант 1: Кириллица, по алфавиту, по возрастанию, учитывать числа, сортировка пузырьком" << endl;
    cout << "Количество слов: " << all_words.size() << endl;
    cout << "Время сортировки: " << end_time - start_time << endl;
    exit << all_words[0];
    f_statistic(statistics, all_words, 0, 0);
    for (int k = 1; k < all_words.size(); k++) {
        if ((all_words[k - 1][0] == all_words[k][0]) || (all_words[k - 1][0] == all_words[k][0] + ('а' - 'А')) || (all_words[k - 1][0] == all_words[k][0] - ('а' - 'А'))) {
            exit << "  " << all_words[k];
            f_statistic(statistics, all_words, k, 0);
        }
        else {
            exit << endl << all_words[k];
            f_statistic(statistics, all_words, k, 0);
        }
    }
    exit.close();
    cout << endl << "statistics: " << endl;
    for (int q = 0; q < 42; q++) {
        if (q <= 9) {
            cout << q << ": " << statistics[q] << endl;
        }
        else {
            cout << char(q + 'а'-10) << ": " << statistics[q] << endl;
        }
    }
}