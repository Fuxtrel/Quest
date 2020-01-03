#include "test.h"
#include <iostream>
#include <vector>


using namespace std;
void Ticket::inputQuestion(ofstream &fout){
    cout << "Введите текст вопроса №"<< number + 1 << "\n";
    getline(cin, question);
    fout << question << "\n";
}

void Ticket::inputAnswer(ofstream &fout){
    cout << "Введите текст ответа №1" << "\n";
    getline(cin, answer[0]);
    fout << "1) " << answer[0] << "\n";
    cout << "Введите текст ответа №2" << "\n";
    getline(cin, answer[1]);
    fout << "2) " << answer[1] << "\n";
    cout << "Введите текст ответа №3" << "\n";
    getline(cin, answer[2]);
    fout << "3) " << answer[2] << "\n";
}

void Ticket::addTicket(vector<Ticket> &questions, ofstream &fout) {
    while(stop_word == 1) {
        questions.push_back(*this);
        questions[this->number].inputQuestion(fout);
        questions[this->number].inputAnswer(fout);
        cout << "Введите номер правильного ответа \n";
        cin >> questions[this->number].answer_correct_number;
        fout << questions[this->number].answer_correct_number << "\n";
        cout << "Продолжим вводить билеты?|1|0|" << "\n";
        cin >> stop_word;
        cin.ignore (7777, '\n');
        this->number++;
    }
}

void runQuest(vector<Ticket> &questions, Person &person, Ticket &ticket, ifstream &fin){
    for(int i = 0; i < ticket.number; i++) {
        //Считали строки из файла
        getline(fin, questions[i].question);
        getline(fin, questions[i].answer[0]);
        getline(fin, questions[i].answer[1]);
        getline(fin, questions[i].answer[2]);
        string tmp;
        getline(fin, tmp);
        questions[i].answer_correct_number = atoi(tmp.c_str());
        //Вывели строки уже из массива объектов
        cout << questions[i].question << "\n";
        cout << questions[i].answer[0] << "\n";
        cout << questions[i].answer[1] << "\n";
        cout << questions[i].answer[2] << "\n";
        cout << "Введите ваш ответ (цифра)\n";
        cin >> person.answer;
        if (person.answer == questions[i].answer_correct_number) {
            person.score++;
        }
        cout << "Набрано " << person.score << "/" << ticket.number << "\n";
    }
    cout << "Количество правильных ответов: "<< person.score <<"\n";

}

